#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5007;

int z[N];

bool is(string t, string s) {
    string kek = t + "#" + s;
    int l = 0, r = 0;
    int n = kek.size();
    kek += '$';
    z[0] = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0, min(r - i, z[i - l]));
        while (kek[z[i]] == kek[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    for (int i = (int)t.size(); i < n; ++i) {
        if (z[i] == (int)t.size()) return true;
    }
    return false;
}
                                                         
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector <int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a;
        int r = i;
        int l = -1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (is(s.substr(m, i - m), s.substr(0, m))) {
                r = m;
            }
            else l = m;
        }
        for (int j = r; j < i; ++j) dp[i] = min(dp[i], dp[j] + b);
    }
    cout << dp[n] << '\n';
}