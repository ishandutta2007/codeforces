#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, m, k, d, h, TT, T, P, SZ, mx=0, ans, kl, nxt[1000001], nm[1000001], pch[1000001], is[1000001], a[1000001], rzm[1000001];
vector<int> prv[1000001];
vector<ll> v;
bool tt[1000001];
ll tl[1000001];

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

void dfs(int h,int k=1)
{
    tt[h]=1;
    tl[h]=k;
    //v.pb(h);
    ll p=nxt[h];
    if (tt[p])
    {
        if (tl[p])
        {
            T++;
            pch[T]=h;
            rzm[T]=tl[h]-tl[p]+1;
            tl[h]=0;
            return;
        }
    }else dfs(p,k+1);
    tl[h]=0;
    //v.pop_back();
}

void dfs2(int h,int k=0)
{
    //cout << h << " - " << k << " " << prv[h].size() << " " << tt[0] <<  "\n";
    tt[h]=1;
    mx=max(mx,k+1);
    if (a[h]==1 && is[k%SZ]!=TT)
    {
        is[k%SZ]=TT;
        kl++;
    }
    for (int i = 0; i < prv[h].size(); i++)
        if (!tt[prv[h][i]]) dfs2(prv[h][i], k+1);
}

void solve()
{
    cin >> n >> m;
    //a.resize(n,vector<ll>(m,0));
    T=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) nxt[i*m+j]=0, nm[i*m+j]=0, prv[i*m+j].clear(), tt[i*m+j]=0, is[i*m+j]=0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            a[i*m+j]=(s[j]=='0'?1:0);
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            ll c=s[j];
            if (c=='L') nxt[i*m+j]=i*m+j-1; else
            if (c=='R') nxt[i*m+j]=i*m+j+1; else
            if (c=='U') nxt[i*m+j]=(i-1)*m+j; else
            nxt[i*m+j]=(i+1)*m+j;
            prv[nxt[i*m+j]].pb(i*m+j);
            //cout << i*m+j << " : " << nxt[i*m+j] << "\n";
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!tt[i*m+j])
            {
                dfs(i*m+j);
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) tt[i*m+j]=0;
    kl=0;
    ll ans=0;
    for (int i = 1; i <= T; i++)
    {
        TT=i;
        SZ=rzm[i];
        mx=0;
        int u=kl;
        dfs2(pch[i]);
        //cout << pch[i] << " " << rzm[i] << " : " << " " << mx << " " << kl-u << "\n";
        mx=min(mx,rzm[i]);
        kl=min(kl,u+mx);
        ans+=mx;
    }
    cout << ans << " " << kl << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //for (ll i = 1; i <= 60; i++) pr[i]=pr[i-1]+(1ll<<(i-1));
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/