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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld E = 1e-8;
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 29, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, a[100001], pls[100001], ans[100001];
int tt[100001];
vector<ll> v[100001];
int intr[317][100001];
bool tf[317][100001];
vector<ll> w;

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

struct dsu
{
    ll d[200001];

    void make_set(int h)
    {
        d[h]=h;
    }

    ll find_set(int h)
    {
        if (h==d[h]) return h; else return d[h]=find_set(d[h]);
    }

    void unite_sets(int x,int y)
    {
        x=find_set(x);
        y=find_set(y);
        if (x<y) swap(x,y);
        d[x]=y;
    }
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll p=sqrt(n);
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (p<x)
        {
            tt[i]=w.size();
            w.pb(i);
            //cout << i << " " << tt[i] << "\n";
        }else tt[i]=-1;
        for (int j = 0; j < x; j++)
        {
            ll y;
            cin >> y;
            v[i].pb(y);
            if (tt[i]!=-1) {tf[w.size()-1][y]=1; ans[tt[i]]+=a[y];}
        }
    }
    //cout << ans[0] << "\n";
    //cout << w.size() << "\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < w.size(); j++)
            for (int u = 0; u < v[i].size(); u++)
                intr[j][i]+=tf[j][v[i][u]];
    //cout << "------\n";
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c=='+')
        {
            ll x, y;
            cin >> x >> y;
            x--;
            if (tt[x]!=-1)
            {
                pls[x]+=y;
            }else
            {
                for (int i = 0; i < v[x].size(); i++) a[v[x][i]]+=y;
                for (int i = 0; i < w.size(); i++)
                    ans[i]+=y*intr[i][x];
            }
        }else
        {
            ll x, y;
            cin >> x;
            x--;
            if (tt[x]!=-1)
            {
                ll an=ans[tt[x]];
                for (int i = 0; i < w.size(); i++)
                    an+=intr[i][x]*pls[w[i]];
                cout << an << "\n";
            }else
            {
                ll an=0;
                for (int i = 0; i < v[x].size(); i++) an+=a[v[x][i]];
                for (int i = 0; i < w.size(); i++)
                    an+=intr[i][x]*pls[w[i]];
                cout << an << "\n";
            }
        }
    }
    return 0;
}

/*

*/