#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
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

int n, m, k, T, sm, a[200005], len[200005], b[200005], dp[200005][22];
vector<int> v[200005];
int ps[200005][22];
bool tt[200005];

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

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

int d[1600005];

void build(int h,int l,int r)
{
    if (l==r)
    {
        if (l!=n+1 && l==v[a[l]].back()) d[h]=1e9, tt[l]=0; else d[h]=l, tt[l]=1;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=min(d[h*2],d[h*2+1]);
}

ll X, Y;

void update(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=Y;
        return;
    }
    int w=(l+r)/2;
    if (X<=w) update(h*2,l,w); else update(h*2+1,w+1,r);
    d[h]=min(d[h*2],d[h*2+1]);
}


int get(int h,int l,int r)
{
    if (X>r || Y<l) return 1e9;
    if (X<=l && r<=Y) return d[h];
    int w=(l+r)/2;
    return min(get(h*2,l,w), get(h*2+1,w+1,r));
}

vector<ll> zz;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        len[i]=0;
        for (int j = 0; j <= k; j++) ps[i][j]=0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll x=a[i];
        for (int j = 0; j < zz.size(); j++)
        {
            if (zz[j]*zz[j]>x) break;
            while (x%(zz[j]*zz[j])==0) x/=zz[j]*zz[j];
        }
        a[i]=x;
    }

    vector<pll> z;

    for (int i = 1; i <= n; i++)
    {
        z.pb(mp(a[i], i));
    }

    sort(all(z));
    ll kk=0;
    for (int i = 0; i < z.size(); i++)
    {
        if (i==0 || z[i].fi!=z[i-1].fi) kk++;
        a[z[i].se]=kk;
    }

    for (int i = n; i > 0; i--)
    {
        v[a[i]].pb(i);
    }

    build(1,1,n+1);

    for (int i = 1; i <= kk; i++) v[i].pop_back();

    int lst=0;

    for (int i = 1; i <= n; i++) len[i]=-1;

    {
        lst=1;
        while (lst<n+1 && len[1]<=k)
        {
            X=lst+1;
            Y=n+1;
            ps[1][len[1]+1]=get(1,1,n+1);
            lst=ps[1][len[1]+1];
            len[1]++;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (v[a[i-1]].size()) tt[v[a[i-1]].back()]=0, X=v[a[i-1]].back(), Y=1e9, update(1,1,n+1), v[a[i-1]].pop_back();
        for (int j = 0; j <= len[i-1]; j++)
        {
            if (tt[ps[i-1][j]])
            {
                len[i]++;
                ps[i][len[i]]=ps[i-1][j];
            }
        }
        lst=(len[i]>-1?ps[i][len[i]]:i);
        while (lst<n+1 && len[i]<=k)
        {
            X=lst+1;
            Y=n+1;
            ps[i][len[i]+1]=get(1,1,n+1);
            lst=ps[i][len[i]+1];
            len[i]++;
        }
    }

    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= k; j++) dp[i][j]=1e9;
    dp[1][0]=0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            if (dp[i][j]<1e9)
            {
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
                //cout << i << " " << j << " " << dp[i][j] << "\n";
                for (int u = 0; u <= min(len[i], k-j); u++)
                    dp[ps[i][u]][j+u]=min(dp[i][j]+1, dp[ps[i][u]][j+u]);
            }
    int ans=1e9;
    for (int i = 0; i <= k; i++) ans=min(ans, dp[n+1][i]);
    cout << ans << "\n";
    //for (int i = 1; i <= kk; i++) cout << (int)v[i].size() << " ";
    //cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll o=sqrt(1e7);
    for (int i = 2; i <= o; i++)
        if (!tt[i])
        {
            zz.pb(i);
            ll j=i*i;;
            while (j<=o) tt[j]=1, j+=i;
        }
    //cout << zz.size() << "\n";
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}