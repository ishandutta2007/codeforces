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

const int N = 1e5+5;
int a[N], b[N], c[N], d[N];
int ord[N], iord[N], cost[N], pre[N];

struct segtree {

    using node = int;

    node combine(node x, node y) {
        if (x == -1) return y;
        if (y == -1) return x;
        return b[x] < b[y] ? x : y;
    }

    vector<int> aa, bb;
    vector<node> tree;
    int n;

    segtree(vector<int> v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        aa.resize(2*n); bb.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                aa[i] = bb[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                } else {
                    tree[i] = -1;
                }
            } else {
                aa[i] = aa[2*i];
                bb[i] = bb[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void rem(int i) {
        tree[i+n] = -1;
        for (i = (i+n)/2; i > 0; i /= 2)
            tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        if (l <= aa[i] && r >= bb[i])
            return tree[i];
        if (l > bb[i] || r < aa[i])
            return -1;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    iota(ord, ord+n, 0);
    sort(ord, ord+n, [&](int i, int j){ return a[i] < a[j]; });
    for (int i = 0; i < n; i++)
        iord[ord[i]] = i;

    segtree s(vector(ord, ord+n));
    queue<int> bfs;
    for (int i = 0; i < n; i++)
        if (a[i] == 0 && b[i] == 0)
            bfs.push(i), s.rem(iord[i]), cost[i] = 1, pre[i] = -1;
    debug(vector(ord, ord+n));
    while (bfs.size()) {
        int i = bfs.front(); bfs.pop();
        int l = 0, r = n-1;
        while (l < r) {
            int m = (l+r+1)/2;
            if (a[ord[m]] <= c[i]) l = m;
            else r = m-1;
        }
        while (1) {
            int j = s.query(0, l);
            if (j == -1 || b[j] > d[i]) break;
            bfs.push(j), s.rem(iord[j]), cost[j] = cost[i]+1;
            pre[j] = i;
        }
    }
    if (cost[n-1] == 0) cout << "-1\n", exit(0);
    vector<int> stk;
    for (int i = n-1; i >= 0; i = pre[i])
        stk.pb(i);
    cout << cost[n-1] << "\n";
    for (int i = stk.size()-1; i >= 0; i--)
        cout << stk[i]+1 << " ";
    cout << "\n";
}