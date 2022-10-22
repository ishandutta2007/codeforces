#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ld ans = 0.0, sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ll nwm = m - (n - i - 1);
        if (nwm >= 0)
        {
            ans = max(ans, (sum + (ld)min(nwm, (i+1ll)*k)) / (i + 1.0));
        }
    }
    cout << setprecision(60) << fixed << ans << "\n";
    return 0;
}