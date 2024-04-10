#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 1e6 + 228;

int used[2 * N];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    if (s.back() == 'L') {
        for (auto &i : s) {
            if (i == 'R')
                i = 'L';
            else
                i = 'R';
        }
    }
    int l = -N, r = 0;
    while (r - l > 1) {
        int m = (l + r) / 2;
        fill(used, used + 2 * N, 0);
        int now = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            int to = now + (s[i] == 'L' ? -1 : 1);
            to = max(to, m + 1);
            if (i == (int) s.size() - 1) {
                if (!used[to + N] && to != 0) {
                    r = m;
                } else {
                    l = m;
                }
            }
            now = to;
            used[now + N] = 1;
        }
    }
    if (l == -N) {
        cout << 1 << '\n';
    } else {
        cout << -r << '\n';
    }
}