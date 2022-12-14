#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int maxn = 500;
int a[maxn], seg[maxn][maxn], ans[maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int r = 0; r < n; r++) {
        seg[r][r] = a[r];
        for (int l = r - 1; l >= 0; l--) {
            for (int i = l; i < r; i++) {
                int sl = seg[l][i], sr = seg[i + 1][r];
                if (sl && sl == sr) seg[l][r] = sl + 1;
            }
        }
    }

    fill_n(ans, n, n);
    for (int i = 0; i < n; i++) {
        if (seg[0][i]) ans[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (seg[j][i]) ans[i] = min(ans[i], ans[j - 1] + 1);
        }
    }

    cout << ans[n - 1];
}