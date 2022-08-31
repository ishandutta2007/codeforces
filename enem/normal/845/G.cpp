#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define V(a) vector<a>

static const ll N=100005;
static ll ntc,n,m,q,basis[64],dp[N];
static V(pll) ad[N];

void dfs(ll x)
{
    for(auto it:ad[x])
    {
        if(dp[it.F]==-1)
        {
            dp[it.F]=(dp[x]^it.S);
            dfs(it.F);
        }
        else
        {
            ll t=((dp[it.F]^dp[x])^it.S);
            while(t>0)
            {
                if(basis[__builtin_clzll(t)]>0)
                {
                    t^=basis[__builtin_clzll(t)];
                }
                else
                {
                    basis[__builtin_clzll(t)]=t;
                    break;
                }
            }
        }
    }
    return;
}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    // cin>>ntc;
    ntc=1;
    REP(tc,1,ntc+1)
    {
        // cin>>n>>m>>q;
        cin>>n>>m;q=1;
        REP(i,0,64)
        {
            basis[i]=0;
        }
        REP(i,0,n)
        {
            ad[i].clear();
            dp[i]=-1;
        }
        REP(i,0,m)
        {
            ll t1,t2,t3;
            cin>>t1>>t2>>t3;
            t1--;t2--;
            ad[t1].PB(MP(t2,t3));
            ad[t2].PB(MP(t1,t3));
        }
        ll xx=rng()%n;
        dp[xx]=0;
        dfs(xx);
        REP(i,0,q)
        {
            ll t1,t2;
            // cin>>t1>>t2;
            t1=1;t2=n;
            t1--;t2--;
            ll t=(dp[t1]^dp[t2]);
            REP(j,0,64)
            {
                if((1LL<<(63-j))&t) t^=basis[j];
            }
            cout<<t<<'\n';
        }
    }

    return 0;
}