#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, T, m, kl1, kl2, lk1, lk2;
vector<int> q1, q2;
bool tt[1000001], tl[1000001];
vector<pii> z;

struct segment_tree
{
    pair<pii, pii> d[1000001];

    pair<pii, pii> upd(pair<pii, pii> x,pair<pii, pii> y)
    {
        pair<pii,pii> h;
        if (x.fi.fi<y.fi.fi) h.fi=x.fi; else h.fi=y.fi;
        if (x.se.fi>y.se.fi) h.se=x.se; else h.se=y.se;
        return h;
    }

    void build(int h,int l,int r)
    {
        if (l==r)
        {
            d[h]=mp(mp(1e9, -1), mp(-1e9, -1));
            return;
        }
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=upd(d[h*2],d[h*2+1]);
    }

    pair<pii,pii> get(int h,int l,int r,int x,int y)
    {
        if (x>y) return mp(mp(1e9, -1), mp(-1e9, -1));
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return upd(get(h*2,l,w,x,min(y,w)), get(h*2+1,w+1,r,max(x,w+1),y));
    }

    void update(int h,int l,int r,int x,pii k)
    {
        if (l==r)
        {
            if (k.se==-1) d[h]=mp(mp(1e9, -1),mp(-1e9, -1)); else d[h]=mp(k, k);
            return;
        }
        int w=(l+r)/2;
        if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
        d[h]=upd(d[h*2],d[h*2+1]);
    }
} g1, g2, g3;

void dfs(int h,int k)
{
    //cout << h << " " << k << "-\n";
    g1.update(1,1,n,z[h].fi,mp(-1,-1));
    tl[h]=1;
    if (k==1)
    {
        if (tt[z[h].fi]) kl1++; else lk1++;
        if (g2.get(1,1,n,z[h].fi+1,n).se.fi>z[h].se || g2.get(1,1,n,1,z[h].fi-1).fi.fi<z[h].se)
        {
            cout << "-1\n";
            exit(0);
        }

        g2.update(1,1,n,z[h].fi,mp(z[h].se, h));
        q1.pb(z[h].fi);

        while (1)
        {
            pll o=g1.get(1,1,n,z[h].fi+1,n).se;
            //cout << " " << o.fi << " " << o.se << "\n";
            if (o.fi<z[h].se) break;
            dfs(o.se, 2);
        }


        while (1)
        {
            pll o=g1.get(1,1,n,1,z[h].fi-1).fi;
            //cout << " " << o.fi << " " << o.se << "\n";
            if (o.fi>z[h].se) break;
            dfs(o.se, 2);
        }
    }else
    {
        if (!tt[z[h].fi]) kl2++;else lk2++;
        if (g3.get(1,1,n,z[h].fi+1,n).se.fi>z[h].se || g3.get(1,1,n,1,z[h].fi-1).fi.fi<z[h].se)
        {
            cout << "-1\n";
            exit(0);
        }

        g3.update(1,1,n,z[h].fi,mp(z[h].se, h));
        q2.pb(z[h].fi);

        while (1)
        {
            pll o=g1.get(1,1,n,z[h].fi+1,n).se;
            //cout << " " << o.fi << " " << o.se << "\n";
            if (o.fi<z[h].se) break;
            dfs(o.se, 1);
        }

        while (1)
        {
            pll o=g1.get(1,1,n,1,z[h].fi-1).fi;
            //cout << " " << o.fi << " " << o.se << "\n";
            if (o.fi>z[h].se) break;
            dfs(o.se, 1);
        }
    }
    //cout << "---\n";
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x>y) swap(x, y), tt[x]=1;
        z.pb(mp(min(x, y), max(x, y)));
    }
    sort(all(z));
    ll mn=1e18;
    for (int i = 0; i < z.size(); i++)
    {
        if (mn<z[i].fi)
        {
            cout << "-1\n";
            return;
        }
        mn=min(mn, (ll)z[i].se);
    }

    g1.build(1,1,n);
    g2.build(1,1,n);
    g3.build(1,1,n);

    for (int i = 0; i < z.size(); i++)
    {
        g1.update(1,1,n,z[i].fi,mp(z[i].se, i));
        //cout << z[i].fi << " " << z[i].se << "\n";
    }

    ll ans=0;
    for (int i = 0; i < z.size(); i++)
        if (!tl[i])
        {
            kl1=0;kl2=0;
            lk1=0;lk2=0;
            while (q1.size())
            {
                g2.update(1,1,n,q1.back(),mp(0, -1));
                q1.pop_back();
            }

            while (q2.size())
            {
                g3.update(1,1,n,q2.back(),mp(0, -1));
                q2.pop_back();
            }
            dfs(i, 1);
            ans+=min(kl1+kl2, lk1+lk2);
        }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*

*/