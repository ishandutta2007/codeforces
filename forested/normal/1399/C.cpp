// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;
void solve();
int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}

// Main Code
void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];
    
    vector<int> cnt(n + 1, 0);
    rep(i, n) ++cnt[w[i]];
    int ans = 0;
    rep(i, 2, 2 * n + 1) {
        int res = 0;
        rep(j, 1, n + 1) {
            int k = i - j;
            if (k > n) continue;
            if (j < k) res += min(cnt[j], cnt[k]);
            else if (j == k) res += cnt[j] / 2;
        }
        chmax(ans, res);
    }
    
    cout << ans << "\n";
    return;
}