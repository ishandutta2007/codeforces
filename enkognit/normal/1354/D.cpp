#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const ll INF=1e18;
const ld E=1e-8;
const ld pi=acos(-1);
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, ans;
string s;

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

/*struct node
{
    node *l, *r;
    int x, y;
    int kl;
    node(int x,int y):x(x),y(y),kl(1),l(nullptr),r(nullptr){};
};

struct DD
{
    node *root;

    ll get(node *h)
    {
        return (h==nullptr?0:h->kl);
    }

    void upd(node *h)
    {
        h->kl=1+get(h->l)+get(h->r);
    }

    node* merge(node* L,node* R)
    {
        if (L==nullptr) return R;
        if (R==nullptr) return L;
        if (L->y>R->y)
        {
            L->r=merge(L->r,R);
            upd(L);
            return L;
        }else
        {
            R->l=merge(L,R->l);
            upd(R);
            return R;
        }
    }

    pair<node*,node*> split(node *h,int key)
    {
        if (h==nullptr) return mp(nullptr,nullptr);
        if (h->x<=key)
        {
            auto tt=split(h->r,key);
            h->r=tt.fi;
            upd(h);
            return mp(h,tt.se);
        }else
        {
            auto tt=split(h->l,key);
            h->l=tt.se;
            upd(h);
            return mp(tt.fi,h);
        }
    }

    void insert(int x)
    {
        ll o=rnd()%MOD;
        node* q=new node(x, o);
        auto w=split(root,x);
        root=merge(w.fi,merge(q,w.se));
        upd(root);
    }

    void erase(int x)
    {
        auto w=split(root,x);
        auto q=split(w.fi,x-1);
        q.se=merge(q.se->l,q.se->r);
        root=merge(merge(q.fi,q.se),w.se);
    }

    ll get(node *h,int k)
    {
        if (get(h->l)+1==k) return h->x; else
        if (get(h->l)+1>k) return get(h->l,k); else
        return get(h->r,k-get(h->l)-1);
    }
};

DD g;*/

int d[4000001];

void upd(int h,int l,int r,int x)
{
    if (l==r) {d[h]++;return;}
    int w=(l+r)/2;
    if (x<=w) upd(h*2,l,w,x); else upd(h*2+1,w+1,r,x);
    d[h]=d[h*2]+d[h*2+1];
}

void del(int h,int l,int r,int x)
{
    if (l==r) {d[h]--;return;}
    int w=(l+r)/2;
    if (d[h*2]>=x) del(h*2,l,w,x); else del(h*2+1,w+1,r,x-d[h*2]);
    d[h]=d[h*2]+d[h*2+1];
}

ll get(int h,int l,int r)
{
    if (l==r) return l;
    int w=(l+r)/2;
    if (d[h*2]>0) return get(h*2,l,w); else return get(h*2+1,w+1,r);
}

int main()
{
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        //g.insert(x);
        upd(1,1,n,x);
    }
    for (int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if (x>0)
        {
            //g.insert(x);
            upd(1,1,n,x);
            //n++;
        }else
        {
            //g.er
            del(1,1,n,-x);
            //n--;
        }
    }
    if (d[1]==0) cout << "0\n"; else cout << get(1,1,n) << "\n";
    return 0;
}