#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

vt<int> prefix_fun(string s) {
    int n = sz(s);
    vt<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[j] != s[i]) j = pi[j - 1];
        if (s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string s, t;
    cin >> s >> t;

    auto t_p = prefix_fun(t);
    map<int, int> p, p_next;
    p[0] = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '?') {
            for (auto it = p.rbegin(); it != p.rend(); it++) {
                int j = it->fi;
                if (j + 1 == sz(t)) p_next[t_p[j]] = it->se + 1;
                else {
                    auto &y = p_next[j + 1];
                    y = max(y, it->se);
                }

                if (j) {
                    auto &y = p[t_p[j - 1]];
                    y = max(y, it->se);
                }
            }
        } else {
            for (auto &x : p) {
                int j = x.fi;
                while (j && t[j] != s[i]) j = t_p[j - 1];
                if (t[j] == s[i]) j++;

                if (j == sz(t)) j = t_p[j - 1], x.se++;

                auto &y = p_next[j];
                y = max(y, x.se);
            }
        }

        p = p_next;
        p_next.clear();
    }

    int ans = 0;
    for (auto &x : p) ans = max(ans, x.se);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}