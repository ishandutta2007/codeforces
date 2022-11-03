#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 4e7;
const int MX = 2e5 + 13;

struct Node {
    li a, b;
    Node* lf;
    Node* rg;

    Node() {};

    Node(li a, li b) : a(a), b(b) {};
};

int cur = 0;
Node buf[M];

Node* newNode(li a, li b) {
//    cout << "new " << endl;
//    if(cur == M) {
//        exit(0);
//    }
    buf[cur].a = a;
    buf[cur].b = b;
    buf[cur].lf = buf[cur].rg = nullptr;
    return &buf[cur++];
}

Node* newNode(li a, li b, Node* lf, Node* rg) {
//    cout << "new " << endl;
//    if(cur == M) {
//        exit(0);
//    }
    buf[cur].a = a;
    buf[cur].b = b;
    buf[cur].lf = lf;
    buf[cur].rg = rg;
    return &buf[cur++];
}

Node* merge(Node* lf, Node* rg) {
//    cout << "1 merge" << endl;
    Node* res = newNode(0ll, 0ll);
//    cout << "2 merge" << endl;
    res->lf = lf;
    res->rg = rg;
//    cout << "3 merge" << endl;
    return res;
}

Node* build(int l, int r) {
    if(r - l == 1) {
        return newNode(0, 0);
    }

    int m = (l + r) / 2;

    return merge(build(l, m), build(m, r));
}

Node* update(Node* v, int l, int r, int ql, int qr, li da, li db) {
    if(l >= qr || r <= ql)
        return v;

    Node* res = newNode(v->a, v->b, v->lf, v->rg);

    if(ql <= l && r <= qr) {

        res->a += da;
        res->b += db;
        return res;
    }

    int m = (l + r) / 2;

    res->lf = update(res->lf, l, m, ql, qr, da, db);
    res->rg = update(res->rg, m, r, ql, qr, da, db);

    return res;
}

pair<li, li> get(Node* v, int l, int r, int i) {
//    pair<li, li> res = {v->a, v->b};

    if(r - l == 1)
        return {v->a, v->b};

    int m = (l + r) / 2;

    pair<li, li> p = (i < m ? get(v->lf, l, m, i) : get(v->rg, m, r, i));

    return {v->a + p.f, v->b + p.s};
}

struct Func {
    int l, r, y1, a, b, y2;

    Func() {};
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Func> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].y1 >> a[i].a >> a[i].b >> a[i].y2;

        a[i].l++;
        a[i].r++;
    }

    vector<Node*> root;
    root.push_back(build(0, MX));

    for(int i = 0; i < n; i++) {
        root.push_back(root[i]);
        root[i + 1] = update(root[i + 1], 0, MX, 0, a[i].l, 0, a[i].y1);
        root[i + 1] = update(root[i + 1], 0, MX, a[i].l, a[i].r, a[i].a, a[i].b);
        root[i + 1] = update(root[i + 1], 0, MX, a[i].r, MX, 0, a[i].y2);
    }

    int q;
    cin >> q;

    li lst = 0;
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;

        l--;
        x = (x + lst) % (1000000000);

        pair<li, li> res1 = get(root[l], 0, MX, min(x, MX - 1));
        pair<li, li> res2 = get(root[r], 0, MX, min(x, MX - 1));

        pair<li, li> res = {res2.f - res1.f, res2.s - res1.s};

        lst = x * 1ll * res.f + res.s;

        cout << lst << '\n';
    }
}