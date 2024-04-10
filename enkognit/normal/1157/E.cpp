#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, T, a[300001], d[2000001], g[2000001];
vector <ll> b;

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=b[l];g[h]=b[l];return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=min(d[h*2],d[h*2+1]);
    g[h]=max(g[h*2],g[h*2+1]);
}

ll get(ll h,ll l,ll r,ll k)
{
    if (l==r) {return g[h];}
    ll w=(l+r)/2;
    if (g[h*2]<k) return get(h*2+1,w+1,r,k); else return get(h*2,l,w,k);
}

void update2(ll h,ll l,ll r,ll k)
{
    if (l==r) {g[h]=-1;d[h]=1e18;return;}
    ll w=(l+r)/2;
    if (g[h*2]<k) update2(h*2+1,w+1,r,k); else update2(h*2,l,w,k);
    d[h]=min(d[h*2],d[h*2+1]);
    g[h]=max(g[h*2],g[h*2+1]);
}

void update(ll h,ll l,ll r)
{
    if (l==r) {g[h]=-1;d[h]=1e18;return;}
    ll w=(l+r)/2;
    if (d[h]==d[h*2]) update(h*2,l,w); else update(h*2+1,w+1,r);
    d[h]=min(d[h*2],d[h*2+1]);
    g[h]=max(g[h*2],g[h*2+1]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        b.pb(x);
    }
    sort(b.begin(),b.end());
    build(1,0,n-1);
    vector <ll> ans;
    for (int i = 0; i < n; i++)
    {
        ll p=n-a[i];
        if (g[1]<p || d[1]>=p) ans.pb((a[i]+d[1])%n),update(1,0,n-1); else
        {
            ll o=get(1,0,n-1,p);
            //cout << o << " " << p << "\n";
            if ((o+a[i])%n>(d[1]+a[i])%n) ans.pb((a[i]+d[1])%n), update(1,0,n-1); else
            ans.pb((a[i]+o)%n), update2(1,0,n-1,p);
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}