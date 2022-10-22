#include <iostream>
#include <vector>
#include <map>
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
        int n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i] * 2;
            a[i] *= n;
        }
        map<ll, ll> m;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += m[sum - a[i]];
            m[a[i]]++;
        }
        cout << ans << "\n";
    }
    return 0;
}