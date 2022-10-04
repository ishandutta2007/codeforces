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
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> ok(n);
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        bool need = false;
        for (int i = 0; i + 1 < n; ++i) {
            if (ok[i]) continue;
            if (a[i][j] > a[i + 1][j]) {
                need = true;
            }
        }
        if (need) ++ans;
        else {
            for (int i = 0; i + 1 < n; ++i) {
                if (a[i][j] < a[i + 1][j]) ok[i] = true;
            }
        }
    }
    cout << ans << '\n';
}