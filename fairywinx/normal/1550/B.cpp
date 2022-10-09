#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    if (b >= 0) {
        cout << a * n + b * n << '\n';
    } else {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n;) {
            auto j = s[i];
            while (s[i] == j) {
                ++i;
            }
            if (j == '1')
                ++c1;
            else
                ++c2;
        }
        cout << (min(c1, c2) + 1) * b + a * n << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}