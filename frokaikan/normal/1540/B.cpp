#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 200;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
int dp[maxn+5][maxn+5];
vi e[maxn+5];

int sz[maxn+5];

void dfs(int now,int fa)
{
    sz[now]=1;
    for(auto v: e[now]) if(v!=fa) 
    {
        dfs(v,now);
        sz[now]+=sz[v];
    }
}

ll inv[maxn+5];
int sta[maxn+5],top;
int ans;
void solve(int now,int fa,int rt)
{
    sta[++top]=now;
    if(now<rt)
    {
        rep(i,1,top-1)
        {
            int u=sta[i],v=sta[i+1];
            ans=(ans+1ll*(sz[u]-sz[v])*dp[i-1][top-i])%mod;
        }
    }
    for(auto v: e[now]) if(v!=fa) solve(v,now,rt);
    top--;
}

int main()
{
    inv[1]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) dp[0][i]=1;
    rep(i,1,maxn) rep(j,1,maxn) dp[i][j]=1ll*(dp[i-1][j]+dp[i][j-1])*inv[2]%mod;
	int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    rep(rt,2,n) 
    {
        dfs(rt,0);
        solve(rt,0,rt);
    }
    ans=1ll*ans*inv[n]%mod;
    printf("%d\n",ans);
	return 0;
}