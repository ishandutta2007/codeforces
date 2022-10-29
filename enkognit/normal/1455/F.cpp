#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ii, jj;
char nx[200];
string dp[502];

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

void solve()
{
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        if (i==0) nx[i+'a']='a'; else
        if (i==m-1) nx[i+'a']='a'; else nx[i+'a']=(i-1+'a');
        //cout << " " << i << " " << nx[i+'a'] << "\n";
    }
    for (int i = 1; i <= n; i++) dp[i]="{";
    //cout << ("a"<dp[1]) << "\n";
    for (int i = 0; i < n; i++)
    {
        //cout << i << " : " << dp[i] << "\n";
        string u="";
        {
            u=dp[i];
            u+=nx[s[i]];
            if (dp[i+1]>u) dp[i+1]=u;
        }
        if (i+1<n)
        {
            u=dp[i];
            u+=nx[s[i+1]];
            u+=s[i];
            if (dp[i+2]>u) dp[i+2]=u;
            if (i>0)
            {
                u=dp[i];
                char c=dp[i].back();
                u.pop_back();
                u+=s[i+1];
                u+=c;
                u+=s[i];
                if (dp[i+2]>u) dp[i+2]=u;
            }
        }
        if (i>0)
        {
            char c=dp[i].back();
            u=dp[i];
            u.pop_back();
            u+=s[i];
            u+=c;
            if (dp[i+1]>u) dp[i+1]=u;
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/