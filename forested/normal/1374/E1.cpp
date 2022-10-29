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
    int n, k;
    cin >> n >> k;
    vector<ll> a, b, c;
    rep(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        if (y && z) {
            a.push_back(x);
        } else if (y) {
            b.push_back(x);
        } else if (z) {
            c.push_back(x);
        }
    }
    
    sort(all(a)); sort(all(b)); sort(all(c));
    
    vector<ll> a_sum(a.size() + 1, 0), b_sum(b.size() + 1, 0), c_sum(c.size() + 1, 0);
    rep(i, a.size()) a_sum[i + 1] = a_sum[i] + a[i];
    rep(i, b.size()) b_sum[i + 1] = b_sum[i] + b[i];
    rep(i, c.size()) c_sum[i + 1] = c_sum[i] + c[i];
    ll ans = INF;
    rep(i, a.size() + 1) {
        if (i > k || k - i > b.size() || k - i > c.size()) continue;
        chmin(ans, a_sum[i] + b_sum[k - i] + c_sum[k - i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << "\n";
}