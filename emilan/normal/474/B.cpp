#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi p(n);
    partial_sum(all(a), p.begin());

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        auto it = lower_bound(all(p), x);
        cout << distance(p.begin(), it) + 1 << '\n';
    }

    return 0;
}