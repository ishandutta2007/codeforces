#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
const int maxn=3e5+3;
int dp[maxn][19],n,m,ans[maxn],a[maxn],last[19];
vector <pi> h[maxn];
void Min(int &x,int y){
    if (y<x) x=y;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        h[u].pb((pi){v,i});
    }
    for (int i=0;i<19;i++) dp[n+1][i]=last[i]=n+1;
    for (int i=n;i;i--){
        for (int j=0;j<19;j++) {
            if (a[i]&(1<<j)) dp[i][j]=i;
            else {
                dp[i][j]=n+1;
                for (int k=0;k<19;k++) if (a[i]&(1<<k)) Min(dp[i][j],dp[last[k]][j]);
            }
        }
        for (int j=0;j<19;j++) if (a[i]&(1<<j)) last[j]=i;
        for (auto x:h[i]){
            int id=x.S,r=x.F;
            for (int j=0;j<19;j++) if (a[r]&(1<<j)) ans[id]|=(dp[i][j]<=r);
        }
    }
    for (int i=1;i<=m;i++) if (ans[i]) puts("Shi"); else puts("Fou");
    return 0;
}