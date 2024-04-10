#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rnd(228);

int num(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    if ('A' <= c && c <= 'Z') return c - 'A' + 36;
    exit(1);
}

struct Node {
    char c;
    int cnt, mask, y;
    Node *l, *r;
    Node(char c_) {
        c = c_;
        mask = (1ll << num(c));
        cnt = 1;
        y = rnd();
        l = r = NULL;
    }
};  

int mask(Node *t) {
    if (!t) return 0;
    else return t->mask;
}

int cnt(Node *t) {
    if (!t) return 0;
    else return t->cnt;
}

void relax(Node *t) {
    t->mask = ((1ll << num(t->c)) | mask(t->l) | mask(t->r));
    t->cnt = 1 + cnt(t->l) + cnt(t->r);
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

int find(Node *t, char c) {
    if (!t) return -1;
    if (!((t->mask >> num(c)) & 1)) return -1;
    if (t->c == c) return cnt(t->l);
    if ((mask(t->l) >> num(c)) & 1) return find(t->l, c);
    else return find(t->r, c) + cnt(t->l) + 1; 
}   

int n, q;
string s;
void read() {
    cin >> n >> q;
    cin >> s;
}

Node *root = NULL;

void build() {
    for (int i = 0; i < n; ++i) {
        root = merge(root, new Node(s[i]));
    }   
}

void del(int l, int r, char c) {
    auto tmp1 = split(root, l);
    auto tmp2 = split(tmp1.second, r - l + 1);
    int pos = -1;
    while ((pos = find(tmp2.first, c)) != -1) {
        auto t1 = split(tmp2.first, pos);
        auto t2 = split(t1.second, 1);
        tmp2.first = merge(t1.first, t2.second);
    }
    root = merge(tmp1.first, merge(tmp2.first, tmp2.second));
}

void solve() {
    build();
    for (int i = 0; i < q; ++i) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        --l; --r;
        del(l, r, c);
    }   
}

void print(Node *t) {
    if (!t) return;
    print(t->l);
    cout << t->c;
    print(t->r);
}   

void print() {
    print(root);
    cout << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}