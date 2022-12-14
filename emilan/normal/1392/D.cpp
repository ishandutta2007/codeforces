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
        string s;
        cin >> n >> s;
        int cnt = count(all(s), 'L');
        if (cnt == 0 || cnt == n) cout << (n + 2) / 3 << '\n';
        else {
            int i = 0;
            while (s[(i + n - 1) % n] == s[i]) i = (i + n - 1) % n;
            int t = (i + n - 1) % n, d = 0, ans = 0;
            while (i != t) {
                if (s[i] == s[(i + 1) % n]) d++;
                else d = 0;
                if (d == 2) ans++, d = -1;
                i = (i + 1) % n;
            }

            cout << ans << '\n';
        }
    }
}