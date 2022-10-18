#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, x, a[100105];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * 1LL * x;
        if (x > 1)
            --x;
    }
    cout << ans;

    return 0;
}