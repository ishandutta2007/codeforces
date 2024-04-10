#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define y1 Enkognit
#define ld long double
#define pii pair<int,int>

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll INF=1e18;
const ll MOD=1e9+7;

template<typename T>
using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, l, r, a[1000001];
bool tt[100001], tl[1000001];
string s;

struct node
{
    node *l, *r;
    ll kl=0;
    node(int p=0):l(nullptr),r(nullptr),kl(p){};
};

struct segment_tree
{
    node *root;

    void build(node *h,int l,int r)
    {
        if (l==r)
        {
            h->kl=0;
            return;
        }
        int w=(l+r)/2;
        h->l=new node();
        h->r=new node();
        build(h->l,l,w);
        build(h->r,w+1,r);
        h->kl=0;
    }

    void update(node *h,int l,int r,int x,int k)
    {
        if (l==r) {h->kl=k;return;}
        int w=(l+r)/2;
        if (x<=w) update(h->l,l,w,x,k); else update(h->r,w+1,r,x,k);
        h->kl=h->l->kl+h->r->kl;
    }

    ll get(node *h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return h->kl;
        int w=(l+r)/2;
        return get(h->l,l,w,x,min(y,w))+get(h->r,w+1,r,max(x,w+1),y);
    }
};

ll binpow(ll h,ll r,ll md=MOD)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n;
    vector<ll> v;
    ll op=0, len=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        op++;
        tt[i]=x;
    }
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        tl[i]=x;
        len++;
    }

    ll o=0, l=0, k=0;
    for (int i = 1; i <= n; i++)
    {
        if (tt[i] && !tl[i]) k++; else
        if (!tt[i] && tl[i]) l++;
    }
    if (k==0) cout << -1; else
    if (k>l) cout << 1; else
    {
        ll z=0;
        //cout << l << " " << k << "\n";
        z=(l-k)/k+1;
        cout << 1+z << "\n";
    }
}

int main()
{
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