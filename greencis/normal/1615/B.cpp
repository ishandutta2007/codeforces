#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int cnt[200200][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < 200200; ++i) {
        for (int j = 0; j < 20; ++j) {
            cnt[i][j] = cnt[i - 1][j];
            if (i & (1 << j))
                ++cnt[i][j];
        }
    }

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int l, r;
        cin >> l >> r;

        int ans = 1e9;
        for (int i = 0; i < 20; ++i) {
            int cur = cnt[r][i] - cnt[l - 1][i];
            ans = min(ans, r - l + 1 - cur);
        }
        cout << ans << endl;
    }
}