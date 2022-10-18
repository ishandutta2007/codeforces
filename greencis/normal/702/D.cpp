#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;

ll d,k,a,b,t;
ll ans = 9e18;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> d >> k >> a >> b >> t;
    k = min(k, d);
    if (d % k == 0) ans = (d / k - 1) * t + d * a;
    else ans = (d / k) * t + d * a;
    ans = min(ans, d * b);
    if (k*a + t - k*b < 0) {
        if (d % k) {
            ll i = d / k;
            ans = min(ans, i*k*a + (i-1)*t + (d-i*k)*b);
        }
    }
    ans = min(ans, k * a + (d - k) * b);
    cout << ans;

    return 0;
}