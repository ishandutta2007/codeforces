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

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, a[500005];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

map<int, int> op;

void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    set<int> s;
    multiset<int> e;
    a[0]=a[1];
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
        op[a[i]]=a[i]-a[i-1];
        e.insert(a[i]-a[i-1]);
    }
    if (s.size()==0) cout << "0\n"; else
        {
            cout << *(--s.end())-*s.begin()-*(--e.end()) << "\n";
        }
    //for (auto  i : e) cout << i << " ";
    //cout << "\n";
    while (q--)
    {
        //cout << "-----\n";
        bool t;
        ll x;
        cin >> t;
        cin >> x;
        if (t==1)
        {
            auto o=s.upper_bound(x);
            if (o!=s.end())
            {
                e.erase(e.lower_bound(op[*o]));
                op[*o]=*o-x;
                e.insert(op[*o]);
            }
            ll p=0;
            if (o!=s.begin())
            {
                o--;
                p=x-*o;
            }
            op[x]=p;
            e.insert(p);
            s.insert(x);
        }else
        {
            e.erase(e.lower_bound(op[x]));
            s.erase(x);
            auto o=s.upper_bound(x);
            if (o!=s.end())
            {
                ll u=*o;
                e.erase(e.lower_bound(op[u]));
                if (o!=s.begin())
                {
                    o--;
                    op[u]=u-*o;
                    e.insert(op[u]);
                }else
                {
                    op[u]=0;
                    e.insert(0);
                }
            }
        }
        //for (auto i : e) cout << i << " ";
        //cout << "\n";
        if (s.size()==0) cout << "0\n"; else
        {
            //cout << *s.begin() << " " << *(--s.end()) << " " << *(--e.end()) << "\n";
            cout << *(--s.end())-*s.begin()-*(--e.end()) << "\n";
        }
    }
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
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/