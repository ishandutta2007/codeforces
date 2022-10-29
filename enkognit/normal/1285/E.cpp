#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, r, pp, mx=-1e18, x, y, ans, d[2000001], b[300001], z[300001];
pll a[300001];
bool tt[300001], tl[300001];
string s;

void build(int h,int l,int r)
{
    if (l==r)
    {
        d[h]=0;
        return;
    }
    int w=(l+r)/2;
    build(h*2,l,w);
    build(h*2+1,w+1,r);
    d[h]=0;
}

void update(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        d[h]=k;
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
    return max(get(h*2,l,w,x,min(y,w)),get(h*2+1,w+1,r,max(x,w+1),y));
}

bool comp(pll x,pll y)
{
    return x.fi<y.fi || x.fi==y.fi && y.se<x.se;
}

int main()
{
    //freopen("loan.in","r",stdin);
    //freopen("loan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {cin >> a[i].fi >> a[i].se;tt[i]=0;tl[i]=0;z[i]=0;b[i]=0;}
        sort(a+1,a+n+1,comp);
        a[n+1].fi=1e18;
        build(1,1,n);
        //cout << "------\n";
        for (int i = 1; i <= n; i++)
        {
            int l=i, r=n;
            while (l<r)
            {
                int w=(l+r+1)/2;
                if (a[w].fi<=a[i].se) l=w; else r=w-1;
            }
            b[i]=l;
        }
        //cout << "\n";
        ll mx=0, ans=0;
        for (int i = 1; i <= n; i++)
        {
            //if (mx<b[i]) tl[i]=1;
            mx=max(mx,b[i]);
            update(1,1,n,i,b[i]);
            z[i]=b[i];
            b[i]=mx;
            if (mx==i) ans++, tt[i]=1;
            //cout << b[i] << " - " << tt[i] << " ";
        }
        //cout << "\n";
        //cout << ans << " -\n";
        ll p=ans;
        ans=0;
        for (int i = 1; i <= n; i++)
            if (b[i]>b[i-1])
            {
                ll an=p;
                if (tt[i]) an--;
                if (i>1 && tt[i-1]==0)
                {
                   if (get(1,1,n,1,i-1)<i+1) an++;
                }
                //cout << an << "\n";
                ll l=i, r=n;
                while (l<r)
                {
                    int w=(l+r+1)/2;
                    if (b[w]>b[i]) r=w-1; else l=w;
                }
                update(1,1,n,i,0);
                for (int j = i+1; j <= l; j++)
                {
                    ll o=get(1,1,n,1,j);
                    if (tt[j]==1 && o!=j) an--;
                    if (tt[j]==0 && o==j) an++;
                    //cout << a[j].fi << " " << a[j].se << " " << o << " -- " << j << "\n";
                }
                update(1,1,n,i,z[i]);
                //cout << an << " : " << l << "\n";
                ans=max(ans,an);
            }
        cout << ans << "\n";
    }
}