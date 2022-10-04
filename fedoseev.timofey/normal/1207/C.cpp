#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector <pair <int, int>> gr;
    gr.push_back({0, 0});
    for (int i = 0; i < n; ++i) {
        int c = s[i] - '0';
        if (gr.back().first == c) ++gr.back().second;
        else gr.push_back({c, 1});
    }
    ll ans = 0;
    for (int i = 0; i < (int)gr.size(); ++i) {
        if (i % 2 == 0) {
            if (i == 0 || i == (int)gr.size() - 1) ans += (ll)gr[i].second * b;
            else ans += ((ll)gr[i].second - 1) * b;
        } else {
            ans += ((ll)gr[i].second + 1) * 2 * b;
        }
    }
    ans += (ll)n * a;
    if ((int)gr.size() > 1) {
        ans += 2 * a;
    } else {
        ans += b;
    }
    for (int i = 2; i + 1 < (int)gr.size(); i += 2) {
        ans += min(2LL * a, ((ll)gr[i].second - 1) * b);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) solve();
}