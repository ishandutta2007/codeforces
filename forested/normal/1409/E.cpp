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
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> y[i];
    
    vector<int> xs = x;
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    
    vector<int> cnt(xs.size(), 0);
    rep(i, n) ++cnt[lower_bound(all(xs), x[i]) - xs.begin()];
    vector<int> sum(xs.size() + 1, 0);
    rep(i, xs.size()) sum[i + 1] = sum[i] + cnt[i];
    vector<int> lef(xs.size(), -1);
    rep(i, xs.size()) {
        lef[i] = (int)(lower_bound(all(xs), xs[i] - k) - xs.begin()) - 1;
    }
    
    vector<int> catch_(xs.size(), 0);
    rep(i, xs.size()) {
        catch_[i] = sum[i + 1] - sum[lef[i] + 1];
    }
    vector<int> mx(xs.size(), 0);
    mx[0] = catch_[0];
    rep(i, xs.size() - 1) mx[i + 1] = max(mx[i], catch_[i + 1]);
    int ans = 0;
    rep(i, xs.size()) {
        int res = catch_[i];
        if (lef[i] != -1) res += mx[lef[i]];
        chmax(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}