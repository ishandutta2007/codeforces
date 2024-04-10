#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, h, T, Q;
pll dp[2001][2001];
ll rang[2001][2001];
bool tt[1000001];
vector<pll> g[2001];
ll a[10];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll gt(ll h)
{
    ll msk=0;
    bool t=0;
    ll j=7;
    if (h==10010) t=1;
    while (j--)
    {
        msk*=2;
        msk+=h%10;
        h/=10;
       // if (t) cout << h << " " << msk << "\n";
    }
    return msk;
}

void solve()
{
    cin >> n >> k;
    vector<ll> v;
    a[0]=gt(1110111);
    a[1]=gt(10010);
    //cout << a[1] << "\n";
    a[2]=gt(1011101);
    a[3]=gt(1011011);
    a[4]=gt(111010);
    a[5]=gt(1101011);
    a[6]=gt(1101111);
    a[7]=gt(1010010);
    a[8]=gt(1111111);
    a[9]=gt(1111011);
    for (int i = 1; i <= n; ++i)
    {
        string s;
        ll msk=0;
        cin >> s;
        for (int j = s.size()-1; j > -1; --j)
        {
            msk*=2;
            msk+=s[j]-'0';
        }
        v.pb(msk);
        //cout << msk << "\n";
    }
    for (int i = 0; i < n; ++i)
    {
        //cout << v[i] << " ";
        for (int j = 9; j > -1; --j)
        {
            //cout << " " << ((a[j]&v[i])==v[i]) << "\n";
            if ((a[j]&v[i])==v[i])
            {
                g[i].pb(mp(j,__builtin_popcount(a[j]^v[i])));
            }
        }
        if (g[i].size()==0) {cout << "-1\n";return;}
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++) dp[i][j]=mp(-1,-1), rang[i][j]=-1;
    dp[0][0]=mp(0,0);
    rang[0][0]=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
            if (dp[i][j].fi!=-1 && dp[i][j].se!=-1)
            {
                //cout << i << " " << j << " :\n";
                for (int u = 0; u < g[i].size(); u++)
                {
                    //cout << " " << g[i][u].fi << " " << g[i][u].se << "\n";
                    if (j+g[i][u].se<=k)
                    {

                        if (dp[i+1][j+g[i][u].se].fi==-1)
                        {
                            dp[i+1][j+g[i][u].se]=mp(j,g[i][u].fi);
                        } else
                        {
                            if (rang[i][dp[i+1][j+g[i][u].se].fi]<rang[i][j] ||
                                rang[i][dp[i+1][j+g[i][u].se].fi]==rang[i][j] && dp[i+1][j+g[i][u].se].se<g[i][u].fi)
                                {
                                    dp[i+1][j+g[i][u].se]=mp(j,g[i][u].fi);
                                }
                        }
                    }
                }
            }
        vector<pair<pll,ll> > vv;
        for (int j = 0; j <= k; j++)
            if (dp[i+1][j].fi!=-1)
                vv.pb(mp(mp(rang[i][dp[i+1][j].fi], dp[i+1][j].se), (ll)j));
        sort(all(vv));
        for (int j = 0; j < vv.size(); j++)
            rang[i+1][vv[j].se]=j;
    }
    string d="";
    //cout << dp[n][k].fi << " " << dp[n][k].se << "\n";
    //cout << dp[n][k].fi << " " << dp[n][k].se << "\n";
    if (dp[n][k].fi==-1) {cout << "-1\n";return;} else
    {
        ll p=k, j=n;
        while (j)
        {
            //cout << j << " " << p << " " << dp[j][p].fi << " " << dp[j][p].se << "\n";
            d+=(char)('0'+dp[j][p].se);
            p=dp[j][p].fi;
            j--;
        }
    }
    reverse(all(d));
    cout << d;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout<<fixed;
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/