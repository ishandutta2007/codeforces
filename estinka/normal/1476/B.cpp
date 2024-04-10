#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

ll divup(ll a, ll b)
{
    return (a + b - 1) / b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n; ll k;
        cin >> n >> k;
        vector<ll> p(n);
        ll sum = 0, extra = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            if (i)
            {
                ll s1 = 100l * p[i], s2 = k * (sum + extra);
                if (s1 > s2) extra += divup(s1 - s2, k);
            }
            sum += p[i];
        }
        cout << extra << "\n";
    }
    return 0;
}