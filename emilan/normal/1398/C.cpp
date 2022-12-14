#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vt<int> p(n + 1);
        map<int, int> f;
        rep(i, n) {
            p[i + 1] = p[i] + s[i] - '0' - 1;
            f[p[i + 1]]++;
        }

        ll cnt = 0;
        rep(i, n) {
            cnt += f[p[i]];
            f[p[i + 1]]--;
        }

        cout << cnt << '\n';
    }
}