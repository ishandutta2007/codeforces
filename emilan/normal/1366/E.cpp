#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

#define die return cout << 0, 0

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    
    map<int, int> pos;
    rep(i, n) pos[a[i]] = i;

    if (pos.begin()->fi != b[0]) die;
    vi bpos(m);
    rep(i, m) {
        if (!pos.count(b[i])) die;
        bpos[i] = pos[b[i]];
        if (i && bpos[i - 1] > bpos[i]) die;
    }

    ll ans = 1;
    for (int i = 1; i < m; i++) {
        int take = bpos[i - 1] + 1;
        for (int j = take; j < bpos[i]; j++) {
            if (a[j] < b[i - 1]) die;
            if (a[j] < b[i]) take = j + 1;
        }

        ans = ans * (bpos[i] - take + 1) % mod;
    }

    for (int i = bpos.back() + 1; i < n; i++) {
        if (a[i] < b.back()) die;
    }

    cout << ans;

    return 0;
}