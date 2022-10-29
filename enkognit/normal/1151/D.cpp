#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define ld long double
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, i, j, k, l, r; pll a[500001];
vector <pll> b;
map<ll,ll> t;

bool comp(pll x,pll y)
{
    return x.fi-x.se>y.fi-y.se;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a,a+n,comp);
    ll ans=0;
    for (int i = 0; i < n; i++)
        ans+=(a[i].fi-a[i].se)*(i+1)-a[i].fi+a[i].se*n;
    cout << ans;
    return 0;
}