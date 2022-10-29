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
int solve() {
    int n;
    cin >> n;
    
    if (n == 1) return 1;
    if (n & 1) return 0;
    int m = n;
    while (m % 2 == 0) m /= 2;
    int cnt = 0;
    for (int i = 3; i * i <= m; ++i) {
        while (m % i == 0) {
            m /= i;
            ++cnt;
        }
    }
    if (m != 1) ++cnt;
    if ((n / 2) & 1) {
        if (cnt == 0 || cnt >= 2) return 0;
        return 1;
    }
    if (cnt) return 0;
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "FastestFinger\n" : "Ashishgup\n");
}