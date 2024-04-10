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
        string s;
        cin >> s;
        vt<int> f;
        int cnt = 0;
        for (char c : s) {
            if (c == '1') cnt++;
            else if (cnt) {
                f.pb(cnt);
                cnt = 0;
            }
        }
        f.pb(cnt);
        sort(rall(f));
        int sco = 0;
        rep(i, sz(f)) if (~i & 1) sco += f[i];
        cout << sco << '\n';
    }
}