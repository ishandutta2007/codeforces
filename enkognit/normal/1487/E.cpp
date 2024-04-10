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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n[4], m, k, T, a[4][150005], dp[4][150005];
vector<ll> v;
vector<ll> c[3][150005];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll d[600005];

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=dp[T][l];
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=min(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 1e18;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return min(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    for (int i = 0; i < 4; i++) cin >> n[i];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= n[i]; j++)
        {
            cin >> a[i][j];
            if (i<3) c[i][j].pb(0), c[i][j].pb(n[i+1]+1);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            ll x, y;
            cin >> x >> y;
            c[i][x].pb(y);
        }
    }
    for (int i = 1; i <= n[3]; i++) dp[3][i]=a[3][i];
    for (int i = 2; i > -1; i--)
    {
        T=i+1;
        build(1, 1, n[i+1]);
        for (int j = 1; j <= n[i]; j++)
        {
            sort(all(c[i][j]));
            dp[i][j]=1e18;
            for (int u = 0; u < c[i][j].size()-1; u++)
            {
                dp[i][j]=min(dp[i][j], a[i][j]+get(1,1,n[i+1],c[i][j][u]+1,c[i][j][u+1]-1));
            }
        }
    }
    ll ans=1e18;
    for (int i = 1; i <= n[0]; i++) ans=min(ans, dp[0][i]);
    if (ans==1e18) ans=-1;
    cout << ans << "\n";
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
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/