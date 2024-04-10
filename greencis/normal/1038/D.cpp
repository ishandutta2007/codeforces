#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[500005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    ll ans = 0;
    int mn = 2e9;
    int mnneg = 2e9;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            ans += a[i];
            mn = min(mn, a[i]);
        } else if (a[i] < 0) {
            ans -= a[i];
            mnneg = min(mnneg, -a[i]);
        } else mn = mnneg = 0;
    }
    if (mn > int(1e9)) {
        if (mnneg <= int(1e9))
            ans -= mnneg * 2;
    } else if (mn <= int(1e9)) {
        if (mnneg > int(1e9))
            ans -= mn * 2;
    }
    if (n == 1)
        ans = a[1];
    cout << ans << endl;
}