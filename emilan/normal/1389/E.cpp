#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int m, d, w;
        cin >> m >> d >> w;
        int p = w / __gcd(d - 1, w), t = min(m, d) - 1;
        cout << t / p * (t % p + t - p + 2ll) / 2 << '\n';
    }
}