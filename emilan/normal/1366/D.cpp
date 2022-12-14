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

    vi primes;
    for (int i = 2; i * i <= 10000000; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) primes.pb(i);
    }
    
    vvi p(n);
    rep(i, n) {
        int t = a[i];
        for (int j : primes) {
            if (t % j == 0) {
                while (t % j == 0) t /= j;
                p[i].pb(j);
            }
        }
        if (t != 1) p[i].pb(t);
    }

    rep(i, n) {
        if (sz(p[i]) < 2) cout << -1;
        else cout << p[i][0];
        cout << " \n"[i == n - 1];
    }

    rep(i, n) {
        if (sz(p[i]) < 2) cout << -1;
        else {
            int pro = 1;
            for (int j = 1; j < sz(p[i]); j++) pro *= p[i][j];
            cout << pro;
        }
        cout << " \n"[i == n - 1];
    }

    return 0;
}