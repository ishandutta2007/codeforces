#include<bits/stdc++.h>
#define inf 1000000020
using namespace std;
const int maxn=2000005;
int d[105][105],n,m,p,k,t,ans,to[1005];
struct edge{
    int to,c;
};

edge e[maxn];
int h[maxn],nxt[maxn];
int a[maxn],s,dis[maxn],sz[maxn],b[maxn],f[maxn],y[maxn],x[maxn],c1,c2;
bool v[1005][1005],vis[1005];

bool dfs(int u){
	for (int i=1;i<=m;i++)
	    if (v[u][i]&&!vis[i]){
	    	vis[i]=true;
	    	if (to[i]==-1||dfs(to[i])){
	    		to[i]=u;return true;
	    	}
	    }
    return false;
}

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=(i==j)?0:1e9+7;
    while (m--){
        int u,v;
        cin >> u >> v;
        d[u][v]=d[v][u]=1;
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cin >> n >> m >> c1 >> c2;
    memset(to,-1,sizeof(to));
    for (int i=1;i<=n;i++) cin >> x[i] >> a[i] >> f[i];
    for (int i=1;i<=m;i++) cin >> y[i] >> b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i]>=b[j]&&d[x[i]][y[j]]<=f[i]) v[i][j]=1;
    for (int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if (dfs(i)) ++ans;
    }
    //cout<<ans<<endl;
    printf("%I64d\n",min(1ll*c2*n,1ll*c1*ans));
    return 0;
}