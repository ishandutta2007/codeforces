#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    // runs in O(nlogn).
    rmq(vector<T>& data) {
        int n = data.size();
        int log2n = ceil(log2(n));
        tree.assign(log2n+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= log2n; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = max(tree[i-1][j], tree[i-1][j+(1<<i-1)]);
    }

    // returns the minimum of the array on the interval [a..b] in O(1) time.
    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return max(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};

const int N = 2e5+5;
vector<array<ll, 3>> t, p, q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    t.resize(n);
    for (int i = 0; i < n; i++)
        cin >> t[i][0] >> t[i][1], t[i][2] = i;
    sort(all(t));
    for (auto& [u, v, i] : t) {
        while (!p.empty() && p.back()[0] == u)
            p.pop_back(), q.pop_back();
        if (p.empty() || p.back()[1] < v)
            p.pb({u, v, i}), q.pb({v, u, i});
    }
    vector<pair<ll, int>> s;
    for (auto& [u, v, i] : p) s.pb({v-u, i});
    rmq rm(s);
    array<ll, 3> ans = {0, 0, 0};
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        int l = lower_bound(all(p), array<ll, 3>{a, -inf_ll, -inf_ll})-p.begin();
        int r = upper_bound(all(q), array<ll, 3>{b, inf_ll, inf_ll})-q.begin()-1;
        debug(l, r);
        if (l <= r) {
            auto res = rm.query(l, r);
            ans = max(ans, {c*res.first, res.second, i});
        }
        if (l > 0)
            ans = max(ans, {c*(min(b, p[l-1][1])-a), p[l-1][2], i});
        if (r < (int)p.size()-1)
            ans = max(ans, {c*(b-max(a, p[r+1][0])), p[r+1][2], i});
    }
    cout << ans[0] << "\n";
    if (ans[0] > 0) {
        cout << ans[1]+1 << " " << ans[2]+1 << "\n";
    }
}