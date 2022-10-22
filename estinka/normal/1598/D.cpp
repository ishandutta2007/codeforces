#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

ll c2(ll x)
{
    return (x * (x - 1)) / 2ll;
}
ll c3(ll x)
{
    return (x * (x - 1) * (x - 2)) / 6ll;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = c3(n);
        vector<int> a(n), b(n);
        vector<ll> cnta(n, 0), cntb(n, 0);
        ll sameab = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            a[i]--, b[i]--;
            cnta[a[i]]++;
            cntb[b[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            sameab += (cnta[a[i]] - 1) * (cntb[b[i]] - 1);
        }
        ans -= sameab;
        cout << ans << "\n";
    }
    return 0;
}