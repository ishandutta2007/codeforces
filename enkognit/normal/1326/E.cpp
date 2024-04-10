#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = (1ll << 30) + 1;
//mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, T, kl = 0, m, ans, p, w, a[2000001], b[2000001], c[2000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

struct segment_tree
{
    ll d[10000001];
    int tt[5000001];

    void push(int h)
    {
        if (tt[h]!=0)
        {
            d[h*2]+=tt[h];
            tt[h*2]+=tt[h];
            d[h*2+1]+=tt[h];
            tt[h*2+1]+=tt[h];
            tt[h]=0;
        }
    }

    void update(int h,int l,int r,int x,int y,int k)
    {
        push(h);
        if (x>y) return;
        if (l==x && y==r)
        {
            d[h]+=k;tt[h]+=k;push(h);
            return;
        }
        int w=(l+r)/2;
        update(h*2,l,w,x,min(y,w),k);
        update(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x)
    {
        push(h);
        if (l==r) return d[h];
        int w=(l+r)/2;
        if (x<=w) return get(h*2,l,w,x); else return get(h*2+1,w+1,r,x);
    }

};

segment_tree g;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g.update(1,1,n,i,i,-1e9);
        c[a[i]]=i;
    }
    c[n+1]=n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    ll k=n+1;
    for (int i = 1; i <= n; i++)
    {
        while (g.d[1]<=0)
        {
            k--;
            g.update(1,1,n,c[k],c[k],1e9);
            g.update(1,1,n,1,c[k],1);
        }
        /*cout << i << " : " <<  k << "\n";
        for (int i = 1; i <= n; i++)
            cout << g.get(1,1,n,i) << " ";*/
        cout << k << " ";
        g.update(1,1,n,1,b[i],-1);
    }

    return 0;
}