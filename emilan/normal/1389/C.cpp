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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        string s;
        cin >> s;

        int mx = 0;
        rep(i, 10) mx = max(mx, count(all(s), char('0' + i)));
        
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 10; j++) {
                string t(s);
                rep(k, sz(t)) {
                    if (t[k] != '0' + i && t[k] != '0' + j) t[k] = '\0';
                }
                t.erase(remove_if(all(t), [](char c) {
                    return c == '\0';
                }), t.end());

                int mode = 0;
                string t1(t);
                rep(k, sz(t)) {
                    char c = (mode ? i : j) + '0';
                    if (t[k] == c) mode ^= 1;
                    else t[k] = '\0';
                }
                t.erase(remove_if(all(t), [](char c) {
                    return c == '\0';
                }), t.end());
                if (!t.empty() && t[0] == t.back()) t.pop_back();

                mode = 1;
                rep(k, sz(t1)) {
                    char c = (mode ? i : j) + '0';
                    if (t1[k] == c) mode ^= 1;
                    else t1[k] = '\0';
                }
                t1.erase(remove_if(all(t1), [](char c) {
                    return c == '\0';
                }), t1.end());
                if (!t.empty() && t1[0] == t1.back()) t1.pop_back();

                mx = max({mx, sz(t), sz(t1)});
            }
        }

        cout << sz(s) - mx << '\n';
    }

    return 0;
}