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

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-12;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n, m, z[300005];
bool tt[300005];
vector<ll> ans;
pii pr[300005];
vector<bool> vv;

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

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

struct node
{
    node *L, *R;
    vector<pair<pll,int> > v;
    node():v({mp(mp(-1e9-1,-1e9-1),-1)}),L(nullptr),R(nullptr){};
};

ll gt(ll x,pll f)
{
    if (f.fi==-1e9-1 || f.se==-1e9-1) return -3e18;
    return f.fi*x+f.se;
}

struct Li_Chao_Tree
{
    node *root;

    void insert(pll f,int nm,node *h,int l=-1e9,int r=1e9+1)
    {
        //cout << l << " " << r << "\n";
        int w=(l+r)/2;
        bool t1=(gt(l,f)>gt(l,h->v.back().fi));
        bool t2=(gt(w,f)>gt(w,h->v.back().fi));
        if (t2)
        {
            h->v.pb(mp(f,nm));
            t1=!t1;
            f=h->v[h->v.size()-2].fi;
        }
        if (r-l==1) return;
        if (t1)
        {
            vv.pb(0);
            if (h->L==nullptr) h->L=new node();
            insert(f,nm,h->L,l,w);
        }else
        {
            vv.pb(1);
            if (h->R==nullptr) h->R=new node();
            insert(f,nm,h->R,w,r);
        }
    }

    ll get(int x,node *h,int l=-1e9,int r=1e9+1)
    {
        //cout << "   " << l << " " << r << " " << h->v.back().fi.fi << " " << h->v.back().fi.se << "\n";
        if (r-l==1) return gt(x,h->v.back().fi);
        int w=(l+r)/2;
        ll o=-1e18;
        if (x<w && h->L!=nullptr) o=get(x,h->L,l,w);
        if (x>=w && h->R!=nullptr) o=get(x,h->R,w,r);
        return max(o, gt(x,h->v.back().fi));
    }

    void erase(int nm,int k,vector<bool> &v,node *h,int l=-1e9,int r=1e9+1)
    {
        int w=(l+r)/2;
        if (h->v.back().se==nm) h->v.pop_back();
        if (r-l==1 || k==v.size()) return;
        if (v[k]==0) erase(nm,k+1,v,h->L,l,w); else
        if (v[k]==1) erase(nm,k+1,v,h->R,w,r);
    }
};

Li_Chao_Tree g;
ll T=0;

vector<pair<pii,int> > d[2000005];

vector<ll> w;

void update(int h,int l,int r,int x,int y,pll f,int xx)
{
    if (x>y) return;
    //cout << l << " " << r << " " << x << " " << y << "\n";
    if (l==x && y==r)
    {
        d[h].pb(mp(f,xx));
        return;
    }
    int w=(l+r)/2;
    update(h*2,l,w,x,min(y,w),f,xx);
    update(h*2+1,w+1,r,max(x,w+1),y,f,xx);
}

void dfs(int h,int l,int r)
{
    //cout << h << " " << l << " " << r << "\n";
    vector<vector<bool> > qq;
    for (int i = 0; i < d[h].size(); i++)
    {
        //cout << " " << i << " : " << d[h][i].fi.fi << " " << d[h][i].fi.se << " " << d[h][i].se << "\n";
        g.insert(d[h][i].fi,d[h][i].se,g.root);
        qq.pb(vv);
        T++;
        vv.clear();
    }

    if (l<r)
    {
        int w=(l+r)/2;
        dfs(h*2,l,w);
        dfs(h*2+1,w+1,r);
    }else
    if (l==r && l<w.size())
    {
        ll p=g.get(w[l],g.root);
        //cout << "  " << l << " " << w[l] << " " << p << "\n";
        if (T==0) tt[ans.size()]=1;
        ans.pb(p);
    }

    for (int i = d[h].size()-1; i > -1; i--)
    {
        g.erase(d[h][i].se,0,qq.back(),g.root);
        qq.pop_back();
        T--;
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
    cin >> n;
    ll kl=0;
    g.root=new node();
    vector<pll> fnc;
    w.pb(-1);
    //ll kl1=0, kl2=0, kl3=0, TT=0;
    for (int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll k, b;
            cin >> k >> b;
            //if (i==1 && k==-305823393) TT=1;
            fnc.pb(mp(k,b));
            z[i]=kl;
            pr[kl]=mp(w.size(),1e9);
            kl++;
        }else
        if (t==2)
        {
            ll o;
            cin >> o;
            pr[z[o]].se=w.size()-1;
        }else
        {
            ll q;
            cin >> q;
            w.pb(q);
        }
    }
    //for (int i = 1; i < w.size(); i++) cout << w[i] << " ";
    //cout << "\n";
    if (w.size()==0)
    {
        //cout << "----\n";
        exit(0);
    }
    for (int i = 0; i < fnc.size(); i++)
    {
        //cout << i << "\n";
        update(1,1,w.size()-1,pr[i].fi,min((ll)pr[i].se,(ll)w.size()-1),fnc[i],i);
    }
    //cout << "----\n";
    dfs(1,1,w.size()-1);
    //if (TT) cout << kl1 << " " << kl2 << " " << kl3 << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (tt[i]) cout << "EMPTY SET\n"; else cout << ans[i] << "\n";
    }
    return 0;
}

/*
8 2
2 2 2 2 2 2 2 2
1 2

*/