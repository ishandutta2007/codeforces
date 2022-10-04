#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

const int N = 1e5 + 7;

int dp[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i] += dp[i - 1];
        dp[i] += dp[i - 2];
        dp[i] %= md;
    }
    string s;
    cin >> s;
    int n = s.size();
    vector <pair <char, int>> cnt;
    cnt.push_back({s[0], 1});
    for (int i = 1; i < n; ++i) {
        if (s[i] == cnt.back().first) ++cnt.back().second;
        else {
            cnt.push_back({s[i], 1});
        }
    }
    int ans = 1;
    for (auto p : cnt) {
        if (p.first == 'n' || p.first == 'u') {
            ans = ((ll)ans * dp[p.second]) % md;
        }
        if (p.first == 'w') ans = 0;
        if (p.first == 'm') ans = 0;
    }
    cout << ans << '\n';
}