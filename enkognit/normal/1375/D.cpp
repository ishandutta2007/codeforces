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

ll n, m, k, a[301301], pos[300301];
vector<ll> v[1005];

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

#define dies_from_cringe exit(0)

void solve()
{
    //cout << "----\n";
    cin >> n;
    for (int i = 0; i <= n; i++)v[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].pb(i);
    }
    ll mex=0;
    vector<ll> vv;
    for (int i = 1; i <= n; i++)
    {
        ll mex=0;
        vector<ll> q;
        for (int j = 1; j <= n; j++) q.pb(a[j]);
        sort(all(q));
        if (q[0]>0) mex=0; else
        {
            mex=q.back()+1;
            for (int i = 0; i < q.size()-1; i++)
                if (q[i]+1<q[i+1])
                {
                    mex=q[i]+1;
                    break;
                }
        }
        if (mex==0)
        {
            ll u=-1;
            for (int j = 1; j <= n; j++)
            {
                if (a[j]!=j)
                {
                    u=j;
                    break;
                }
            }
            if (u==-1) {break;}
            a[u]=0;
            vv.pb(u);
            i--;
        }else
        {
            a[mex]=mex;
            vv.pb(mex);
        }
        //for (int i = 1; i <= n; i++) cout << a[i] << " ";
        //cout << "\n";
        //system("pause");
    }

    //for (int i = 1; i <= n; i++) cout << a[i] << " ";
   // cout << "\n";

    cout << vv.size() << "\n";
    for (int i = 0; i < vv.size(); i++) cout << vv[i] << " ";
    cout << "\n";
    //cout << "-----\n";
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

/*d
1
3 3
10 1 2
5 1 1
*/