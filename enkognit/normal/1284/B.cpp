#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

mt19937_64 rnd(time(NULL));

ll n, m, k, i, j, mx=0, kl=0, T=0, a[200001];
vector <ll> b[200001];
vector <pll> v;

bool comp(pll x,pll y)
{
    return (x.fi>y.fi || (x.fi==y.fi && x.fi>y.fi));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            ll x;
            cin >> x;
            b[i].pb(x);
        }
        bool t=0;
        for (int j = 1; j < a[i]; j++)
            if (b[i][j]>b[i][j-1]) {t=1;break;}
        if (!t) v.pb(mp(b[i][0],b[i].back()));
    }
    ll ans=n*n;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll p=v.size();
    v.pb(mp(-1e18,-1e18));
    for (int i = 0; i < v.size()-1; i++)
    {
        //cout << v[i].fi << " " << v[i].se << "\n";
        ll l=0, r=v.size()-1;
        while (l<r)
        {
            ll w=(l+r)/2;
            if (v[w].fi<=v[i].se) r=w; else l=w+1;
        }
        ans-=p-l;
        //cout << l << "\n";
    }
    cout << ans;
    return 0;
}
/*
4
101
10001
1
10
1101
*/