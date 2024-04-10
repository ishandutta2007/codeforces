#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, a[10001];
int dist[10001][1001];

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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+m+1);
    ll g, r;
    cin >> g >> r;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < g; j++) dist[i][j]=1e9+1;
    dist[1][0]=0;
    deque<pll> q;
    q.push_front(mp(1,0));
    while (!q.empty())
    {
        pll x=q.front();
        q.pop_front();
        ll i=x.fi;
        if (x.fi>1 && x.se+a[i]-a[i-1]<=g)
        {
            if (x.se+a[i]-a[i-1]<g)
            {
                if (dist[x.fi-1][x.se+a[i]-a[i-1]]>dist[x.fi][x.se])
                {
                    dist[x.fi-1][x.se+a[i]-a[i-1]]=dist[x.fi][x.se];
                    q.push_front(mp(x.fi-1,x.se+a[i]-a[i-1]));
                }
            }else
            {
                if (dist[x.fi-1][0]>dist[x.fi][x.se]+g+r)
                {
                    dist[x.fi-1][0]=dist[x.fi][x.se]+g+r;
                    q.push_back(mp(x.fi-1,0));
                }
            }
        }
        if (x.fi<m && x.se+a[i+1]-a[i]<=g)
        {
            if (x.se+a[i+1]-a[i]<g)
            {
                if (dist[x.fi+1][x.se+a[i+1]-a[i]]>dist[x.fi][x.se])
                {
                    dist[x.fi+1][x.se+a[i+1]-a[i]]=dist[x.fi][x.se];
                    q.push_front(mp(x.fi+1,x.se+a[i+1]-a[i]));
                }
            }else
            {
                if (dist[x.fi+1][0]>dist[x.fi][x.se]+g+r)
                {
                    dist[x.fi+1][0]=dist[x.fi][x.se]+g+r;
                    q.push_back(mp(x.fi+1,0));
                }
            }
        }
    }
    int ans=1e9+1;
    if (dist[m][0]!=1e9+1) ans=dist[m][0]-r;
    for (int i = 1; i < g; i++) ans=min(ans, dist[m][i]+i);
    if (ans==1e9+1) cout << "-1\n"; else
    cout << ans << "\n";
    return 0;
}
/*
3 2 1 20.0
1 2 1.0 1.0 1.0 1.0
2 3 1.0 1.0 1.1 1.0
*/