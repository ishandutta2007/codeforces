#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

mt19937 rnd(228);
struct Node {
    int x, mx, sz, y, cnt;
    Node *l, *r;
    Node(int x_, int sz_) {
        x = x_; mx = sz = sz_;
        y = rnd();
        cnt = 1;
        l = r = NULL;
    }   
};

int cnt(Node *t) {
    if (!t) return 0;
    else return t->cnt;
}

int mx(Node *t) {
    if (!t) return -1;
    else return t->mx;
}

void relax(Node *t) {
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
    t->mx = max(t->sz, max(mx(t->l), mx(t->r)));
}

pair <Node*, Node*> split(Node *t, int k) {
    if (!t) return {NULL, NULL};
    if (k <= cnt(t->l)) {
        auto tmp = split(t->l, k);
        t->l = tmp.second;
        relax(t);
        return {tmp.first, t};
    }
    else {
        auto tmp = split(t->r, k - cnt(t->l) - 1);
        t->r = tmp.first;
        relax(t);
        return {t, tmp.second};
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

Node* insert(Node *t, int x) {
    auto tmp = split(t, cnt(t) - 1);
    if (tmp.second && tmp.second->x == x) {
        tmp.second->sz++;
        relax(tmp.second);
    }   
    else {
        tmp.second = merge(tmp.second, new Node(x, 1));
    }   
    return merge(tmp.first, tmp.second);
}

Node* insert(Node *t, Node *e) {
    auto tmp = split(t, cnt(t) - 1);
    if (tmp.second && tmp.second->x == e->x) {
        tmp.second->sz += e->sz;
        relax(tmp.second);
    }   
    else {
        tmp.second = merge(tmp.second, e);
    }   
    return merge(tmp.first, tmp.second);
}

int find(Node *t) {
    if (!t) {
        cout << "KEK\n";
        exit(0);
    }   
    if (mx(t->l) == t->mx) {
        return find(t->l);
    }
    else if (t->sz == t->mx) {
        return cnt(t->l);
    }
    else {
        return cnt(t->l) + 1 + find(t->r);
    }
}

Node *root = NULL;

void build() {
    for (int i = 0; i < n; ++i) {
        root = insert(root, a[i]);
    }   
}

void del() {
    int num = find(root);
    auto tmp1 = split(root, num);
    auto tmp2 = split(tmp1.second, 1);
    if (!tmp2.second) {
        root = tmp1.first;
    }
    else {
        auto tmp3 = split(tmp2.second, 1);
        tmp1.first = insert(tmp1.first, tmp3.first);
        root = merge(tmp1.first, tmp3.second);
    }   
}   

int ans = 0;
void solve() {
    build();
    while (root) {
        ++ans;
        del();
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    read();
    solve();
    print();

    return 0;
}