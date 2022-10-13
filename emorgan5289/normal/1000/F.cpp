#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    struct node {
        vector<array<int, 3>> s;
        vector<pair<int, int>> m;
    };

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<array<int, 3>>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i].s.pb(v[i-n]);
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                merge(all(tree[2*i].s), all(tree[2*i+1].s), back_inserter(tree[i].s));
            }
            tree[i].m.resize(tree[i].s.size());
            for (int j = 0; j < tree[i].s.size(); j++)
                tree[i].m[j] = max(j == 0 ? pair(-inf, -inf) : tree[i].m[j-1], pair(tree[i].s[j][1], tree[i].s[j][2]));
        }
    }

    int get(int i, int x, int y) {
        int j = upper_bound(all(tree[i].s), array<int, 3>{x, inf, inf})-tree[i].s.begin()-1;
        if (j < 0 || tree[i].m.size() == 0) return -1;
        return tree[i].m[j].first >= y ? tree[i].m[j].second : -1;
    }

    int query(int l, int r, int x, int y, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return get(i, x, y);
        if (l > b[i] || r < a[i])
            return -1;
        return max(query(l, r, x, y, 2*i), query(l, r, x, y, 2*i+1));
    }
};

const int N = 500005;
int p[N];
vector<array<int, 3>> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    fill(p, p+N, -1);
    v.assign(n, {-1, -1, -1});
    for (int i = 0; i < n; i++) {
        cin >> v[i][2];
        if (p[v[i][2]] == -1)
            v[i][0] = 0;
        else {
            v[p[v[i][2]]][1] = i-1;
            v[i][0] = p[v[i][2]]+1;
        }
        p[v[i][2]] = i;
    }
    for (int i = 0; i < n; i++)
        if (v[i][1] == -1)
            v[i][1] = n-1;
    segtree s(v);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--, y--;
        int r = s.query(x, y, x, y);
        cout << (r == -1 ? 0 : r) << "\n";
    }
}