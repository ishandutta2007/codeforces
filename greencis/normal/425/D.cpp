#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;
 
constexpr int MAXN = 100'000;
 
struct Point {
    int x, y;
} pt[MAXN];
 
constexpr int MAXC = 100'000;
unordered_set<int> sx[MAXC + 1], sy[MAXC + 1];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pt[i].x >> pt[i].y;
        sx[pt[i].x].insert(pt[i].y);
        sy[pt[i].y].insert(pt[i].x);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [x, y] = pt[i];
        if (sx[x].size() >= sy[y].size()) {
            for (int x2 : sy[y]) {
                if (x2 > x && y + x2 - x <= MAXC) {
                    auto& rf = sy[y + x2 - x];
                    if (rf.contains(x) && rf.contains(x2))
                        ++ans;
                }
            }
        } else {
            for (int y2 : sx[x]) {
                if (y2 > y && x + y2 - y <= MAXC) {
                    auto& rf = sx[x + y2 - y];
                    if (rf.contains(y) && rf.contains(y2))
                        ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
}