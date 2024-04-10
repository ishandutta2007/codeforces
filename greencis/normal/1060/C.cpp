#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x, a[2005], b[2005];
ll mx[2005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    cin >> x;

    for (int i = 0; i < 2005; ++i)
        mx[i] = 9e18;

    for (int i = 0; i < m; ++i) {
        ll cur = 0;
        for (int j = i; j < m; ++j) {
            cur += b[j];
            mx[j - i + 1] = min(mx[j - i + 1], cur);
        }
    }

    for (int i = 2004; i > 0; --i)
        mx[i - 1] = min(mx[i - 1], mx[i]);
    mx[0] = 0;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = 0;
        for (int j = i; j < n; ++j) {
            cur += a[j];
            int bi = upper_bound(mx, mx + 2005, x / cur) - mx;
            ans = max(ans, max(bi - 1, 0) * (j - i + 1));
           // cerr << i << "  " << j << " " << bi << " " << x - cur << " " << ans << endl;
        }
    }
    cout << ans << endl;
}