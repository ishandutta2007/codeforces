#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1e9 + 7;
const ll logn = 61;
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
        vector<ll> x(n);
        vector<ll> f(logn, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            for (ll j = 0; j < logn; j++)
            {
                if ((1ll << j) & x[i])
                {
                    f[j]++;
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll andsum = 0, orsum = 0;
            for (ll j = 0; j < logn; j++)
            {
                if ((1ll << j) & x[i])
                {
                    andsum += (((1ll << j) % mod) * 1ll * f[j]) % mod;
                    orsum += (((1ll << j) % mod) * 1ll * n) % mod;
                }
                else orsum += (((1ll << j) % mod) * 1ll * f[j]) % mod;
                andsum %= mod;
                orsum %= mod;
            }
            ans += (andsum * orsum) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}