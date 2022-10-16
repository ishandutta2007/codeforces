#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf(x...) assert(scanf(x))
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cerr<<(k>>20)<<endl;}

const int mxn=2e5+3;

VI g[mxn];int n,b[mxn],rt,mv[mxn];ll dp[mxn];
void dfs(int x,int f=0){
    for(int y:g[x])if(y!=f){dfs(y,x),mv[x]=max(mv[x],mv[y]),dp[x]+=dp[y];}
    if(!f){
        int v1=0,v2=0;
        for(int y:g[x])if(y!=f){if(mv[y]>=v1)v2=v1,v1=mv[y];else if(mv[y]>=v2)v2=mv[y];}
        dp[x]+=b[x]*2-v1-v2;
        return;
    }
    if(b[x]>mv[x])dp[x]+=b[x]-mv[x],mv[x]=b[x];
    
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",b+i);for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
    for(int i=1;i<=n;++i)if(b[i]>=b[rt])rt=i;
    dfs(rt);cout<<dp[rt]<<endl;
    return 0;
}