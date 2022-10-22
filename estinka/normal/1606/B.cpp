#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        ll have = 1;
        while (have < n && have <= k)
        {
            ans++;
            have += have;
        }
        n -= have;
        if (n >= 0) ans += (n + k - 1) / k;
        cout << ans << "\n";
    }
    return 0;
}