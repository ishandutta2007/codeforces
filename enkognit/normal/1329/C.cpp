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


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, h, g, T, Q, a[8000001];

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

void dlt(int h)
{
    a[h]=max(a[h*2],a[h*2+1]);
    if (a[h*2]==0 && a[h*2+1]==0) return;
    if (a[h*2]>a[h*2+1]) dlt(h*2); else dlt(h*2+1);
}

bool dfs(int h)
{
    if (h==0) return 0;
    if (h>=(1<<g)) return 1;
    if (a[h*2]==0 && a[h*2+1]==0) return 0;
    if (a[h*2]>a[h*2+1]) return dfs(h*2); else return dfs(h*2+1);
}

void solve()
{
    cin >> h >> g;
    for (int i = 1; i < (1<<h); i++) cin >> a[i];
    ll nw=1;
    queue<ll> q;
    vector<ll> v;
    for (int i = (1<<g); i < (1<<h); i++)
    {
      //  cout << nw << "\n";
        if (nw<1 || nw>=(1<<h)) while(1);
        if (dfs(nw))
        {
            v.pb(nw);
            dlt(nw);
        }else
        {
            i--;
            ll l=nw*2, r=l+1;
            if (l<(1<<g)) {q.push(l);}
            if (r<(1<<g)) {q.push(r);}
            nw=q.front();
            q.pop();
        }
    }
    ll ans=0;
    for (int i = 1; i < (1<<g); i++) ans+=a[i];
    cout << ans << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
    for (int i = 1; i < (1<<h); i++) a[i]=0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
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