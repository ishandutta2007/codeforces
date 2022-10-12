#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int B = 400, N = 3e5+5;
int off[B];
deque<int> s[B];

void dbg() {
    debug();
    for (int i = 0; i < B; i++)
        if (s[i].size() > 0)
            debug(i, s[i], off[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int t = 0; t < n; t++) {
        int l, r; cin >> l >> r;
        debug(t, l, r);
        // remove >= r
        for (int i = 0; i < B; i++)
            if (!s[i].empty() && s[i].back()+off[i] >= r) {
                s[i].erase(lower_bound(all(s[i]), r-off[i]));
                break;
            }
        dbg();
        // shift [l, r]
        for (int i = 0; i < B; i++) {
            if (s[i].empty()) continue;
            int x = s[i].front()+off[i], y = s[i].back()+off[i];
            if (l <= x && y <= r)
                off[i]++;
            else if (l <= y && x <= r)
                for (auto& j : s[i])
                    if (l <= j+off[i] && j+off[i] <= r)
                        j++;
        }
        dbg();
        // insert l
        int p = l;
        for (int i = 0; i < B; i++) {
            if (s[i].empty() || p < s[i].front()+off[i]) {
                s[i].push_front(p-off[i]);
                p = -1;
            }
            else if (B*s[i].size() <= N || p < s[i].back()+off[i]) {
                s[i].insert(lower_bound(all(s[i]), p-off[i]), p-off[i]);
                p = -1;
            }
            if (B*s[i].size() > N+B) {
                p = s[i].back()+off[i];
                s[i].pop_back();
            }
            if (p == -1) break;
        }
        dbg();
    }
    int ans = 0;
    for (int i = 0; i < B; i++)
        ans += s[i].size();
    cout << ans << "\n";
}