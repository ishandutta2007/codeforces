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

ll n, m, k, T, a[31], tt[10][10], b[31], c[31];

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

void solve()
{
    ll x, y;
    cin >> x >> y;
    for (int i = 1; i <= 6; i++)
    {
        cin >> a[i];
    }
    for (int i = 7; i <= 25; i++) a[i]=1e18;
    bool t=1;
    while (t)
    {
        t=0;
        for (int i = 1; i <= 25; i++)
            for (int j = i+1; j <= 25; j++)
            {
                ll xx=b[i]+b[j], yy=c[i]+c[j];
                if (xx<-2 || xx>2 || yy<-2 || yy>2) continue;
                if (a[tt[xx+2][yy+2]]>a[i]+a[j])
                {
                    a[tt[xx+2][yy+2]]=a[i]+a[j];
                    t=1;
                }
            }
    }
    //cout << "---\n";
    ll zn1=2, zn2=2;
    if (x==0)
    {
        ll o=0;
        if (y<0) o=a[5]; else o=a[2];
        cout << abs(y)*o << "\n";
        return;
    }
    if (y==0)
    {
        ll o=0;
        if (x<0) o=a[3]; else o=a[6];
        cout << abs(x)*o << "\n";
        return;
    }
    zn1=x/abs(x)+2;
    zn2=y/abs(y)+2;
    ll ans=min(abs(x), abs(y))*a[tt[zn1][zn2]];
    //cout << zn1 << " " << zn2 << " " << a[tt[zn1][zn2]] << "\n";
    if (abs(x)>abs(y))
    {
        ans+=a[tt[zn1][2]]*(abs(x)-abs(y));
    }else
    {
        ans+=a[tt[2][zn2]]*(abs(y)-abs(x));
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    tt[3][3]=1;
    tt[2][3]=2;
    tt[1][2]=3;
    tt[1][1]=4;
    tt[2][1]=5;
    tt[3][2]=6;
    tt[2][2]=0;
    tt[1][3]=7;
    tt[3][1]=8;
    b[1]=1;
    b[2]=0;
    b[3]=-1;
    b[4]=-1;
    b[5]=0;
    b[6]=1;
    b[7]=-1;
    b[8]=1;
    c[1]=1;
    c[2]=1;
    c[3]=0;
    c[4]=-1;
    c[5]=-1;
    c[6]=0;
    c[7]=1;
    c[8]=-1;
    ll k=8;
    for (int i = 0; i < 5; i++)
    {
        k++;
        tt[i][0]=k;
        b[k]=i-2, c[k]=-2;
        k++;
        tt[0][i]=k;
        b[k]=-2, c[k]=i-2;
        k++;
        tt[i][4]=k;
        b[k]=i-2, c[k]=2;
        k++;
        tt[4][i]=k;
        b[k]=2, c[k]=i-2;
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*

*/