#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

const int K = 62;

vector <int> who[K];

map <ll, int> cnt;
map <ll, bool> ok;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <ll> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        who[__builtin_popcountll(a[i])].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll ans = 0;
    int cntn = 0;
    vector <ll> ok;
    for (int i = K - 1; i >= 0; --i) {
        for (int j : who[i]) {
            bool fl = false;
            if (cnt[a[j]] >= 2) {
                fl = true;
            }
            for (ll x : ok) {
                if ((x & a[j]) == a[j]) {
                    fl = true;
                }
            }
            if (fl) {
                ok.push_back(a[j]);
                ans += b[j];
                ++cntn;
            }
        }
    }
    if (cntn >= 2) cout << ans << '\n';
    else cout << "0\n";
}