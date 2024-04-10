#include <bits/stdc++.h>
int n,ans,vis[105][105],G[105][105];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&G[i][j]);
			if (i==j)vis[i][j]=1;
			if (i==n-j+1)vis[i][j]=1;
			if (i==n/2+1||j==n/2+1)vis[i][j]=1;
			ans+=vis[i][j]*G[i][j];
		}
	}printf("%d",ans);
	return 0;
}