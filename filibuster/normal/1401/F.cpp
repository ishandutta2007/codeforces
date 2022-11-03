//#define _GLIB_CXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int K = 19;
const int N = (1 << K) + 13;


struct Node {
    int sz;
    li sum;
    bool rev;

    Node* lf;
    Node* rg;

    Node() {};
};

int a[N];
bool rev[K], swp[K];
int deg2[N];

void build(Node* v, int l, int r) {
    v->sz = r - l;
    v->rev = false;

    if(v->sz == 1) {
        v->sum = a[l];
        return;
    }

    int m = (l + r) / 2;
    v->lf = new Node();
    v->rg = new Node();

    build(v->lf, l, m);
    build(v->rg, m, r);

    v->sum = v->lf->sum + v->rg->sum;
}

void update(Node* v, int i, int x, bool rv) {
    if(v->sz == 1) {
        v->sum = x;
        return;
    }

    Node* lf = v->lf;
    Node* rg = v->rg;

    if(swp[deg2[v->sz]])
        swap(lf, rg);

    rv = rv ^ rev[deg2[v->sz]];

    if(rv)
        swap(lf, rg);

    if(i < v->sz / 2) {
        update(lf, i, x, rv);
    } else {
        update(rg, i - v->sz / 2, x, rv);
    }

    v->sum = lf->sum + rg->sum;
}

li get(Node* v, int l, int r, int ql, int qr, bool rv) {
    if(r <= ql || l >= qr)
        return 0;

    if(ql <= l && r <= qr)
        return v->sum;

    int m = (l + r) / 2;

    Node* lf = v->lf;
    Node* rg = v->rg;

    if(swp[deg2[v->sz]])
        swap(lf, rg);

    rv = rv ^ rev[deg2[v->sz]];

    if(rv)
        swap(lf, rg);

    return get(lf, l, m, ql, qr, rv) + get(rg, m, r, ql, qr, rv);
}

/*
0 5
1
4 1 1
1 1 2
4 1 1
2 0
4 1 1


*/

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < (1 << n); i++)
        cin >> a[i];

    for(int i = 0; i < K; i++) {
        deg2[1 << i] = i;
    }

    Node* root = new Node();
//cout << "sgf" << endl;
    build(root, 0, 1 << n);

//    cout << "sgf" << endl;

    for(int j = 0; j < q; j++) {
        int t;
        cin >> t;

        if(t == 1) {
            int i, x;
            cin >> i >> x;

            update(root, i - 1, x, false);
        } else if(t == 2) {
            int k;
            cin >> k;

            rev[k] ^= true;
        } else if(t == 3) {
            int k;
            cin >> k;

            swp[k + 1] ^= true;
        } else {
            int l, r;
            cin >> l >> r;

            cout << get(root, 0, (1 << n), l - 1, r, false) << endl;
        }
    }
}