#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<LL>> r(2, vector<LL>(n + 1));
        for (int i = 0; i < 2; i += 1)
            for (int j = 1; j <= n; j += 1) {
                cin >> r[i][j];
                r[i][j] += r[i][j - 1];
            }
        LL ans = LLONG_MAX;
        for (int i = 1; i <= n; i += 1)
            ans = min(max(r[1][i - 1], r[0][n] - r[0][i]), ans);
        cout << ans << "\n";
    }
    return 0;
}