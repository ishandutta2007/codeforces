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

ll n, m, k, a[10001];
vector<ll> c[1005];

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
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    ll kl=0;
    string d="abacaba";
    for (int i = 1; i <= n-6; i++)
    {
        bool tt=1;
        for (int j = 0; j < d.size(); j++)
        {
            tt&=(d[j]==s[i+j]);
            //if (d[j]!=s[i+j]) cout << i << " " << j << " " << d[j] << " " << s[i+j] << "\n";
        }
        //cout << i << " " << tt << "\n";
        kl+=(ll)tt;
    }
    if (kl>1)
    {
        cout << "No\n";
        return;
    }
    if (kl==1)
    {
        cout << "Yes\n";
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i]=='?') s[i]='z';
            cout << s[i];
        }
        cout << "\n";
        return;
    }
    bool u=0;
    for (int i = 1; i <= n-6; i++)
    {
        bool tt=1;
        for (int j = 0; j < d.size(); j++)
            if (s[i+j]!='?')
            {
                tt&=(d[j]==s[i+j]);
            }
        if (tt)
        {
            vector<ll> v;
            for (int j = 0; j < d.size(); j++)
                if (s[i+j]=='?') s[i+j]=d[j], v.pb(i+j);
            bool r=0;
            for (int j = max(1, i-6); j <= min((ll)i+6, n-6); j++)
                if (j!=i)
            {
                bool tt=1;
                for (int u = 0; u < d.size(); u++)
                    tt&=(s[j+u]==d[u]);
                //cout << j << " " << tt << "\n";
                if (tt) {r=1;break;}
            }
            if (!r)
            {
                u=1;
                break;
            }else
            {
                for (int j = 0; j < v.size(); j++) s[v[j]]='?';
                //cout << s << "\n";
            }
        }
    }
    if (u)
    {
        cout << "Yes\n";
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i]=='?') s[i]='z';
            cout << s[i];
        }
        cout << "\n";
        return;
    }else cout << "No\n";
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
15
asdf???c???qwer

11
abac???caba
*/