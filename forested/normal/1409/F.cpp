// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n, k_;
    cin >> n >> k_;
    string s, t;
    cin >> s >> t;
    
    if (t[0] == t[1]) {
        rep(i, n) {
            if (s[i] == t[0]) continue;
            if (k_) {
                s[i] = t[0];
                --k_;
            }
        }
        int ans = 0, cnt = 0;
        rep(i, n) {
            if (s[i] == t[0]) {
                ans += cnt;
                ++cnt;
            }
        }
        cout << ans << "\n";
        return 0;
    }
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k_ + 1, vector<int>(n + 1, -inf)));
    dp[0][0][0] = 0;
    rep(i, n) rep(j, k_ + 1) rep(k, n + 1) {
        if (dp[i][j][k] == -inf) continue;
        chmax(dp[i + 1][j][k + (int)(s[i] == t[0])], dp[i][j][k] + (s[i] == t[1] ? k : 0));
        if (j < k_) {
            chmax(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
            chmax(dp[i + 1][j + 1][k], dp[i][j][k] + k);
        }
    }
    
    int ans = -inf;
    rep(i, k_ + 1) rep(j, n + 1) chmax(ans, dp[n][i][j]);
    cout << ans << "\n";
}