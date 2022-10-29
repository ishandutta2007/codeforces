#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pi 3.14159265358979323846

using namespace std;

ll n, m, j, o, l, k, r, x, y, a[300002];pll d[1000001];
vector <ll> v;
bool t[1000001],tt;
vector <ll> ans;

void build(ll h,ll l,ll r)
{
    if (l==r) {d[h]=mp(a[l],0);return;}
    ll w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    if (d[h*2].se==0) d[h]=mp(d[h*2].fi | d[h*2+1].fi,1); else d[h]=mp(d[h*2].fi ^ d[h*2+1].fi,0);
}

void update(ll h,ll l,ll r,ll x,ll y)
{
    if (l==r) {d[h].fi=y;return;}
    ll w=(l+r)/2;
    if (x<=w)update(h*2,l,w,x,y); else update(h*2+1,w+1,r,x,y);
    if (d[h*2].se==0) d[h]=mp(d[h*2].fi | d[h*2+1].fi,1); else d[h]=mp(d[h*2].fi ^ d[h*2+1].fi,0);
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    n=pow(2,n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    //cout << d[1].fi << "\n";
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        update(1,1,n,x,y);
        cout << d[1].fi << "\n";
    }
    //cout << ((4^6)|(3^5));
    return 0;
}
/*
4 3
1 2 3 4
1 2
2 3
3 4
*/