#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, a[200001], kol=1;
vector<ll> c[200001];
ll d[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

void update(int h,int l,int r,int x,ll k)
{
    if (l==r)
    {
        d[h]=max((ll)k,d[h]);
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=max(d[h*2],d[h*2+1]);
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return max(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n+2; i++) c[i].pb(0);
    ll mxx=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mxx=max(mxx, a[i]);
        c[a[i]].pb(i);
    }
    if (mxx==1)
    {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= n+2; i++) c[i].pb(n+1);
    for (int i = 1; i <= n+2; i++)
    {
        bool tt=1;
        //cout << i << " " << get(1,0,n,0,0) << "\n";
        for (int j = 0; j < c[i].size()-1; j++)
        {
            ll mx=get(1,0,n,0,c[i][j]);
            //cout << " " << mx << "\n";
            if (mx<c[i][j+1]) tt=0;
            update(1,0,n,c[i][j],c[i][j+1]);
        }
        if (tt)
        {
            cout << i << "\n";
            return;
        }
    }
    //cout << n+1;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/