#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, ans[100001], a[100001], c[100001];

struct ver
{
    ver *l, *r;
    int mn, nm, sum;
    ver():l(nullptr),r(nullptr),nm(0),mn(1),sum(0){};
};

ver *root;

void build(ver *h,ll l,ll r)
{
    h->nm=l;
    //cout << l << " " << r << "\n";
    if (l==r) return;
    ll w=(l+r)/2;
    h->l=new ver();
    h->r=new ver();
    build(h->l,l,w);
    build(h->r,w+1,r);
}

void update(ver *h,ll l,ll r,ll x,ll k)
{
    if (l==r)
    {
        h->mn=k;
        if (k==0) h->sum=1; else h->sum=0;
        return;
    }
    ll w=(l+r)/2;
    if (x<=w) update(h->l,l,w,x,k); else update(h->r,w+1,r,x,k);
    if (h->l->mn <= h->r->mn) h->mn=h->l->mn, h->nm=h->l->nm;
        else
            h->mn=h->r->mn, h->nm=h->r->nm;
    h->sum=h->l->sum+h->r->sum;
}

ll get(ver *h,ll l,ll r,ll x,ll y)
{
    if (x>y) return 0;
    if (l==x && y==r) return h->sum;
    ll w=(l+r)/2;
    return get(h->l,l,w,x,min(y,w))+get(h->r,w+1,r,max(w+1,x),y);
}

vector <pll> v;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v.pb(mp(-1,0));
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v.pb(mp(x,i));
    }
    root=new ver();
    build(root,1,n);
    sort(v.begin(),v.end());
    vector <ll> z;
    ll T=0, r=0, kl=0, e=0;
    while(kl<n)
    {
        //cout << kl << "\n";
        if (e==z.size())
        {
            pll o=mp(root->mn,root->nm);
            //cout << o.fi << " " << o.se << "\n";
            if (o.fi==1)
            {
                r++;
                //cout << r << "\n";
                T=v[r].fi;
                //cout << T << "\n";
                update(root,1,n,v[r].se,0);
                continue;
            }
            kl++;
            T+=m;
            while (r+1<v.size() && v[r+1].fi<=T)
            {
                r++, update(root,1,n,v[r].se,0);
                if (get(root,1,n,1,v[r].se-1)==0) z.pb(v[r].se);
            }
            ans[o.se]=T;
            update(root,1,n,o.se,1);
        } else
        {
            kl++;
            T+=m;
            while (r+1<v.size() && v[r+1].fi<=T)
            {
                r++, update(root,1,n,v[r].se,0);
                if (get(root,1,n,1,v[r].se-1)==0) z.pb(v[r].se);
            }
            ans[z[e]]=T;
            update(root,1,n,z[e],1);
            e++;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}