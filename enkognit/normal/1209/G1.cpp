#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, k, l, m, r, i, j, x, y, ans, dp[1000001], a[1000001];
ll tt[1000001], fst[1000001], lst[1000001];
vector <pair<pll,ll> > v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!tt[a[i]])
        {
            fst[a[i]]=i;
        }
        tt[a[i]]++;
        lst[a[i]]=i;
    }
    for (int i = 1; i <= 200000; i++)
        if (tt[i])
    {
        v.pb(mp(mp(fst[i],lst[i]),tt[i]));
    }
    sort(v.begin(),v.end());
    v.pb(mp(mp(1e18,1e18),0));
    ll mx=v[0].se, sm=v[0].se;
    ll ans=0;
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i].fi.se<v[i+1].fi.fi)
        {
            ans+=sm-mx;
            mx=v[i+1].se,sm=v[i+1].se;
        }else
        sm+=v[i+1].se,mx=max(mx,v[i+1].se), v[i+1].fi.se=max(v[i+1].fi.se,v[i].fi.se);
    }
    cout << ans;
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/