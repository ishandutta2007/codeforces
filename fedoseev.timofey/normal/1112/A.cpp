#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
                                                         
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    vector <int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    vector <int> c(k);
    for (int i = 0; i < k; ++i) cin >> c[i];
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int cr = c[i];
        --cr;
        for (int j = 0; j < n; ++j) {
            if (j == cr) continue;
            if (s[j] == s[cr] && p[j] > p[cr]) {
                ++ans;
                break;
            }
        }
    }
    cout << ans << '\n';
}