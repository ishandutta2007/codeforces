#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>

static ll n,ans[1LL<<18],ad[18][18];
static V(ll) dp[1LL<<18][18];
static bool f[1LL<<18][18];
static char c;

void xd(ll t,ll x)
{
    if(f[t][x]) return;
    REP(i,0,(1LL<<(__builtin_popcountll(t)-1)))
    {
        dp[t][x].PB(0);
    }
    REP(i,0,n)
    {
        if((1LL<<i)&(t^(1LL<<x)))
        {
            xd((t^(1LL<<x)),i);
            REP(j,0,(1LL<<(__builtin_popcountll(t)-2)))
            {
                dp[t][x][(j<<1)|ad[i][x]]+=dp[(t^(1LL<<x))][i][j];
            }
        }
    }
    f[t][x]=true;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            cin>>c;
            ad[i][j]=c-'0';
        }
    }
    REP(i,0,n)
    {
        dp[1LL<<i][i].PB(1);
        f[1LL<<i][i]=true;
    }
    REP(i,0,n)
    {
        xd((1LL<<n)-1,i);
        REP(j,0,(1LL<<(n-1)))
        {
            ans[j]+=dp[(1LL<<n)-1][i][j];
        }
    }
    REP(i,0,(1LL<<(n-1)))
    {
        cout<<ans[i]<<' ';
    }

    return 0;
}