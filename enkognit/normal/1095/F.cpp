#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

set <pll > s;
vector <pll> c[200001];
map <ll,ll> t;

int main()
{
    ll n,m;
    ll a[200001];
    cin >> n >> m;
    int i;
    ll l=1e9,p=0;
    for (int i = 0; i < n; i++) {cin >> a[i];if (a[i]<l) l=a[i],p=i;}
    for (i = 0; i < m; i++)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        x--,y--;
        c[x].pb(mp(h,y));
        c[y].pb(mp(h,x));
    }
    for (i = 0; i < n; i++) if (i!=p)c[p].pb(mp(a[i]+a[p],i));
    for (int i=0;i<c[p].size();i++)
    {
        s.insert(c[p][i]);
    }
    t[p]=1;
    ll ans=0;
    while (!s.empty())
    {
        pll k=*s.begin();
        s.erase(s.begin());
        if (t[k.se]) continue;
        ans+=k.fi;
        //cout << k.se << " " << ans << "\n";
        t[k.se]=1;
        for (int i=0;i<c[k.se].size();i++)
            if (!t[c[k.se][i].se]) s.insert(c[k.se][i]);
    }
    cout << ans;
    return 0;
}