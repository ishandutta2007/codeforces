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

const ll MOD=998244353;
ll n, m, k, l, r,  ans=1e9, T, TT;
ll tt[1000001];
vector<ll> vv;
vector<vector<ll> > z;
ll a[1000001], b[1000001];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=MOD;
        h*=h;
        h%=MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    ll T=0;
    z.clear();
    ans=1e9;
    for (int i = 1; i <= n; i++) {cin >> a[i];}
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<ll> v;
    T=0, TT=0;
    for (int i = 1; i <= n; i++) tt[i]=0;
    for (int i = 1; i <= n; i++)
        if (!tt[i])
        {
            TT++;
            ll h=i;
            v.clear();
            v.pb(h);
            tt[h]=TT;
            //cout << h << " ";
            while (!tt[a[h]])
            {
                h=a[h];
                tt[h]=TT;
                //cout << h << " ";
                v.pb(h);
            }
            //cout << "\n";
            if (tt[a[h]]!=TT) continue;
            T++;
            z.pb(vv);
            for (int i = v.size()-1; i > -1; i--)
            {
                z[T-1].pb(v[i]);
                if (v[i]==a[h])
                {
                    break;
                }
            }
        }
    for (int i = 0; i < T; i++)
    {
        //for (int j = 0; j < z[i].size(); j++) cout << z[i][j] << " ";
        //cout << "\n";
        ll p=sqrt(z[i].size()), l=z[i].size();
        vector<ll> g;
        for (int j = 1; j <= p; j++)
        {
            if (l%j==0)
            {
                g.pb(j);
                if (j!=l/j) g.pb(l/j);
            }
        }
        for (int j = 0; j < g.size(); j++)
        {
            ll x=g[j];
            //cout << x << "\n";
            for (int u = 0; u < x; u++) tt[u]=1;
            ll kl=x;
            for (int u = x; u < z[i].size(); u++)
            {
                if (b[z[i][u]]!=b[z[i][u%x]]) kl-=tt[u%x], tt[u%x]=0;
            }
            if (kl) ans=min(ans, x);
        }
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}