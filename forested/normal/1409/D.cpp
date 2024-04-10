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
    unsigned long long n;
    int s;
    cin >> n >> s;
    
    vector<int> n_;
    auto m = n;
    while (m) {
        n_.push_back(m % 10);
        m /= 10;
    }
    while (n_.size() < 30) n_.push_back(0);
    reverse(all(n_));
    
    vector<int> mn(n_.size() + 1, inf);
    rep(i, n_.size() + 1) {
        int sum = 0;
        rep(j, i, n_.size()) {
            if (n_[j] != 9) chmin(mn[i], sum + n_[j] + 1);
            sum += n_[j];
        }
        chmin(mn[i], sum);
    }
    
    vector<int> ans(n_.size(), 0);
    rep(i, n_.size()) {
        if (n_[i] + mn[i + 1] <= s) {
            ans[i] = n_[i];
            s -= n_[i];
        } else {
            ans[i] = n_[i] + 1;
            break;
        }
    }
    
    int ukuku = 0;
    rep(i, ans.size()) {
        if (ans[i]) {
            ukuku = i;
            break;
        }
    }
    vector<int> vec;
    rep(i, ukuku, ans.size()) vec.push_back(ans[i]);
    reverse(all(vec));
    unsigned long long p = 1, t = 0;
    rep(i, vec.size()) {
        t += vec[i] * p;
        p *= 10;
    }
    cout << t - n << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}