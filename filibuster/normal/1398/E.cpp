#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = 10;

/*
2 1 9
1 2 1
*/

mt19937 rnd(0);

struct Node {
    int x, y, sz;
    li sum;

    Node* lf;
    Node* rg;

    Node() {};

    Node(int x) : x(x), y(rnd()), sz(1), lf(nullptr), sum(x), rg(nullptr) {};
};

li gets(Node* a) {
    return (a ? a->sum : 0);
}

int getsz(Node* a) {
    return (a ? a->sz : 0);
}

Node* upd(Node* a) {
    if(!a)
        return a;

    a->sum = a->x + gets(a->lf) + gets(a->rg);
    a->sz = 1 + getsz(a->lf) + getsz(a->rg);

    return a;
}

pair<Node*, Node*> split(Node* a, int x) {
    if(!a)
        return {a, a};

    if(a->x < x) {
        auto p = split(a->rg, x);
        a->rg = p.f;
        return {upd(a), p.s};
    } else {
        auto p = split(a->lf, x);
        a->lf = p.s;
        return {p.f, upd(a)};
    }
}

pair<Node*, Node*> cut(Node* a, int k) {
    if(!a)
        return {a, a};

    if(getsz(a->lf) < k) {
        auto p = cut(a->rg, k - getsz(a->lf) - 1);
        a->rg = p.f;
        return {upd(a), p.s};
    } else {
        auto p = cut(a->lf, k);
        a->lf = p.s;
        return {p.f, upd(a)};
    }
}

Node* merge(Node* a, Node* b) {
    if(!a)
        return b;

    if(!b)
        return a;

    if(a->y > b->y) {
        a->rg = merge(a->rg, b);
        return upd(a);
    } else {
        b->lf = merge(a, b->lf);
        return upd(b);
    }
}

Node* insert(Node* root, int x) {
    Node* nw = new Node(x);

    auto p = split(root, x);
    return merge(merge(p.f, nw), p.s);
}

Node* erase(Node* root, int x) {
    auto p1 = split(root, x + 1);
    auto p2 = split(p1.f, x);

    return merge(p2.f, p1.s);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    li sum = 0;
    set<int> st1, st2;
    li s2 = 0;

    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;

        if(t == 0) {
            if(x < 0) {
                root = erase(root, -x);
                st1.erase(-x);
            } else {
                root = insert(root, x);
                st1.insert(x);
//                cout << "gf " << gets(root) <<endl;
            }
        } else {
            if(x < 0) {
                root = erase(root, -x);
                st2.erase(-x);
                s2 += x;
            } else {
                root = insert(root, x);
//                cout << "gf " << gets(root) <<endl;
                st2.insert(x);
                s2 += x;
            }
        }

        li res = gets(root);

        auto p = cut(root, st1.size());
        res += gets(p.s);
        root = merge(p.f, p.s);

        if(st1.empty()) {
            res -= *st2.begin();
        } else if(*st1.rbegin() < *st2.begin()){
            res -= *st2.begin();
            res += *st1.rbegin();
        }

        cout << res << endl;
    }
}