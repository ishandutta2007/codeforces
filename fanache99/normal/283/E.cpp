#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 100000;
const int MAXNODES = 262144;

int tree[1 + MAXNODES], lazy[1 + MAXNODES], s[1 + MAXN];

struct Event {
    int where;
    int from;
    int to;

    bool operator < (const Event &other) const {
        return where < other.where;
    }
};

Event v[1 + 2 * MAXN];

void Propagate(int node, int left, int right) {
    if (!lazy[node])
        return;
    int middle = (left + right) / 2;
    lazy[2 * node] ^= lazy[node];
    tree[2 * node] = (middle - left + 1) - tree[2 * node];
    lazy[2 * node + 1] ^= lazy[node];
    tree[2 * node + 1] = (right - middle) - tree[2 * node + 1];
    lazy[node] = 0;
}

void Update(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        tree[node] = (right - left + 1) - tree[node];
        lazy[node] ^= 1;
        return;
    }
    int middle = (left + right) / 2;
    Propagate(node, left, right);
    if (from <= middle)
        Update(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right, from, to);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int Query(int node, int left, int right, int from, int to) {
    if (from > to)
        return 0;
    if (from <= left && right <= to)
        return tree[node];
    int middle = (left + right) / 2, answer = 0;
    Propagate(node, left, right);
    if (from <= middle)
        answer += Query(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        answer += Query(2 * node + 1, middle + 1, right, from, to);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return answer;
}

int BinarySearch(int n, int x) {
    int left = 1, right = n, answer = n + 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (s[middle] >= x) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, q = 0;
    scanf("%d%d", &n, &m);
    long long answer = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++)
        scanf("%d", &s[i]);
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = BinarySearch(n, a);
        b = BinarySearch(n, b + 1) - 1;
        if (b == 0 || a == n + 1 || a > b)
            continue;
        q++;
        v[q] = {a, a, b};
        q++;
        v[q] = {b + 1, a, b};
    }
    sort(v + 1, v + q + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= q && v[j].where == i) {
            Update(1, 1, n, v[j].from, v[j].to);
            j++;
        }
        int x = (i - 1) - Query(1, 1, n, 1, i - 1) + Query(1, 1, n, i + 1, n);
        answer -= 1LL * x * (x - 1) / 2;
    }
    printf("%I64d\n", answer);
    return 0;
}