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

ll n, m, a[200005];
vector<ll> pos[200005];

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
    cin >> n;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb(mp(a[i],i));
    }
    sort(all(v));
    ll kk=0;
    for (int i = 0; i < v.size(); i++)
    {
        kk++;
        if (i>0 && v[i-1].fi==v[i].fi)kk--;
        a[v[i].se]=kk;
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]].pb(i);
        ans=max(ans,(ll)pos[a[i]].size());
        //cout << a[i] << " ";
    }
    //cout << "\n";
    ll k=0;
    for (int i = 1; i <= n+1; i++)
        if (pos[i].size()==0) {k=i-1;break;}
    //if (k==1) {cout << n-ans << "\n";return;}
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < pos[i].size(); j++)
        {
            ll p=upper_bound(all(pos[i+1]),pos[i][j])-pos[i+1].begin();
            ans=max(ans,j+1+(ll)pos[i+1].size()-p);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        ll j=i, q=pos[i].size();
        while (j+1<=k && pos[j+1][0]>pos[j].back()) j++, q+=pos[j].size();
        //cout << i << " " << j << "\n";
        if (i>1)
        {
            ll o1=upper_bound(all(pos[i-1]), pos[i][0])-pos[i-1].begin()-1;
            q+=o1+1;
            //cout << pos[i-1][o1] << "\n";
        }
        if (j<k)
        {
            ll o2=upper_bound(all(pos[j+1]), pos[j].back())-pos[j+1].begin();
            q+=pos[j+1].size()-o2;
        }
        ans=max(ans,q);
        i=j;
    }
    for (int i = 1; i <= n; i++) pos[i].clear();
    cout << n-ans << "\n";
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
8 2
2 2 2 2 2 2 2 2
1 2

*/