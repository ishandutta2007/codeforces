#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, ans, p, T, dist[3][200001], pr[1000001];
vector<ll> cc[200001];

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

void solve()
{
    ll a, b, c;
    cin >> n >> m >> a >> b >> c;
    vector<ll> v, pp(3);
    for (int i = 1; i <= n; i++) cc[i].clear();
    for (int i = 0; i < m; i++)
    {
        pr[i+1]=0;
        ll x;
        cin >> x;
        v.pb(x);
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        cc[x].pb(y);
        cc[y].pb(x);
    }
    sort(all(v));
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i] << " ";
        pr[i+1]=pr[i]+v[i];
    }
    //cout << "\n";
    pp[0]=a;
    pp[1]=b;
    pp[2]=c;
    //system("pause");
    for (int j = 0; j < pp.size(); j++)
    {
        set<pair<int,int> > q;
        for (int i = 1; i <= n; i++) dist[j][i]=1e18;
        dist[j][pp[j]]=0;
        q.insert(mp(0,pp[j]));
        while (q.size())
        {
            ll h=(*q.begin()).se;
            q.erase(q.begin());
            for (int i = 0; i < cc[h].size(); i++)
                if (dist[j][cc[h][i]] > dist[j][h] + 1)
                {
                    q.erase(mp(dist[j][cc[h][i]], cc[h][i]));
                    dist[j][cc[h][i]] = dist[j][h] + 1;
                    q.insert(mp(dist[j][cc[h][i]], cc[h][i]));
                }
        }
    }
    ll ans=1e18;
    for (int i = 1; i <= n; i++)
    {
        ll p1=dist[0][i], p2=dist[1][i], p3=dist[2][i];
        if (p1+p2+p3>m) continue;
        //cout << " " << i << " " << p1 << " " << p2 << " " << p3 << " : " << pr[p2] << " " << pr[p1+p3+p2] << "\n";
        ans=min(ans, pr[p2] + pr[p1+p3+p2]);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
2
3 2
10
01
01
DL
RU
UU
2 4
1111
0101
RDRD
UUUU
*/