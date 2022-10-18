#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

int a[40];
unordered_set<int> st[21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        int half = (n + 1) / 2;
        int ans = 0;
        for (int minpos = 0; minpos < n; ++minpos) {
            int mn = a[minpos];
            for (int i = 0; i <= half; ++i)
                st[i].clear();
            st[0].insert(0);
            for (int i = 0; ans != -1 && i < n; ++i) {
                if (a[i] < mn) continue;
                int diff = mn - a[i];
                for (int m = half - 1; m >= 0; --m) {
                    for (int x : st[m]) {
                        st[m + 1].insert(gcd(x, diff));
                    }
                }
            }
            for (int x : st[half]) {
                if (x == 0) {
                    ans = -1;
                    break;
                }
                if (x > ans) {
                    ans = x;
                }
            }
        }
        cout << ans << '\n';
    }
}