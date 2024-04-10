#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, T, a[1000001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct segment_tree
{
    ll d[3000001];
    ll mx[3000001];
    ll tt[3000001];

    void push(int &h,int &l,int &r)
    {
        if (tt[h])
        {
            int w=(l+r)/2;
            d[h*2]=(w-l+1)*tt[h];
            d[h*2+1]=(r-w)*tt[h];
            tt[h*2]=tt[h];
            tt[h*2+1]=tt[h];
            mx[h*2]=tt[h];
            mx[h*2+1]=tt[h];
            tt[h]=0;
        }
    }

    void update_1(int h,int l,int r,int x,ll k)
    {
        push(h,l,r);
        if (l==r)
        {
            d[h]=k;
            mx[h]=k;
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update_1(h*2,l,w,x,k); else update_1(h*2+1,w+1,r,x,k);
        d[h]=d[h*2]+d[h*2+1];
        mx[h]=max(mx[h*2],mx[h*2+1]);
    }

    void update_2(int h,int l,int r,int x,int y,ll k)
    {
        if (x>y) return;
        push(h,l,r);
        if (l==x && y==r)
        {
            d[h]=((ll)(r-l+1))*(ll)k;
            mx[h]=k;
            tt[h]=k;
            return;
        }
        int w=(l+r)/2;
        update_2(h*2,l,w,x,min(y,w),k);
        update_2(h*2+1,w+1,r,max(x,w+1),y,k);
        d[h]=d[h*2]+d[h*2+1];
        mx[h]=max(mx[h*2], mx[h*2+1]);
        //cout << " :: " << l << " " << r << " " << d[h] << " = " << d[h*2] << " + " << d[h*2+1] << "\n";
    }

    ll get_pos(int h,int l,int r,ll k)
    {
        if (l==r) return l;
        int w=(l+r)/2;
        if (mx[h*2+1]>=k) return get_pos(h*2+1,w+1,r,k); else return get_pos(h*2,l,w,k);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y);
    }
};

segment_tree g;

void solve()
{
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    ll lf=1e9, k=0, ans=0;
    for (int i = 1; i <= n; i++)
    {
        ll nw=ans;
        if (s[i]=='0')
        {
            for (int j = lf; j < i; j++)
                g.update_1(1,1,n,j,k-j+lf);
            ans+=g.get(1,1,n,1,i);
            lf=1e9;
            k=0;
        }else
        {
            k++;
            ans+=k*(k+1)/2;
            lf=min(lf, (ll)i);
            ll o=0;
            //cout << " : " << g.mx[1] << " " << k << "\n";
            if (g.mx[1]>=k) o=g.get_pos(1,1,n,k);
            //cout << " " <<  o+1 << " " << lf-1 << "\n";
            g.update_2(1,1,n,o+1,lf-1,k);
            //cout << " " << lf-1 << " " <<  g.get(1,1,n,1,lf-1) << "\n";
            //cout << " - " << g.d[1] << "\n";
            ans+=g.d[1];
        }
        //cout << ans-nw << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/