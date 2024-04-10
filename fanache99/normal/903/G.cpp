#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

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

const int MAXN = 200000;
const long long INF = 1000000000000000000LL;
const int MAXNODES = 524288;
long long a[1 + MAXN], b[1 + MAXN];
vector<pair<int, long long> > g[1 + MAXN];
long long sum[1 + MAXN];
long long tree[1 + MAXNODES], lazy[1 + MAXNODES];
multiset<long long> limit;

void BuildTree(int node, int left, int right) {
    if (left == right) {
        tree[node] = b[left];
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void Propagate(int node) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

long long Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return tree[node] - lazy[node];
    Propagate(node);
    int middle = (left + right) / 2;
    long long answer = INF;
    if (from <= middle)
        answer = min(answer, Query(2 * node, left, middle, from, to));
    if (middle + 1 <= to)
        answer = min(answer, Query(2 * node + 1, middle + 1, right, from, to));
    tree[node] = min(tree[2 * node] - lazy[2 * node], tree[2 * node + 1] - lazy[2 * node + 1]);
    return answer;
}

void Update(int node, int left, int right, int from, int to, long long add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        return;
    }
    Propagate(node);
    int middle = (left + right) / 2, answer = INF;
    if (from <= middle)
        Update(2 * node, left, middle, from, to, add);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right, from, to, add);
    tree[node] = min(tree[2 * node] - lazy[2 * node], tree[2 * node + 1] - lazy[2 * node + 1]);
}

void Precompute(int n) {
    BuildTree(1, 1, n);
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        long long now = 0;
        for (auto &it : g[i]) {
            long long add = min(Query(1, 1, n, it.first, n), it.second);
            now += add;
            Update(1, 1, n, it.first, n, add);
        }
        sum[i] = sum[i - 1] + now;
    }
    for (int i = 1; i <= n; i++)
        limit.insert(sum[i] + a[i]);
}

void Change(int x, int y) {
    limit.erase(limit.find(sum[x] + a[x]));
    a[x] = y;
    limit.insert(sum[x] + a[x]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), q = Read();
    for (int i = 1; i < n; i++) {
        int x = Read(), y = Read();
        a[i] = x;
        b[i] = y;
    }
    b[n] = INF;
    for (int i = 1; i <= m; i++) {
        int x = Read(), y = Read(), z = Read();
        g[x].push_back(make_pair(y, z));
    }
    Precompute(n);
    printf("%I64d\n", *(limit.begin()));
    for (int i = 1; i <= q; i++) {
        int x = Read(), y = Read();
        Change(x, y);
        printf("%I64d\n", *(limit.begin()));
    }
    return 0;
}