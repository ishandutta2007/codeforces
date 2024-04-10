#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
 
using namespace std;
#define int long long
mt19937 rnd(time(NULL));

const int INF = 1e9 + 7;

struct Node {
    int x, y, val, mx;
    Node *l, *r;
};

Node *init(int x, int val) {
    Node *t = new Node;
    t->x = x;
    t->y = rnd();
    t->val = t->mx = val;
    t->l = t->r = NULL;
    return t;
}

int mx(Node *t) {
    if (!t) return -INF;
    else return t->mx;
}

void relax(Node *t) {
    t->mx = max(max(mx(t->l), mx(t->r)), t->val);
}

pair <Node*, Node*> split(Node *t, int x) {
    if (!t) return {NULL, NULL};

    if (t->x <= x) {
        auto tmp = split(t->r, x);
        t->r = tmp.first;
        relax(t);
        return {t, tmp.second};
    }
    else {
        auto tmp = split(t->l, x);
        t->l = tmp.second;
        relax(t);
        return {tmp.first, t};
    }
}

Node *merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;

    if (l->y < r->y) {
        l->r = merge(l->r, r);
        relax(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        relax(r);
        return r;
    }
}

Node *insert(Node *t, Node *elem) {
    auto tmp = split(t, elem->x);
    return merge(merge(tmp.first, elem), tmp.second);
}

const int MAXN = 1e5 + 7;
Node *dp[MAXN];

void add(int u, int v, int c) {
    auto tmp = split(dp[v], c);
    int best = mx(tmp.second);
    dp[v] = merge(tmp.first, tmp.second);
    dp[u] = insert(dp[u], init(c, best + 1));
}

struct Edge {
    int u, v, c;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAXN; ++i) {
        dp[i] = NULL;
        dp[i] = insert(dp[i], init(INF, 0));
    }

    int n, m;
    cin >> n >> m;

    vector <Edge> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].c;
        --e[i].u;
        --e[i].v;
    }

    reverse(e.begin(), e.end());

    for (int i = 0; i < m; ++i) {
        add(e[i].u, e[i].v, e[i].c);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, mx(dp[i]));
    }

    cout << ans << '\n';
    return 0;
}