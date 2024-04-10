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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, TT, a[300005], qq[300005], kl[300005];
bool tt[300005], tl[300005];
vector<ll> c[300005], v[300005];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}
struct dsu
{
    ll d[300005];

    void make_sets(int h)
    {
        for (int i = 1; i <= h; i++) d[i]=i;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        d[y]=x;
    }
};

dsu g;


void dfs(int h)
{
    if (tt[h])
    {
        cout << "0\n";
        exit(0);
    }
    T++;
    if (!tt[a[h]] && tl[a[h]])
    {
        cout << "0\n";
        exit(0);
    }
    tt[h]=1;
    tl[h]=1;
    if (c[h].size())
    {
        g.unite_sets(h, c[h][0]);
        dfs(c[h][0]);
    }
    tl[h]=0;
}

void dfs2(int h)
{
    tl[h]=1;
    if (a[h]!=0)
    {
        if (!tl[a[h]]) v[g.find_set(a[h])].pb(g.find_set(h)), qq[g.find_set(h)]++;
    }
    if (c[h].size())
    dfs2(c[h][0]);
    tl[h]=0;
}

void solve()
{
    cin >> n >> k;
    g.make_sets(n);
    tt[0]=1;
    ll p=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[i]=x;
        if (x==0) p=i;
    }
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        kl[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (c[i].size()>1 || kl[i]>1)
        {
            cout << "0\n";
            exit(0);
        }
    for (int i = 1; i <= n; i++)
        if (kl[i]==0)
            dfs(i);
    if (T!=n)
    {
        cout << "0\n";
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        if (kl[i]==0) dfs2(i);
   // cout << "----\n";
    set<pii> s;
    for (int i = 1; i <= n; i++)
        if (kl[i]==0) s.insert(mp(qq[g.find_set(i)], g.find_set(i)));
    vector<int> ans;
    //cout << "----\n";
    while (!s.empty())
    {
        pii x=*s.begin();
        s.erase(s.begin());
        if (x.fi>0)
        {
            cout << "0\n";
            exit(0);
        }
        ll h=x.se;
        ans.pb(h);
        while (c[h].size())
        {
            h=c[h][0];
            ans.pb(h);
        }
        for (int i = 0; i < v[x.se].size(); i++)
        {
            s.erase(mp(qq[v[x.se][i]], v[x.se][i]));
            qq[v[x.se][i]]--;
            s.insert(mp(qq[v[x.se][i]], v[x.se][i]));
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
3 2
100 100
101 101
102 102
101 101 2
105 105 2
*/