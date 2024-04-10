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

struct segtree {

    using node = int;

    node combine(node x, node y) {
        return min(x, y);
    }

    constexpr static node identity = inf;

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree() {}

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
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

    void set(int i, int x) {
        tree[i+n] = x;
        for (i = (i+n)/2; i > 0; i /= 2)
            tree[i] = min(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const int N = 1e5+5;
int a[N], p[N], v[N], vp[N], b[N];
int t = 1;
segtree s;

void ins(int i) {
    debug("ins", i);
    b[i] = 1;
    s.set(i+1, a[i]);
}

void rem(int i) {
    debug("rem", i);
    b[i] = 0;
    int m = s.query(0, i+1);
    debug(m, a[i]);
    if (m >= a[i]) v[a[i]] = 1;
    s.set(i+1, inf);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (*max_element(a, a+n) == 1)
        cout << "1\n", exit(0);
    fill(p, p+N, -1);
    vector<int> d(N, inf);
    s = segtree(d);
    for (int i = 0; i < n; i++) {
        if (p[a[i]] != -1) rem(p[a[i]]);
        vp[a[i]] = 1;
        while (vp[t]) t++;
        debug(t);
        s.set(0, t);
        v[t] = 1;
        ins(i), p[a[i]] = i;
    }
    debug(vector(v, v+20));
    for (int i = n-1; i >= 0; i--)
        if (b[i]) rem(i);
    for (int i = 1; i < N; i++)
        if (!v[i]) cout << i << "\n", exit(0);
}