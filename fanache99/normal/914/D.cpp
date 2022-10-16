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
#include <cassert>

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

const int MAXN = 500000;
const int MAXNODES = 1048576;

struct Interval {
    int left;
    int right;
    int node;
};

Interval nodes[1 + MAXN];
int v[1 + MAXN], m;
int tree[1 + MAXNODES];

int Gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        tree[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    tree[node] = Gcd(tree[2 * node], tree[2 * node + 1]);
}

void Update(int node, int left, int right, int where) {
    if (left == right) {
        tree[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle, where);
    else
        Update(2 * node + 1, middle + 1, right, where);
    tree[node] = Gcd(tree[2 * node], tree[2 * node + 1]);
}

void Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        m++;
        nodes[m] = {left, right, node};
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Query(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        Query(2 * node + 1, middle + 1, right, from ,to);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    BuildTree(1, 1, n);
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int type = Read();
        if (type == 1) {
            int a = Read(), b = Read(), x = Read();
            m = 0;
            Query(1, 1, n, a, b);
            int which = 0, bad = 0;
            for (int i = 1; i <= m; i++)
                if (tree[nodes[i].node] % x != 0) {
                    bad++;
                    which = i;
                }
            if (bad > 1) {
                printf("NO\n");
                continue;
            }
            int left = nodes[which].left, right = nodes[which].right, node = nodes[which].node;
            while (left != right) {
                if (tree[2 * node] % x != 0 && tree[2 * node + 1] % x != 0)
                    break;
                int middle = (left + right) / 2;
                if (tree[2 * node] % x != 0) {
                    right = middle;
                    node = 2 * node;
                }
                else {
                    left = middle + 1;
                    node = 2 * node + 1;
                }
            }
            if (left == right)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else {
            int x = Read(), y = Read();
            v[x] = y;
            Update(1, 1, n, x);
        }
    }
    return 0;
}