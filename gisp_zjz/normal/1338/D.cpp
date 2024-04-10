#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+6;
typedef long long ll;
vector <int> h[maxn];
int n,p,q,flag,ans,dp[maxn][2];
void Max(int &x,int y){
    if (y>x) x=y;
}
void dfs(int u,int fa){
    //nd down, d all
    int x=0,y=0,xx=0,yy=0,d=h[u].size(),nd=d;
    if (fa) nd--;
    for (auto v:h[u]){
        if (v==fa) continue;
        dfs(v,u);
        int p=dp[v][0],q=max(dp[v][0],dp[v][1]);
        if (p>x) y=x,x=p; else if (p>y) y=p;
        if (q>xx) yy=xx,xx=q; else if (q>yy) yy=q;
    }
    dp[u][0]=nd; dp[u][1]=1;
    Max(dp[u][0],nd-1+xx);
    Max(dp[u][1],1+x);
    Max(ans,d);
    Max(ans,d-1+xx);
    Max(ans,d-2+xx+yy);
    Max(ans,1+x+y);
    //cout<<u<<' '<<x<<' '<<y<<' '<<xx<<' '<<yy<<endl;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        h[u].pb(v); h[v].pb(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}