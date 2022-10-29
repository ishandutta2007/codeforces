#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, j, k, l, r, a[1001], dp1[100001], dp2[100001], d[100001];
ll t[301];

void solve()
{
    vector <ll> dp;
    dp.pb(0);
    for (int i = 0; i < n*m; i++)
    {
        ll l=0, r=dp.size()-1;
        while (l<r)
        {
            ll w=(l+r)/2+(l+r)%2;
            if (dp[w]<=a[i%n]) l=w; else r=w-1;
        }
        if (l==dp.size()-1) dp.pb(a[i%n]); else dp[l+1]=min(dp[l+1], a[i%n]);
    }
    cout << dp.size()-1 << "\n";
    exit(0);
}

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=l;return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    if (t[d[h*2]]<t[d[h*2+1]]) d[h]=d[h*2+1]; else d[h]=d[h*2];
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x > y) return 0;
    if (l == x && y == r) return d[h];
    ll w = (l + r) / 2;
    ll o1 = get(h * 2, l, w, x, min(y, w)), o2 = get(h * 2 + 1, w + 1, r, max(x,w+1), y);
    if (t[o1]>t[o2]) return o1; else return o2;
}

int main()
{
    //freopen("packdel.in","r",stdin);
    //freopen("packdel.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {cin >> a[i];t[a[i]]++;ans=max(ans,t[a[i]]*m);}
    if (m<n*2)solve();
    build(1,1,300);
//cout << 1;
    if (m==1) solve();
    vector <ll> v1, v2;
    v1.pb(0);
    v2.pb(0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++) v1.pb(a[i]);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++) v2.pb(a[i]);
    m-=n*2;
    m=max(m,0ll);
    //cout << v.size() << "\n";
    //cout << 1 << "\n";
    for (int i = 1; i <= n*n; i++)
    {
        dp1[i]=1;
        for (int j = i-1; j > 0; j--) if (v1[j]<=v1[i]) {dp1[i]=max(dp1[i], dp1[j]+1);}
    }

    for (int i = n*n; i > 0; i--)
    {
        dp2[i]=1;
        for (int j = i+1; j <= n*n; j++) if (v2[j]>=v2[i]) dp2[i]=max(dp2[i], dp2[j]+1);
    }



    for (int i = n*(n-1); i <= n * n; i++)
        for (int j = 1; j <= n; j++)
            if (v1[i]<=v2[j])
            {
                //cout << i << " " << j << "\n";
                ll p=0;
                for (int u = v1[i]; u <= v2[j]; u++)if (t[p]<t[u]) p=u;
                //cout << 1;
                //cout << i << " " << j << " " << p << " " << dp1[i]+dp2[j]+t[p]*m << "\n";
                ans=max(dp1[i]+dp2[j]+t[p]*m, ans);
            }
    cout << ans;
}
/*
4 9
4 2
4 5
3 4
2 10
*/