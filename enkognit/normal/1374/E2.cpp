#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, a[5];
vector<pll> vv[5];
vector<pll> tt[200001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

#define dies_from_cringe exit(0)

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    k=m-k;
    for (int i = 1; i <= n; i++)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (x==0) x=1; else x=0;
        if (y==0) y=1; else y=0;
        vv[x*2+y].pb(mp(t,i));
    }
    for (int j = 0; j < 4; j++)sort(all(vv[j]));
    ll kl=0, sm=0, ans=1e18, mom=-1;
    while (kl<m)
    {
        ll p0=1e18, p1=1e18, p2=1e18;
        if (vv[0].size()>a[0]) p0=vv[0][a[0]].fi;
        if (vv[1].size()>a[1] && a[1]<k) p1=vv[1][a[1]].fi;
        if (vv[2].size()>a[2] && a[2]<k) p2=vv[2][a[2]].fi;
        if (p0==1e18 && p1==1e18 && p2==1e18) break;
        if (p0<=p1 && p0<=p2) tt[vv[0][a[0]].se].pb(mp(0,1e18)), sm+=p0, a[0]++, kl++; else
        if (p1<=p0 && p1<=p2) tt[vv[1][a[1]].se].pb(mp(0,1e18)), sm+=p1, a[1]++, kl++; else
        if (p2<=p1 && p2<=p0) tt[vv[2][a[2]].se].pb(mp(0,1e18)), sm+=p2, a[2]++, kl++;
    }
    ll o=k;
    for (int i = 0; i <= min((ll)vv[3].size(), k); i++)
    {
        //cout << i << " " << kl << " " << sm << "\n";
        if (ans>sm && i+kl==m)
        {
            mom=i;
            ans=sm;
        }
        if (i<min((ll)vv[3].size(), k))
        {
            tt[vv[3][i].se].pb(mp(i+1,1e18));
            sm+=vv[3][i].fi;
            o--;
            while (a[1]>o)
            {
                a[1]--;
                sm-=vv[1][a[1]].fi, tt[vv[1][a[1]].se].back().se=i;
                kl--;
            }
            while (a[2]>o)
            {
                a[2]--;
                sm-=vv[2][a[2]].fi, tt[vv[2][a[2]].se].back().se=i;
                kl--;
            }
            while (i+1+kl<m && a[0]<vv[0].size())
            {
                kl++;
                sm+=vv[0][a[0]].fi;
                tt[vv[0][a[0]].se].pb(mp(i+1,1e18));
                a[0]++;
            }
            while (i+1+kl>m)
            {
                ll p0=-1, p1=-1, p2=-1;
                if (a[0]>0) p0=vv[0][a[0]-1].fi;
                if (a[1]>0) p1=vv[1][a[1]-1].fi;
                if (a[2]>0) p2=vv[2][a[2]-1].fi;
                if (p1==-1 && p2==-1 && p3==-1) break;
                if (p0>=p1 && p0>=p2) sm-=p0, tt[vv[0][a[0]-1].se].back().se=i, a[0]--, kl--; else
                if (p1>=p0 && p1>=p2) sm-=p1, tt[vv[1][a[1]-1].se].back().se=i, a[1]--, kl--; else
                if (p2>=p1 && p2>=p0) sm-=p2, tt[vv[2][a[2]-1].se].back().se=i, a[2]--, kl--;
            }
        }
    }
    if (mom==-1) {cout << "-1\n";exit(0);}
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < tt[i].size(); j++)
            if (tt[i][j].fi<=mom && tt[i][j].se>=mom)
            {
                cout << i << " ";
                break;
            }
    return 0;
}

/*d
1
3 3
10 1 2
5 1 1
*/