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

const int MAXN = 50000;

struct Node {
    long long sum;
    long long lazy;
    Node *left, *right;

    Node() {
        sum = lazy = 0;
        left = right = NULL;
    }
};

vector<int> g[1 + MAXN], path[1 + MAXN];
int dad[1 + MAXN], candy[1 + MAXN], cost[1 + MAXN];
int weight[1 + MAXN], paths, which[1 + MAXN], where[1 + MAXN], start[1 + MAXN], offset[1 + MAXN], depth[1 + MAXN], up[1 + MAXN];

void Decompose(int node) {
    weight[node] = 1;
    int bestSon = 0;
    for (auto &son : g[node]) {
        depth[son] = depth[node] + 1;
        Decompose(son);
        weight[node] += weight[son];
        if (weight[son] > weight[bestSon])
            bestSon = son;
    }
    if (!bestSon) {
        paths++;
        which[node] = paths;
        path[paths].push_back(node);
        return;
    }
    which[node] = which[bestSon];
    path[which[node]].push_back(node);
}

inline bool Compare(const int &a, const int &b) {
    return depth[a] < depth[b];
}

map<pair<int, int>, Node*> root;

void Propagate(Node *node) {
    if (!node->left)
        node->left = new Node();
    node->left->lazy += node->lazy;
    if (!node->right)
        node->right = new Node();
    node->right->lazy += node->lazy;
    node->lazy = 0;
}

long long Get(Node *node, int left, int right) {
    return node->sum + node->lazy * (right - left + 1);
}

void Update(Node *node, int left, int right, int from, int to, int add) {
    if (from <= left && right <= to) {
        node->lazy += add;
        return;
    }
    Propagate(node);
    int middle = (left + right) / 2;
    if (from <= middle) {
        if (!node->left)
            node->left = new Node();
        Update(node->left, left, middle, from, to, add);
    }
    if (middle + 1 <= to) {
        if (!node->right)
            node->right = new Node();
        Update(node->right, middle + 1, right, from, to, add);
    }
    node->sum = 0;
    if (node->left)
        node->sum += Get(node->left, left, middle);
    if (node->right)
        node->sum += Get(node->right, middle + 1, right);
}

long long Query(Node *node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return Get(node, left, right);
    int middle = (left + right) / 2;
    long long answer = 0;
    Propagate(node);
    if (from <= middle && node->left)
        answer += Query(node->left, left, middle, from, to);
    if (middle + 1 <= to && node->right)
        answer += Query(node->right, middle + 1, right, from, to);
    node->sum = 0;
    if (node->left)
        node->sum += Get(node->left, left, middle);
    if (node->right)
        node->sum += Get(node->right, middle + 1, right);
    return answer;
}

void Add(int a, int b, int add, int id) {
    while (which[a] != which[b]) {
        if (!root[make_pair(id, which[a])])
            root[make_pair(id, which[a])] = new Node();
        Update(root[make_pair(id, which[a])], 1, path[which[a]].size(), 1, where[a], add);
        a = up[which[a]];
    }
    if (!root[make_pair(id, which[a])])
        root[make_pair(id, which[a])] = new Node();
    Update(root[make_pair(id, which[a])], 1, path[which[a]].size(), where[b], where[a], add);
}

long long GetSum(int a, int b, int id) {
    long long answer = 0;
    while (which[a] != which[b]) {
        if (!root[make_pair(id, which[a])])
            root[make_pair(id, which[a])] = new Node();
        answer += Query(root[make_pair(id, which[a])], 1, path[which[a]].size(), 1, where[a]);
        a = up[which[a]];
    }
    if (!root[make_pair(id, which[a])])
        root[make_pair(id, which[a])] = new Node();
    answer += Query(root[make_pair(id, which[a])], 1, path[which[a]].size(), where[b], where[a]);
    return answer;
}

long long square[1 + MAXN], sum[1 + MAXN];

void Modify(int node, int id, int add) {
    long long before = GetSum(node, 1, id);
    square[id] += 2 * before * add + depth[node];
    Add(node, 1, add, id);
    long long now = GetSum(node, 1, id);
    sum[id] += now - before;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, q, c;
    scanf("%d%d%d%d", &n, &m, &q, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &candy[i]);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &dad[i]);
        g[dad[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &cost[i]);
    depth[1] = 1;
    Decompose(1);
    for (int i = 1; i <= paths; i++) {
        sort(path[i].begin(), path[i].end(), Compare);
        for (int j = 0; j < path[i].size(); j++)
            where[path[i][j]] = j + 1;
        up[i] = dad[path[i][0]];
        offset[i] = offset[i - 1] + 4 * path[i].size();
    }
    for (int i = 1; i <= n; i++)
        Modify(i, candy[i], 1);
    for (int i = 1; i <= q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            Modify(a, candy[a], -1);
            candy[a] = b;
            Modify(a, candy[a], 1);
        }
        else {
            int x;
            scanf("%d", &x);
            long long answer = square[x] * cost[x] * cost[x] - 2 * sum[x] * cost[x] * c + 1LL * c * c * n;
            printf("%.12f\n", 1.0 * answer / n);
        }
    }
    return 0;
}