#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, l, r, x, a[19], ans;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int mask = 1 << n; mask--; ) {
        int sum = 0, mn = 1e9, mx = -1e9;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                sum += a[i];
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
        }
        ans += sum >= l && sum <= r && mx - mn >= x;
    }
    cout << ans;

    return 0;
}