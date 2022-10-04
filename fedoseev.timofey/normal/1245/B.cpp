#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        string ans(n, '$');
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R' && b > 0) {
                ans[i] = 'P';
                --b;
                ++cnt;
            }
            if (s[i] == 'P' && c > 0) {
                ans[i] = 'S';
                --c;
                ++cnt;
            }
            if (s[i] == 'S' && a > 0) {
                ans[i] = 'R';
                --a;
                ++cnt;
            }
        }
        if (2 * cnt >= n) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                if (ans[i] == '$') {
                    if (a > 0) {
                        ans[i] = 'R';
                        --a;
                    } else if (b > 0) {
                        ans[i] = 'P';
                        --b;
                    } else {
                        ans[i] = 'S';
                        --c;
                    }
                }
                cout << ans[i];
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}