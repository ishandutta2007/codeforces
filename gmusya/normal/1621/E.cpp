#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

const ll INF = 1e9;

struct SegmentTree {
    ll n;
    vector<ll> t;

    explicit SegmentTree(ll size) {
        n = size;
        t.resize(n << 2);
    }

    void Build(ll v, ll tl, ll tr, vector<ll>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) / 2;
        Build(v * 2, tl, tm, a);
        Build(v * 2 + 1, tm + 1, tr, a);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    ll Get(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) {
            return INF;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        ll x = Get(v * 2, tl, tm, l, min(r, tm));
        ll y = Get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return min(x, y);
    }

    void Build(vector<ll>& a) {
        Build(1, 0, n - 1, a);
    }

    ll Get(ll l, ll r) {
        return Get(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        n = m;
        a.resize(n);
        reverse(a.begin(), a.end());
        vector<vector<ll>> b(m);
        vector<ll> sum(m);
        vector<ll> sz(m);
        for (ll i = 0; i < m; ++i) {
            ll k;
            cin >> k;
            sz[i] = k;
            b[i].resize(k);
            for (ll j = 0; j < k; ++j) {
                cin >> b[i][j];
                sum[i] += b[i][j];
            }
        }
        vector<ll> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](ll i, ll j) {
            return sum[i] * sz[j] < sum[j] * sz[i];
        });
        vector<ll> can(n, -1);
        for (ll i = 0; i < n; ++i) {
            if (a[0] * sz[p[i]] >= sum[p[i]]) {
                can[0] = i;
            }
        }
        for (ll i = 1; i < n; ++i) {
            can[i] = can[i - 1];
            for (ll j = can[i - 1] + 1; j < n; ++j) {
                if (a[i] * sz[p[j]] >= sum[p[j]]) {
                    can[i] = j;
                } else {
                    break;
                }
            }
        }
        vector<ll> mi(n);
        for (ll i = 0; i < n; ++i) {
            mi[i] = can[i] - i;
        }
        SegmentTree segment_tree(n);
        segment_tree.Build(mi);
        vector<vector<ll>> ans(m);
        for (ll i = 0; i < m; ++i) {
            ans[i].resize(sz[i]);
        }
        for (ll i = 0; i < m; ++i) {
            ll ind = p[i];
            for (ll j = 0; j < sz[ind]; ++j) {
                ll val = b[ind][j];
                ll new_sum = sum[ind] - val;
                ll new_sz = sz[ind] - 1;
                if (a[n - 1] * new_sz < new_sum) {
                    continue;
                }
                ll L = 0, R = n - 1;
                while (L != R) {
                    ll M = (L + R) / 2;
                    if (a[M] * new_sz >= new_sum) {
                        R = M;
                    } else {
                        L = M + 1;
                    }
                }
                if (L >= i) {
                    ll res1 = segment_tree.Get(0, i - 1);
                    ll res2 = segment_tree.Get(L + 1, n - 1);
                    ll res3 = segment_tree.Get(i, L - 1);
                    if (res1 >= 0 && res2 >= 0 && res3 >= 1) {
                        ans[ind][j] = 1;
                    } else {
                        ans[ind][j] = 0;
                    }
                } else {
                    ll res1 = segment_tree.Get(0, L - 1);
                    ll res2 = segment_tree.Get(i + 1, n - 1);
                    ll res3 = segment_tree.Get(L + 1, i);
                    if (res1 >= 0 && res2 >= 0 && res3 >= -1) {
                        ans[ind][j] = 1;
                    } else {
                        ans[ind][j] = 0;
                    }
                }
            }
        }
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < sz[i]; ++j) {
                cout << ans[i][j];
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
1
5 5
2 3 4 5 5
2
5 5
2
5 2
3
4 2 3
4
5 2 3 4
5
1 2 3 4 5
 */