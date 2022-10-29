#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, m, T, k, kl, a[1000001], dst1[1000001], dstn[1000001];
vector<ll> c[200001];
string s;
map<int,bool> ww;

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) c[i].clear(), dst1[i]=1e18, dstn[i]=1e18;
    for (int i = 1; i <= k; i++) {cin >> a[i];}
    for (int i = 0 ;i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    set<pair<int,int> > s;
    s.insert(mp(0,1));
    dst1[1]=0;
    while (s.size())
    {
        ll x=(*s.begin()).se, h=(*s.begin()).fi;
        s.erase(s.begin());
        for (int i = 0; i < c[x].size(); i++)
            if (dst1[c[x][i]]>h+1)
        {
            s.erase(mp(dst1[c[x][i]],c[x][i]));
            dst1[c[x][i]]=h+1;
            s.insert(mp(dst1[c[x][i]],c[x][i]));
        }
    }
    s.insert(mp(0,n));
    dstn[n]=0;
    while (s.size())
    {
        ll x=(*s.begin()).se, h=(*s.begin()).fi;
        s.erase(s.begin());
        for (int i = 0; i < c[x].size(); i++)
            if (dstn[c[x][i]]>h+1)
        {
            s.erase(mp(dstn[c[x][i]],c[x][i]));
            dstn[c[x][i]]=h+1;
            s.insert(mp(dstn[c[x][i]],c[x][i]));
        }
    }
    ll ans=0;
    vector<pll> v1;

    for (int i = 1 ;i <= k; i++) v1.pb(mp(dst1[a[i]]-dstn[a[i]],a[i]));
    sort(all(v1));
    ll mx=dst1[v1[0].se];
    for (int i = 1; i < v1.size(); i++)
    {
        ans=max(ans,mx+dstn[v1[i].se]+1);
        mx=max(mx,dst1[v1[i].se]);
    }
    cout << min(ans,dst1[n]) << "\n";
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
*/