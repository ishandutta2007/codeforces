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
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kol=0, T=0, mask, d[1000001];
vector <ll> vl, vr;
vector <pll> c[200001];
set<pii > s;
vector <ll> v;
bool tt[1000001], w[1000001];

void push(int h)
{
    if (!tt[h])
    {
        d[h*2]=min(d[h*2],d[h]);
        d[h*2+1]=min(d[h*2+1],d[h]);
        d[h]=1e18;
    }
}

void build(int h,int l,int r)
{
    if (l==r)
    {
        if (l==0) d[h]=0; else d[h]=1e18;
        tt[h]=1;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=1e18;
}

void update(int h,int l,int r,int x,int y,ll k)
{
    //if (k==0) {cout << x << " " << y << "\n";}
    push(h);
    if (x>y) return;
    if (l==x && y==r)
    {
        d[h]=min(k,d[h]);
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(w,y),k);
    update(h*2+1,w+1,r,max(w+1,x),y,k);
}

ll get(int h,int l,int r,ll x)
{
    push(h);
    if (l==r) return d[h];
    int w=(l+r)/2;
    if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    v.pb(0);
    for (int i = s.size()-1; i > -1; i--) if (s[i]=='1') v.pb(s.size()-i);
    v.pb(n+1);
    build(1,0,n);
    //cout << get(1,0,n,n);
    for (ll i = 0; i < n; i++)
    {
        ll o=get(1,0,n,i);
        //cout << o << " ";
        update(1,0,n,i+1,i+1,o+n-i);
        ll p=upper_bound(v.begin(),v.end(),min(i+m+1,n))-v.begin();
        p--;
        //if (i==0) cout << v[p] << "\n";
        if (v[p]>i && v[p]-i<=m+1 && v[p]!=n+1)update(1,0,n,i+1,min(v[p]+m,n),o+n-v[p]+1), p++;

    }
    cout << get(1,0,n,n);
    return 0;
}
/*
3
3 5
HHR
1 2 3
1 2 5
1 3 10
3 2 0
3 1 7
2 2
RR
1 2 1
2 1 2
3 3
HRR
1 2 1
1 3 2
2 3 3
*/