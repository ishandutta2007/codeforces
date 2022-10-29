#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb puhs_back
#define pll pair<ll,ll>
#define se second
#define fi first

using namespace std;

ll n, m, k, l, r, i, j, a[1000001];

void solve()
{
    cin >> n;
    ll mx=-1e18, mn=1e18;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mx=max(mx,x);
        mn=min(mn,y);
    }
    if (mx<=mn) {cout << "0\n";} else
    cout << mx-mn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}