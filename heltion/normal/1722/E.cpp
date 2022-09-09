#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr bool multiple_test_cases = true;
int main() {
    auto main = [](){
        int m = 1000;
        vector s(m + 1, vector<LL>(m + 1));
        int n, q;
        cin >> n >> q;
        for (int i = 0, h, w; i < n; i += 1) {
            cin >> h >> w;
            s[h][w] += h * w;
        }
        for (int i = 1; i <= m; i += 1)
            for (int j = 1; j <= m; j += 1)
                s[i][j] += s[i][j - 1];
        for (int i = 1; i <= m; i += 1)
            for (int j = 1; j <= m; j += 1)
                s[i][j] += s[i - 1][j];
        for (int i = 0, hs, ws, hb, wb; i < q; i += 1) {
            cin >> hs >> ws >> hb >> wb;
            cout << s[hb - 1][wb - 1] - s[hb - 1][ws] - s[hs][wb - 1] + s[hs][ws] << "\n";
        }
    };
/*================================================*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    if (multiple_test_cases) {
        cin >> t;
    }
    for (int ti = 1; ti <= t; ti += 1) {
        main();
    }
}