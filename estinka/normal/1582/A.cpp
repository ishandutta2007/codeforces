#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

ll a[4], b[4];
ll dif()
{
    return abs(a[1] + a[2] * 2 + a[3] * 3 - (b[1] + b[2] * 2 + b[3] * 3) * 2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a[1] >> a[2] >> a[3];
        ll ans = 1e18;
        for (b[1] = max(0ll, a[1] / 2 - 3); b[1] <= min(a[1], a[1]/2 + 3); b[1]++) 
            for (b[2] = max(0ll, a[2] / 2 - 3); b[2] <= min(a[2], a[2] / 2 + 3); b[2]++)
                for (b[3] = max(0ll, a[3] / 2 - 3); b[3] <= min(a[3], a[3] / 2 + 3); b[3]++)
                    ans = min(ans, dif());
        cout << ans << "\n";
    }
    return 0;
}