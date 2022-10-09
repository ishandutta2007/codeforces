#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    for (int a1 = 0; a1 < 3; ++a1) {
        for (int a2 = a1 + 1; a2 < 3; ++a2) {
            string ans;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < 2 * n; ++i) {
                if (s[a1][i] == '0')
                    ++cnt1;
                else
                    ++cnt2;
            }
            if (cnt1 > cnt2) {
                int i1 = 0, i2 = 0;
                while (i1 < 2 * n || i2 < 2 * n) {
                    if (i1 == 2 * n) {
                        ans += s[a2][i2];
                        ++i2;
                    } else if (i2 == 2 * n) {
                        ans += s[a1][i1];
                        ++i1;
                    } else if (s[a1][i1] == s[a2][i2]) {
                        ans += s[a1][i1];
                        ++i1, ++i2;
                    } else if (s[a1][i1] == '1') {
                        ans += s[a1][i1];
                        ++i1;
                    } else {
                        ans += s[a2][i2];
                        ++i2;
                    }
                }
                if (ans.size() <= 3 * n) {
                    cout << ans << '\n';
                    return;
                }
            } else {
                int i1 = 0, i2 = 0;
                while (i1 < 2 * n || i2 < 2 * n) {
                    if (i1 == 2 * n) {
                        ans += s[a2][i2];
                        ++i2;
                    } else if (i2 == 2 * n) {
                        ans += s[a1][i1];
                        ++i1;
                    } else if (s[a1][i1] == s[a2][i2]) {
                        ans += s[a1][i1];
                        ++i1, ++i2;
                    } else if (s[a1][i1] == '0') {
                        ans += s[a1][i1];
                        ++i1;
                    } else {
                        ans += s[a2][i2];
                        ++i2;
                    }
                }
                if (ans.size() <= 3 * n) {
                    cout << ans << '\n';
                    return;
                }
            }
        }
    }
    exit(1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
    // solve();
}