#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

struct edge
{
    ll to, w;
    edge(ll to,ll w):to(to),w(w){};
};

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, p, kl[1000001];
bool T=0;
vector<short> rang[1000001];
ll kol[200001];
bool tt[1000001], tl[1000001];
vector<vector<ll> > v;
vector<ll> vv, ans;

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

bool check(vector<ll> g)
{
    vector<ll> pos(n+1);
    for (int i = 0; i < g.size(); i++) pos[g[i]]=i+1;
    for (int i = 0; i < v.size(); i++)
    {
        ll l=1e18, r=0;
        for (int j = 0; j < v[i].size(); j++)
            l=min(l,pos[v[i][j]]), r=max(r,pos[v[i][j]]);
        if (r-l+1!=v[i].size()) return false;
    }
    return true;
}

void slv(int h,int nt=0)
{
    //cout << h << " " << nt << "\n";
    vector<ll> q;
    for (int i = 1; i <= n; i++) kol[i]=kl[i], tt[i-1]=0, tl[i]=0;
    tl[nt]=1;
    ll j=n-(nt!=0);
    queue<ll> qq;
    qq.push(h);
    ll oo=0;
    while (j--)
    {
        oo++;
        if (qq.size()==0) return;
        ll x=qq.front();
        //cout << x << "\n";
        //for (int i = 0 ;i < rang[x].size(); i++) cout << rang[x][i] << " ";
        //cout << "\n";
        qq.pop();
        q.pb(x);
        tl[x]=1;
        for (int i = 0; i < v.size(); i++)
            if (!tt[i])
        {
            bool t=0;
            for (int j = 0; j < v[i].size(); j++)
                if (v[i][j]==x) {t=1;break;}
            if (t)
            {
                tt[i]=1;
                for (int j = 0; j < v[i].size(); j++)
                    if (!tl[v[i][j]])
                    {
                        kol[v[i][j]]--;
                        if (kol[v[i][j]]==1) qq.push(v[i][j]);
                    }
                break;
            }
        }
    }
    if (nt!=0) q.pb(nt);
    reverse(all(q));
    //for (int i = 0; i < q.size(); i++) cout << q[i] << " ";
    //cout << "\n";
    //for (int )
    if (check(q))
        ans=q;
}

void solve()
{
    cin >> n;
    ans.clear();
    for (int i = 1; i <= n; i++) kl[i]=0;
    v.clear();
    for (int i = 0; i < n-1; i++)
    {
        ll x;
        cin >> x;
        v.pb(vv);
        for (int j = 0; j < x; j++)
        {
            ll y;
            cin >> y;
            v[i].pb(y);
            kl[y]++;
        }
    }
    //for (int i = 1; i <= n; i++) cout << kl[i] << " ";
    //cout << "\n";
    pll par=mp(0,0);
    bool ttt=0;
    for (int i = 1; i <= n; i++) kol[i]=kl[i], tt[i-1]=0, tl[i]=1;
    for (int it = 0; it < n; it++)
    {
        vector<ll> z;
        for (int i = 1; i <= n; i++)
            if (kol[i]==1) z.pb(i);
        if (z.size()==2)
        {
            if (it==0) ttt=1;
            par=mp(z[0],z[1]);
        } else
        {
            for (int i = 0; i < v.size(); i++)
                if (!tt[i])
            {
                bool t=0;
                for (int j = 0; j < v[i].size(); j++)
                    if (v[i][j]==z[0]) {t=1;break;}
                if (t)
                {
                    tt[i]=1;
                    for (int j = 0; j < v[i].size(); j++)
                    {
                        kol[v[i][j]]--;
                    }
                }
            }
        }
    }
    //cout << " - " << par.fi << " " << par.se << "\n";
    if (ttt)
    {
        slv(par.fi,par.se);
        slv(par.se,par.fi);
    }else
    if (par.fi==0)
    {
        ll o=0;
        for (int i = 1; i <= n; i++)
            if (kl[i]==1) {o=i;break;}
        slv(o,0);
    }else
    {
        //cout << "---- ";
        ll o=0;
        for (int i = 1; i <= n; i++)
            if (kl[i]==1) {o=i;break;}
        //cout << o << "\n";
        slv(o,par.fi);
        slv(o,par.se);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 2 1 20.0
1 2 1.0 1.0 1.0 1.0
2 3 1.0 1.0 1.1 1.0
*/