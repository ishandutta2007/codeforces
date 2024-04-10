#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

ll n, m, k;
short z[86][100001];
int lst[200001];
pii bb[100001];
bool tt[100001];

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

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

vector<ll> v1, v2;

struct node
{
    node *l, *r;
    ll pr;
    node():pr(1),l(0),r(0){};
};

struct sparse_table
{
    short d[100001][17];

    void build(int h,int o)
    {
        for (int i = h; i > 0; i--)
        {
            d[i][0]=z[o][i];
            for (int j = 1, u = 2; j < 17; u*=2, j++)
            {
                if (i+u-1>h) break;
                d[i][j]=max(d[i][j-1], d[i+u/2][j-1]);
            }
        }
    }

    ll get(ll l,ll r)
    {
        //cout << " : " << l << " " << r << " " << bb[r-l+1].fi << " " << bb[r-l+1].se << " " << d[l][bb[r-l+1].se] << "\n";
        return (ll)max(d[l][bb[r-l+1].se], d[r-bb[r-l+1].fi+1][bb[r-l+1].se]);
    }
};

struct persistent_segment_tree
{
    vector<pair<node*,int> > root;

    void build(node* h,int l,int r)
    {
        if (l==r) return;
        int w=(l+r)/2;
        h->l=new node();
        h->r=new node();
        build(h->l,l,w);
        build(h->r,w+1,r);
    }

    void build_tree(int n)
    {
        root.pb(mp(new node(), 0));
        build(root.back().fi,1,n);
    }

    node* update(node *h,int l,int r,int x,ll k)
    {
        if (l==r)
        {
            node* u=new node();
            u->pr=k;
            return u;
        }
        int w=(l+r)/2;
        node* u=new node();
        if (x<=w)
        {
            u->r=h->r;
            u->l=update(h->l,l,w,x,k);
        }else
        {
            u->l=h->l;
            u->r=update(h->r,w+1,r,x,k);
        }
        u->pr=(u->l->pr*u->r->pr)%MOD;
        return u;
    }

    ll get(node* h,int l,int r,int x,int y)
    {
        if (x>y) return 1;
        //cout << l << " " << x << " " << y << " " << r << " " << h->pr << "\n";
        if (l==x && y==r) return h->pr;
        int w=(l+r)/2;
        return (get(h->l,l,w,x,min(y,w))*get(h->r,w+1,r,max(x,w+1),y))%MOD;
    }
};

persistent_segment_tree g;

sparse_table q[90];

void solve()
{
    //cout << bb[2].fi << " " << bb[2].se << "\n";
    cin >> n;
    g.build_tree(n);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ll p=sqrt(x);
        for (int j = 2; j <= p; j++)
            if (x%j==0)
            {
                ll y=lower_bound(all(v1), j)-v1.begin();
                ll p=0;
                while (x%j==0)
                {
                    x/=j;
                    p++;
                }
                z[y][i]=p;
            }
        //cout   << i << "\n";
        if (x>1)
        {
            if (x<=sqrt(2e5)) z[lower_bound(all(v1), x)-v1.begin()][i]=1;else
            if (lst[x]>0)
                g.root.pb(mp(g.update(g.update(g.root.back().fi,1,n,lst[x],1),1,n,i,x), i));else
                g.root.pb(mp(g.update(g.root.back().fi,1,n,i,x), i));
            lst[x]=i;
        }
    }
    //cout << "\n";
    //for (int i = 1; i <= n; i++) cout << z[0][i] << "\n";
    for (int i = 0; i < v1.size(); i++) q[i].build(n,i);
    ll qq=0, ls=0;
    int lr, rr;
    cin >> qq;
    while (qq--)
    {
        ll l, r;
        cin >> l >> r;
        l=(l+ls)%n+1;
        r=(r+ls)%n+1;
        if (r<l) swap(l, r);
        ll ans=1;
        //cout << "-\n";
        //cout << l << " " << r << "\n";
        for (int i = 0; i < v1.size(); i++)
        {
            //cout << i << " " << q[i].get(l,r) << "\n";
            ans=(ans*binpow(v1[i],
                            q[i].get(l,r)))%MOD;
        }
        //cout << "-\n";
        //cout << ans << "\n";
        lr=0, rr=g.root.size()-1;
        while (lr<rr)
        {
            int w=(lr+rr+1)/2;
            if (g.root[w].se<=r) lr=w; else rr=w-1;
        }
        //cout << g.root.size() << "\n";
        //cout << (nullptr==g.root[lr].fi) << "\n";
        //cout << ans << "\n";
        ans=(ans*g.get(g.root[lr].fi,1,n,l,r))%MOD;
        ls=ans;
        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 2; i <= 2e5; i++)
        if (!tt[i])
        {
            //cout << i << " " << bb[2].fi << " " << bb[2].se << "\n";
            if (i<=sqrt(2e5)) v1.pb(i);
            ll j=i*i;
            while (j<=2e5) tt[j]=1, j+=i;
        }
    ll o=0, u=-1;
    for (int i = 1; i <= 1e5; i++)
    {
        if (i/2==o) o=i, u++;
        bb[i]=mp(o, u);
    }

    //cout << bb[2].fi << " " << bb[2].se << "\n";
    //cout << v1.size() << "\n";
    //cout << v2.size() << "\n";
    solve();
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/