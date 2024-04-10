#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

const int N = 2e5+5;
const ll p = 54581, mod = 1e9+7;
ll ppow[N], pinv;

struct segtree {

    struct node {
        ll w, h;
        bool l, r;
    };

    node combine(node x, node y) {
        node z;
        if (y.w == 0) return node(x);
        if (x.w == 0) return node(y);
        z.w = x.r && y.l ? x.w+y.w-2 : x.w+y.w;
        z.l = x.w == 1 && x.r && y.l ? 0 : x.l;
        z.r = y.w == 1 && x.r && y.l ? 0 : y.r;
        ll l = x.r && y.l ? (x.h+2*mod-2*ppow[x.w-1])%mod : x.h;
        ll r = x.r && y.l ? ((y.h+mod-2)%mod*pinv)%mod : y.h;
        z.h = x.r && y.l ? (l+ppow[x.w-1]*r)%mod : (l+ppow[x.w]*r)%mod;
        return z;
    }

    constexpr static node identity = {0, 0, 0, 0};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(string& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = (v[i-n] == '1' ? node{1, 2, 1, 1} : node{1, 1, 0, 0});
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ppow[0] = 1;
    pinv = inv(p, mod);
    for (int i = 1; i < N; i++)
        ppow[i] = (ppow[i-1]*p)%mod;
    int n; cin >> n;
    string t; cin >> t;
    segtree s(t);
    int q; cin >> q;
    while (q--) {
        int x, y, len; cin >> x >> y >> len; x--, y--;
        auto l = s.query(x, x+len-1).h;
        auto r = s.query(y, y+len-1).h;
        debug(t.substr(x, len), t.substr(y, len));
        debug(l, r);
        cout << (l == r ? "Yes" : "No") << "\n";
    }
}

// 1110000111000
// 1000010001111

// 11110110101001100
// 11001010000111111