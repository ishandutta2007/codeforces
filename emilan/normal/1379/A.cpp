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

    string f("abacaba");

    int tcs;
    cin >> tcs;
    rep(tc, tcs) {
        int n;
        string s;
        cin >> n >> s;
        
        int cnt = 0;
        for (int i = 0; i < n - 6; i++) {
            if (s.substr(i, 7) == f) cnt++;
        }

        if (cnt > 1) cout << "no\n";
        else if (cnt == 1) {
            replace(all(s), '?', 'd');
            cout << "yes\n" << s << '\n';
        } else {
            int r = 0;
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (s[i] == f[r] || s[i] == '?') r++;
                else i -= r, r = 0;

                if (r == 7) {
                    string s2(s);
                    for (int j = 0; j < 7; j++) s2[i - 6 + j] = f[j];

                    cnt = 0;
                    for (int i = 0; i < n - 6; i++) {
                        if (s2.substr(i, 7) == f) cnt++;
                    }

                    if (cnt == 1) {
                        replace(all(s2), '?', 'd');
                        cout << "yes\n" << s2 << '\n';
                        ok = true;
                        break;
                    } else r = 0, i -= 6;
                }
            }

            if (!ok) cout << "no\n";
        }
    }

    return 0;
}