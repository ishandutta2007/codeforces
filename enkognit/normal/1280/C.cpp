#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimise("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

template <typename ENKOGNIT>
using ordered_set = tree<ENKOGNIT, null_type, less<ENKOGNIT>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, O, k, i, j, ans1, ans2, l, r, kl, OO, o, kol[2000001], rast[2000001];
pll zad;
vector<pll> c[2000001];

void dfs1(ll h,ll p=-1)
{
    kol[h]=1;
    rast[h]=0;
    for (int i =0; i < c[h].size(); i++)
        if (c[h][i].fi!=p)
        {
            dfs1(c[h][i].fi,h);
            kol[h]+=kol[c[h][i].fi];
            if (kol[c[h][i].fi]%2) ans1+=c[h][i].se;
            rast[h]+=rast[c[h][i].fi]+kol[c[h][i].fi]*c[h][i].se;
        }
}

void dfs2(ll h,ll p,pll zad)
{
    bool tt=1;
    if (zad.fi>n) {return;}
    ll kl=0, sum=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].fi!=p)
    {
        kl+=kol[c[h][i].fi];
        sum+=rast[c[h][i].fi]+c[h][i].se*kol[c[h][i].fi];
        if (kol[c[h][i].fi]>n) tt=0;
    }
    //cout << h << " " << zad.fi << " " << sum << " " << zad.se << "\n";
    if (tt) ans2=max(ans2,sum+zad.se);
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].fi!=p)
        {
            pll zd=zad;
            zd.fi+=kl-kol[c[h][i].fi]+1;
            zd.se+=zd.fi*c[h][i].se+sum-rast[c[h][i].fi]-c[h][i].se*kol[c[h][i].fi];
            dfs2(c[h][i].fi,h,zd);
        }
}

int main()
{
    //freopen("travelator.in","r",stdin);
    //freopen("travelator.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n*2; i++) c[i].clear(), kol[i]=0, rast[i]=0;
        for (int i = 1; i < n*2; i++)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            c[x].pb(mp(y,z));
            c[y].pb(mp(x,z));
        }
        ans1=0;ans2=0;zad=mp(0,0);
        dfs1(1);
        dfs2(1,0,zad);
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

*/