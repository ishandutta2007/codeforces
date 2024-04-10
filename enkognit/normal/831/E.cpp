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

ll n, m, i, j, k, l, r, pb, pa1, pa2, a[200001];
string s;
ll d[500001], f[200001];

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=l;return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=(a[d[h*2]] <= a[d[h*2+1]] ? d[h*2] : d[h*2+1]);
}

void update(ll h,ll l,ll r,ll x)
{
    if (l==r) {d[h]=0;return;}
    ll w=(l+r)/2;
    if (w>=x) update(h*2,l,w,x); else update(h*2+1,w+1,r,x);
    d[h]=(a[d[h*2]] <= a[d[h*2+1]] ? d[h*2] : d[h*2+1]);
}

ll get(ll h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    ll w=(l+r)/2;
    ll o1=get(h*2,l,w,x,min(y,w)), o2=get(h*2+1,w+1,r,max(x,w+1),y);
    return a[o1]<=a[o2]?o1:o2;
}

void updf(ll h)
{
    for (int i = h; i <= 2e5; i+=(i&-i)) f[i]++;
}

ll getf(ll h)
{
    ll ans=0;
    for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
    return ans;
}

int main()
{
    //freopen("packdel.in","r",stdin);
    //freopen("packdel.out","w",stdout);
    cin >> n;
    a[0]=1e18;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    ll k=0, ans=0;
    for (int i = 0; i < n; i++)
    {
        ll o=d[1], p=get(1,1,n,k+1,n);
        if (a[o]==a[p]) o=p;
        if (o>k)
        {
            ans+=o-k-getf(o)+getf(k);
        }else
        {
            ans+=n-k-getf(n)+getf(k)+o-getf(o);
        }
        updf(o);
        update(1,1,n,o);
        k=o;
    }
    cout << ans;
}