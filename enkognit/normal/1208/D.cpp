#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[1000001], b[1000001];
vector <ll> v, z;
string s;
ll tt[3000001];
ll d[3000001];

void push(ll h)
{
        tt[h*2]+=tt[h];
        tt[h*2+1]+=tt[h];
        d[h*2]+=tt[h];
        d[h*2+1]+=tt[h];
        tt[h]=0;
}

void build(ll h,ll l,ll r)
{
    if (l==r)
    {
        d[h]=l*(l-1)/(2ll);
        return;
    }
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(ll h,ll l,ll r,ll x)
{
    push(h);
    if (l==r){return l;}
    ll w=(l+r)/2;
    if (d[h*2]>=x) return get(h*2,l,w,x);else
    return get(h*2+1,w+1,r,x);
}

void upd(ll h,ll l,ll r,ll x)
{
    push(h);
    if (l==r){d[h]=-1e15;return;}
    ll w=(l+r)/2;
    if (x<=w) upd(h*2,l,w,x); else upd(h*2+1,w+1,r,x);
    d[h]=max(d[h*2],d[h*2+1]);
}

void update(ll h,ll l,ll r,ll x,ll y,ll k)
{
    push(h);
    //cout << x << " " << y << "\n";
    if (x>y) return;
    if (l==x && y==r)
    {
        tt[h]-=k;
        d[h]-=k;
        push(h);
        return;
    }
    ll w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),k);
    update(h*2+1,w+1,r,max(x,w+1),y,k);
    d[h]=max(d[h*2],d[h*2+1]);
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    for (int i = n-1; i > -1; i--)
    {
        ll p=get(1,1,n,a[i]);
        b[i]=p;
        //cout << p << "\n";
        upd(1,1,n,p);
        //cout << p << "\n";
        update(1,1,n,p+1,n,p);
        //cout << p << "\n";
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}