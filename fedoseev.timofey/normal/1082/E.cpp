#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Mx = 5e5 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, c;
    vector <int> a;
    cin >> n >> c;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    vector <int> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (a[i] == c);
    ans = pref[n];
    vector <vector <int>> w(Mx);
    for (int i = 0; i < n; ++i) w[a[i]].push_back(i);
    for (int i = 1; i < Mx; ++i) {
        if (i == c) continue;
        int cur = -2e9;
        for (int j = 0; j < w[i].size(); ++j) {
            cur = max(cur, pref[w[i][j]] - j);
            ans = max(ans, cur + pref[n] - pref[w[i][j] + 1] + j + 1);
        }
    }
    cout << ans << '\n';
}