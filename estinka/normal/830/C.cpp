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

inline ll ceildiv(const ll& a, const ll& b)
{
    return (a + b - 1) / b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll>a(n);
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        k += a[i];
        for (ll j = 1; j * j <= a[i]; j++)
        {
            s.insert(j);
            s.insert(ceildiv(a[i], j));
        }
    }
    vector<ll> aa;
    for (ll i : s) aa.push_back(i);
    aa.push_back(1e16);
    ll ans = -1;
    for (ll i = 0; i < aa.size() - 1; i++)
    {
        ll l = aa[i], r = aa[i + 1] - 1;
        ll s = 0;
        for (ll j : a) s += ceildiv(j, l);
        ll cn = k / s;
        if (cn < l || cn > r) continue;
        ans = max(ans, k / s);
    }
    cout << ans << "\n";
    return 0;
}