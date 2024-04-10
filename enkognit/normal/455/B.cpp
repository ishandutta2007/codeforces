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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T;
pll a[100001];
vector<pii> c[100001];
ll d[100001][30];

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

auto cmp(pii x,pii y)
{
    return x.fi>y.fi || (x.fi==y.fi && x.se<y.se);
}

ll kl=1;

void insert(string &s,int k=0,int h=1)
{
    if (k==s.size()) return;
    if (d[h][s[k]-'a']==0) d[h][s[k]-'a']=++kl;
    insert(s,k+1,d[h][s[k]-'a']);
}

bool dfs1(int h=1,int o=0)
{
    if (o==1)
    {
        for (int i = 0; i < 26; i++)
            if (d[h][i])
            {
                if (!dfs1(d[h][i],0)) return 0;
            }
        return 1;
    }else
    {
        for (int i = 0; i < 26; i++)
            if (d[h][i])
            {
                if (dfs1(d[h][i],1)) return 1;
            }
        return 0;
    }
}

bool dfs2(int h=1,int o=0)
{
    if (o==1)
    {
        bool t=0;
        for (int i = 0; i < 26; i++)
            if (d[h][i])
            {
                if (dfs2(d[h][i],0)==0) return 0;
                t=1;
            }
        if (!t) return 0; else return 1;
    }else
    {
        bool t=0;
        for (int i = 0; i < 26; i++)
            if (d[h][i])
            {
                if (dfs2(d[h][i],1)) return 1;
                t=1;
            }
        if (!t) return 1; else return 0;
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
    ll k;
    cin >> n >> k;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s);
    }
    ll p1=dfs1(), p2=dfs2();
    //cout << p1 << " " << p2 << "\n";
    if (p1 && p2) {cout << "First\n";dies_from_cringe;}
    if (p1)
    {
        if (k%2) cout << "First\n"; else cout << "Second\n";
    }else
    {
        cout << "Second\n";
    }
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/