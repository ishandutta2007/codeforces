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

const ll mod = 1e9 + 7;
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
        vector<int> b(n);
        map<ll, ll> sum_dp;
        sum_dp[0] = 1;
        vector<ll> mydp(n + 1, 0); // last prefix sum
        mydp[0] = 1;
        ll pf = 0, sumtotal = 1; // 1 for no sums, just copies
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mydp[i + 1] = sumtotal;
            sumtotal += (mod + mydp[i + 1] - sum_dp[pf]) % mod;
            sumtotal %= mod;
            sum_dp[pf] = mydp[i + 1];
            pf += b[i];
        }
        ll ans = 0;
        for (pair<ll, ll> i : sum_dp) ans = (ans + i.second) % mod;
        cout << ans << "\n";
    }
    return 0;
}