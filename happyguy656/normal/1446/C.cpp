#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,a[mxn],tr[mxn*33][2],tn,sz[mxn*33],dp[mxn*33];
void dfs(int z){
    int x=tr[z][0],y=tr[z][1];
    if(x)dfs(x);if(y)dfs(y);
    if(!x)dp[z]=dp[y];else if(!y)dp[z]=dp[x];
    else dp[z]=min(dp[x]+sz[y]-1,dp[y]+sz[x]-1);
}
int main(){
    scanf("%d",&n);sz[0]=n;for(int t=1;t<=n;++t){
        int x;scanf("%d",&x);
        for(int i=30,d=0;~i;--i){
            int c=x>>i&1;if(!tr[d][c])tr[d][c]=++tn;d=tr[d][c];++sz[d];
        }
    }
    dfs(0);printf("%d\n",dp[0]);
    return 0;
}