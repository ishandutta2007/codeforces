#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[1000001], dp[1000001], kol=0, T=0, mask;
pair <ll,ll> c[200001], ans[16];
bool tt[200001];
map <ll,ll> w, q;
map <int, vector <pair<ll,pair<ll,ll > > > > ff;
vector <ll> v[16];
vector <pair<ll ,pair<ll,ll > > > way;
ll s;
bool tw[10001], pp[200001];

void make(ll x,ll y,ll h)
{
    if (!w[x]) kol++,w[x]=kol,q[kol]=x;
    if (!w[y]) kol++,w[y]=kol,q[kol]=y;
    c[w[x]]=mp(w[y],h);
    //cout << x << " - " << y << "\n";
}

void dfs(ll h,ll p)
{
    tt[h]=1;
    //cout << q[h] << "\n";
    if (!tw[c[h].se] && !pp[c[h].fi])
    {
        way.pb(mp(c[h].se, mp(q[h], c[h].se)));
        if (c[h].fi==p)
        {
            T=1;
            mask^=(1<<(c[h].se-1));
            pp[h]=1;
            tt[h]=0;
            dp[mask]=0;
            if (ff[mask].size()==0) ff[mask]=way;
            //cout << "--" << mask << "\n";
            return;
        }else
        if (!tt[c[h].fi])
        {
            tw[c[h].se]=1;
            mask^=(1<<(c[h].se-1));
            dfs(c[h].fi,p);
            tw[c[h].se]=0;
            mask^=(1<<(c[h].se-1));
        }
        way.erase(way.end()-1);
        if (T) {pp[h]=1;tt[h]=0;return;}
    }
}

void rec(ll h)
{
    if (dp[h]==-1) return;
    if (dp[h]==0)
    {
        //cout << h << "\n";
        for (int i = 0; i < ff[h].size(); i++)
        {
            ll j=i-1;
            if (i==0) j=ff[h].size()-1;
            ans[ff[h][i].fi]=mp(ff[h][i].se.fi, ff[h][j].se.se);
            //cout << ff[h][i].fi << " " << ff[h][i].se.fi << " " << ff[h][j].se.se << "\n";
        }
        return;
    }
    rec(dp[h]);
    rec(h^dp[h]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll p=0;
    for (int i = 1; i <= n; i++)
    {
        ll q;
        cin >> q;
        for (int j = 0; j < q; j++) {ll x;cin >> x;v[i].pb(x);p+=x;}
        //sort(v[i].begin(),v[i].end());
    }
    if (p%n) {cout << "No\n";exit(0);}
    s=p/n;
    for (int i = 1; i <= n; i++)
    {
        ll sum=0;
        for (int j = 0; j < v[i].size(); j++) sum+=v[i][j];
        for (int j = 0; j < v[i].size(); j++)
        {
            make(v[i][j], s-sum+v[i][j], i);
        }
    }
    for (int i = 0; i < (1<<n); i++) dp[i]=-1;
    for (int i = 1; i <= kol; i++)
    {
        //cout << q[i] << " " << pp[i] << "\n";
        if (!pp[i])
        {
            way.clear();
            for (int j = 1; j <= n; j++) tw[j]=0;
            for (int j = 1; j <= kol; j++) tt[j]=0;
            T=0;
            mask=0;
            dfs(i, i);
        }
    }
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = i; j>=0; j=(j-1)&i)
        {
            ll x=i^j;
            if (dp[x]!=-1 && dp[j]!=-1) {dp[i]=j;break;}
            if (j==0) break;
        }
        //cout << i << ": " << dp[i] << "\n";
    }

    if (dp[(1<<n)-1]==-1) {cout << "No\n";exit(0);}

    rec((1<<n)-1);

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}