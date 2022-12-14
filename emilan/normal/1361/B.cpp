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

const int mod = 1e9 + 7;

ll modExp(ll b, int e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e /= 2;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, p;
        cin >> n >> p;
        vi a(n);
        for (int& i : a) cin >> i;

        if (p == 1) {
            cout << (n & 1) << '\n';
            continue;
        }

        sort(rall(a));
        a.pb(-1);
        
        ll ans = 0, diff = 0;
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == a[i]) cnt++;
            else {
                if (diff == 0) {
                    if (cnt & 1) {
                        diff = 1;
                        ans = (ans + modExp(p, a[i - 1])) % mod;
                    }
                } else {
                    while (cnt > diff) cnt -= 2;
                    diff -= cnt;
                    ans = ((ans - cnt * modExp(p, a[i - 1])) % mod +
                           mod) % mod;
                }

                if (diff && diff < 1 << 20) {
                    if (log10(p) * (a[i - 1] - a[i]) > 6) diff = 1 << 20;
                    else diff *= modExp(p, a[i - 1] - a[i]);
                }
                cnt = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}