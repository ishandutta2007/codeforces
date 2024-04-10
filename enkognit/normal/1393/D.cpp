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

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, P, up[2002][2002], dw[2002][2002];
string s[2002];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
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

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i]=' '+s[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            up[i][j]=1;
            if (i>1 && j>1 && j<m)
            {
                if (s[i-1][j]==s[i-1][j-1] && s[i-1][j]==s[i-1][j+1] && s[i][j]==s[i-1][j])
                    up[i][j]=min(min(up[i-1][j-1], up[i-1][j+1]), up[i-1][j])+1;
            }
        }
    for (int i = n; i > 0; i--)
        for (int j = 1; j <= m; j++)
        {
            dw[i][j]=1;
            if (i<n && j>1 && j<m)
            {
                if (s[i+1][j]==s[i+1][j-1] && s[i+1][j]==s[i+1][j+1] && s[i][j]==s[i+1][j])
                    dw[i][j]=min(min(dw[i+1][j-1], dw[i+1][j+1]), dw[i+1][j])+1;
            }
        }
    ll ans=0;
    int i=1, j=2;
    //cout << dw[i][j] << " " << min(min(dw[i+1][j-1], dw[i-1][j+1]), dw[i+1][j])+1 << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll l=1, r=min(min((ll)i,n-i+1), min((ll)j,m-j+1));
            while (l<r)
            {
                int w=(l+r+1)/2;
                //if (i==2 && j==3) cout << w << " " << dw[i-w+1][j] << " " << up[i+w-1][j] << "\n";
                if (dw[i-w+1][j]>=w && up[i+w-1][j]>=w) l=w; else r=w-1;
            }
            //cout << i << " " << j << " " << up[i+1][j] << " " << dw[i-1][j] << " " << l << "\n";
            ans+=l;
        }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}