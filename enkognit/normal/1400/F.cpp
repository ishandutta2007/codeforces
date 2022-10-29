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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, T, TT, ans, a[1000001], pref[1001], dp[1001][5001];
string gg;
bool tt[101];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x,ll y)
{
    while (x>0 && y>0)
    {
        if (x>y) swap(x, y);
        y%=x;
    }
    return x+y;
}

ll d[400001][10], ge[400001][10], hh[400001], pr[400001], link[400001], zn[400001];
ll kl;

ll go(int h,int o);

ll get_link(int h)
{
    if (link[h]==0)
        if (h==1 || pr[h]==1) link[h]=1;
            else link[h]=go(get_link(pr[h]), zn[h]);
    return link[h];
}

ll go(int h,int o)
{
    if (ge[h][o]==0)
        if (d[h][o]!=0) ge[h][o]=d[h][o]; else
        ge[h][o]=(h==1?1:go(get_link(h), o));
    return ge[h][o];
}

vector<pll> v;

void add(int h,int k,string& s)
{
    if (k==s.size())
    {
        a[h]++;
        return;
    }
    //cout << " " << h << " " << k << "\n";
    if (d[h][s[k]-'0']==0)
    {
        kl++;
        d[h][s[k]-'0']=kl;
        hh[kl]=hh[h]+1;
        pr[kl]=h;
        zn[kl]=s[k]-'0';
        v.pb(mp(hh[kl], kl));
    }
    add(d[h][s[k]-'0'], k+1, s);
}

void rec(int h)
{
    if (h==n)
    {
        bool t=0;
        for (int i = 0; i < gg.size() && !t; i++)
            for (int j = i; j < gg.size() && !t; j++)
                if (n%(pref[j]-(i==0?0:pref[i-1]))==0 && (pref[j]-(i==0?0:pref[i-1]))!=n) t=1;
        if (!t)
        {
            //cout << gg << "\n";
            add(1,0,gg);
            //cout << "--\n";
        }
        return;
    }
    for (int i = 1; i <= min(n-h, 9ll); i++)
    {
        pref[gg.size()]=((int)gg.size()==0?0:pref[gg.size()-1])+i;
        gg+=(i+'0');
        //cout << gg << "\n";
        rec(h+i);
        gg.pop_back();
    }
}

void solve()
{
    kl=1;
    string s;
    cin >> s;
    cin >> n;
    rec(0);
    //cout << "-----\n";
    for (int i = 0; i <= s.size(); i++)
        for (int j = 1; j <= kl; j++) dp[i][j]=1e9;
    for (int i = 0; i < v.size(); i++)
    {
        a[v[i].se]+=a[get_link(v[i].se)];
    }
    dp[0][1]=0;
    for (int i = 0; i < s.size(); i++)
        for (int j = 1; j <= kl; j++)
            if (dp[i][j]!=1e9)
            {
                dp[i+1][j]=min(dp[i][j]+1, dp[i+1][j]);
                if (a[go(j, s[i]-'0')]==0) dp[i+1][go(j, s[i]-'0')]=min(dp[i+1][go(j, s[i]-'0')], dp[i][j]);
            }
    ll ans=1e9;
    for (int i = 1; i <= kl; i++) ans=min(ans, dp[s.size()][i]);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
3
1 2 4
1 3 6

6
1 2 4
3 4 3
1 4 10
5 1 2
4 6 5
*/