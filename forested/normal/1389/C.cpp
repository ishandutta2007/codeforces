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
    string s;
    cin >> s;
    
    vector<vector<int>> nxt(s.size() + 1, vector<int>(10, (int)s.size()));
    per(i, s.size()) {
        rep(j, 10) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - '0'] = i;
    }
    
    int ans = inf;
    rep(i, 10) {
        int cnt = 0;
        rep(j, s.size()) if (s[j] == '0' + i) ++cnt;
        chmin(ans, (int)s.size() - cnt);
    }
    rep(i, 10) rep(j, 10) {
        int mx = 0, now = 0;
        while (now < s.size()) {
            if (nxt[now][i] == s.size()) break;
            now = nxt[now][i] + 1;
            if (nxt[now][j] == s.size()) break;
            now = nxt[now][j] + 1;
            mx += 2;
        }
        chmin(ans, (int)s.size() - mx);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}