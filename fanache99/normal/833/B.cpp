//#include <iostream>
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

const int MAXN = 35000;
const int INF = 1000000000;

int tree[1 + 4 * MAXN], lazy[1 + 4 * MAXN];
int v[1 + MAXN], dp[2][1 + MAXN], last[1 + MAXN];

void BuildTree(int node, int left, int right, int which) {
    if (left == right) {
        tree[node] = dp[which][left - 1];
        lazy[node] = 0;
        last[left] = 0;
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle, which);
    BuildTree(2 * node + 1, middle + 1, right, which);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    lazy[node] = 0;
}

void Propagate(int node) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void Update(int node, int left, int right, int from, int to, int add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        return;
    }
    Propagate(node);
    int middle = (left + right) / 2;
    if (from <= middle)
        Update(2 * node, left, middle, from, to, add);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right, from, to, add);
    tree[node] = max(tree[2 * node] + lazy[2 * node], tree[2 * node + 1] + lazy[2 * node + 1]);
}

int Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return tree[node] + lazy[node];
    Propagate(node);
    int middle = (left + right) / 2, answer = -INF;
    if (from <= middle)
        answer = max(answer, Query(2 * node, left, middle, from, to));
    if (middle + 1 <= to)
        answer = max(answer, Query(2 * node + 1, middle + 1, right, from, to));
    tree[node] = max(tree[2 * node] + lazy[2 * node], tree[2 * node + 1] + lazy[2 * node + 1]);
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    int now = 0, before = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        dp[now][i] = -INF;
    }
    for (int i = 1; i <= k; i++) {
        swap(now, before);
        BuildTree(1, 1, n, before);
        for (int j = 0; j <= n; j++) {
            dp[now][j] = -INF;
            if (j < i)
                continue;
            Update(1, 1, n, last[v[j]] + 1, j, 1);
            last[v[j]] = j;
            dp[now][j] = Query(1, 1, n, 1, j);
        }
    }
    printf("%d\n", dp[now][n]);
    return 0;
}