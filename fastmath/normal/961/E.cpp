#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
#define int long long

const int MAXN = 2e5 + 7;

int a[MAXN];

struct Node {
    int sum;
    Node *l, *r;
};

Node *init() {
    Node *t = new Node;
    t->sum = 0;
    t->l = t->r = NULL;
    return t;
}

void push(Node *t) {
    if (!t->l) t->l = init();
    if (!t->r) t->r = init();
}

Node *upd(Node *t, int tl, int tr, int p, int x) {
    Node *nt = init();
    if (tl == tr) {
        nt->sum = t->sum + x;
        return nt;
    }

    int tm = (tl + tr) / 2;
    push(t);
    if (p <= tm) {
        nt->l = upd(t->l, tl, tm, p, x);
        nt->r = t->r;
    }
    else {
        nt->l = t->l;
        nt->r = upd(t->r, tm + 1, tr, p, x);
    }

    nt->sum = nt->l->sum + nt->r->sum;
    return nt;
}

int get(Node *t, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return t->sum;
    int tm = (tl + tr) / 2;
    push(t);
    return get(t->l, tl, tm, l, r) + get(t->r, tm + 1, tr, l, r);
}

Node *tree[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        a[i] = min(a[i], MAXN);
    }

    tree[0] = init();
    for (int i = 0; i < n; ++i) {
        tree[i + 1] = tree[i];
        tree[i + 1] = upd(tree[i + 1], 0, MAXN, a[i], 1);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += get(tree[min(i, a[i])], 0, MAXN, i + 1, MAXN);
    }
    
    cout << ans << '\n';
    return 0;
}