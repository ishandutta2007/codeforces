/* codificador10 - Ayush Raj */

// ->Subscribe to my youtube channel
// https://www.youtube.com/watch?v=dQw4w9WgXcQ

#pragma region
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds; // find_by_order, order_of_key
using namespace std;

#ifndef ONLINE_JUDGE
#include "crazybarcafan.hpp"
#else
#define print(...)
#define debug(...)
#endif
// clang-format off
#define int long long
#define ll			 long long
#define lld			 long double
#define nline			 '\n'
#define vii			 vector<int>
#define vvii			 vector<vector<int>>
#define pii			 pair<int, int>
#define mii			 map<int, int>
#define sii			 set<int>
#define msii			 multiset<int>
#define pqi			 priority_queue<int>
#define MOD			 998244353
#define mod 		 1000000007
#define ff			 first
#define ss			 second
#define pb			 push_back
#define sz(x)			 ((int)(x).size())
#define all(x)			 (x).begin(), (x).end()
#define mem(x,y)		 memset(x,y,sizeof(x))
#define modulo(x,y) 		 x%y<0 ? x%y+y : x%y;
#define rep(i, a, b)		 for (int i = a; i < b; i++)
#define rrep(i, a, b)		 for (int i = b - 1; i >= a; i--)
#define setbits(x) 		 __builtin_popcount(x)ie. popcountll for LL
#define leadzero(x)		 __builtin_clz(x) //31/63-leadzero = pos of MSB
#define trailzero(x)		 __builtin_ctz(x)
#define parity(x)  		 __builtin_parity(x)
#define google(x)		 cout << "Case #" << x << ": ";
#define precision		 cout << setprecision(10) << fixed
#define pbds			 tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define sayian			 ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
/*-----------------------------------------------FUNCTIONS----------------------------------------------------*/

template<typename T1>istream& operator>>(istream& in,vector<T1>&a){for(auto &it:a){in>>it;};return in;}
template<typename T1>ostream& operator<<(ostream& out,vector<T1>&a){for(auto &it:a){out<<it<<" ";}return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template<class T> void ix1( vector<T>&a){rrep(i,1,sz(a)){a[i]=a[i-1];};a[0]=0;}
template <class T> T gcd(T a,T b){while(a != 0){T temp = a; a = b%a; b=temp;}return b;}
template <class T> T egcd(T a,T b,T &x,T &y){T gcd,xt,yt;if(a==0){gcd = b;x = 0,y=1;}\
else {gcd = egcd(b%a ,a ,xt ,yt);x = yt-(b/a)*xt; y=xt;}return gcd;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}
template <class T> T expo(T base,T exp,T modd){T res=1;base=base%modd;\
while(exp>0){if (exp&1)res =(res*base)%modd;exp=exp>>1;base=(base*base)%modd;}return res;}
template <class T> T modinv(T a,T modd){T x,y; egcd<T>(a,modd,x,y);while(x<0) x+=modd;\
 while(x>=modd) x -= modd; return x;}
template <class T> T modinvfermat(T a,T modd){return expo<T>(a,modd-2,modd);}
        int32_t dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
        int32_t dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

const int32_t N = 1e5+5;
const int32_t inf = 1e9;

// clang-format on
#pragma endregion
/*--------------------------------------------------SOLVE----------------------------------------------------*/

void solve()
{

    int n, k;
    cin >> n >> k;
    vvii dp(k + 1, vii(n + 1, 0)); // the no of sequences possible at the ith position with jth as the last term
    rep(i, 1, n + 1) dp[1][i] = 1; // base case
    rep(i, 1, k)
    {
        rep(j, 1, n + 1)
        {
            for (int q = j; q <= n; q += j) // fill the next postion with the current postion
            {
                dp[i + 1][q] += dp[i][j], dp[i + 1][q] %= mod;
            }
        }
    }
    int ans = 0;
    for (auto it : dp[k])
        ans += it, ans %= mod;
    cout << ans;
}

/*--------------------------------------------------testcase--------------------------------------------------*/

signed main()
{
    sayian;
    int32_t testcase = 1;
    // cin>>testcase;
    for (int32_t tt = 1; tt <= testcase; tt++)
    {
        solve();
    }
    return 0;
}