#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

mt19937 rnd(228);

struct Node {
    int cnt;    
    int x, y;
    Node *l, *r;
    Node(int x_) {
        x = x_;
        y = rnd();
        cnt = 1;
        l = r = NULL;
    }
};

int cnt(Node *t) {
    if (!t) return 0;
    else return t->cnt;
}

void relax(Node *t) {
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
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

Node *insert(Node *t, int x) {
    auto tmp = split(t, x);
    return merge(merge(tmp.first, new Node(x)), tmp.second);
}

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int curr = 0;
    Node *root = NULL;
    root = insert(root, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        curr += a[i];
        //curr - t < x
        auto tmp = split(root, curr - t);
        ans += cnt(tmp.second);
        root = merge(tmp.first, tmp.second);
        root = insert(root, curr);
    }

    cout << ans << '\n';
    return 0;
}