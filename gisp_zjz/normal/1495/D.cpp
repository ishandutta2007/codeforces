#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int M=998244353;
int dis[405][405],ans[405][405];
int n,m,cnt[405][405],x[405],y[405];
vector<int> G[405];
int main(){
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=(i==j)?0:n+1;
    while (m--){
		int u,v; cin >> u >> v;
		dis[u][v]=dis[v][u]=1;
		G[u].pb(v); G[v].pb(u);
    }
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j++){
        int res=1,d=dis[i][j];
        for (int u=1;u<=n;u++){
            int d1=dis[i][u],d2=dis[j][u];
            if ((d1+d2+d)&1) res=0;
			x[u]=(d1-d2+d)/2;
			y[u]=(d1+d2-d)/2;
			if (x[u]<0||x[u]>d||y[0]<0) res=0;
			cnt[x[u]][y[u]]++;
        }
        for (int w=0;w<=d;w++) if (cnt[w][0]!=1){res=0;break;}
        for (int u=1;u<=n;u++){
			if (y[u]==0) continue;
			int tot=0;
			for (auto v:G[u]){
				if (x[v]==x[u]&&y[v]+1==y[u]) ++tot;
			}
			res=1ll*res*tot%M;
        }
        for (int u=1;u<=n;u++) cnt[x[u]][y[u]]--;
        ans[i][j]=ans[j][i]=res;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",ans[i][j]);puts("");
	}
	return 0;
}