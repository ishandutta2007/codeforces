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

ll n, kl, m, T, hh[100001], in[100001],out[100001], k, i, j, h, bn[100001][20];
string s;
vector<ll> c[100001];

void dfs(int h,int k=0,int p=0)
{
    bn[h][0]=p;
    T++;
    in[h]=T;
    hh[h]=k;
    for (int i = 1; i < 20; i++) bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],k+1,h);
        }
    T++;
    out[h]=T;
}

bool is_acentor(int x,int y)
{
    return in[x]<=in[y] && out[x]>=out[y];
}

ll find_lca(int x,int y)
{
    if (is_acentor(x,y)) return x;
    for (int i = 19; i > -1; i--)
        if (!is_acentor(bn[x][i],y)) x=bn[x][i];
    return bn[x][0];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    in[0]=-1;
    out[0]=1e9;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        ll r1=hh[a]+hh[b]-hh[find_lca(a,b)]*2;
        if (r1<=k && k%2==r1%2) {cout << "YES\n";continue;}
        ll rxy=1+hh[x]+hh[y]-hh[find_lca(x,y)]*2,
           rax=hh[a]+hh[x]-hh[find_lca(a,x)]*2,
           ray=hh[a]+hh[y]-hh[find_lca(a,y)]*2,
           rbx=hh[b]+hh[x]-hh[find_lca(b,x)]*2,
           rby=hh[b]+hh[y]-hh[find_lca(b,y)]*2;
        if (rax+rby+1<=k && (rax+rby+1)%2==k%2) {cout << "YES\n";continue;}
        if (ray+rbx+1<=k && (ray+rbx+1)%2==k%2) {cout << "YES\n";continue;}
        if (rax+rby+1+rxy<=k && (rax+rby+1+rxy)%2==k%2) {cout << "YES\n";continue;}
        if (ray+rbx+1+rxy<=k && (ray+rbx+1+rxy)%2==k%2) {cout << "YES\n";continue;}
        cout << "NO\n";
    }
    return 0;
}
/*
*/