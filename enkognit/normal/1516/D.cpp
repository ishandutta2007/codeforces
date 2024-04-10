#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, a[100005], b[100005], lst[100005];
vector<ll> c[100005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

ll bn[100005][20];

void dfs(int h,int p=0)
{
    bn[h][0]=p;
    for (int i = 1; i < 20; i++)
        bn[h][i]=bn[bn[h][i-1]][i-1];
    for (int i = 0; i < c[h].size(); i++)
        dfs(c[h][i], h);
}

void solve()
{
    cin >> n >> m;
    b[0]=1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll p=sqrt(a[i]), x=a[i];
        vector<ll> v;
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                v.pb(j);
                while (x%j==0) x/=j;
            }
        ll mx=b[i-1];
        if (x>1) v.pb(x);
        for (int j = 0; j < v.size(); j++)
        {
            mx=max(mx, lst[v[j]]+1);
            lst[v[j]]=i;
        }
        b[i]=mx;
        //cout << i << " " << b[i] << "\n";
        c[b[i]-1].pb(i);
    }
    dfs(0);
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        ll u=0;
        for (int j = 19; j > -1; j--)
            if (bn[y][j]>=x) y=bn[y][j], u+=(1<<j);
        cout << u+1 << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/