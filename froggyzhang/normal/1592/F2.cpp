#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int n,m,a[N][N],c[N][N],mat[N],vis[N];
bool dfs(int u){
	for(int v=2;v<=m;++v){
		if(c[u][v]&&c[n+1][v]&&!vis[v]){
			vis[v]=1;
			if(!mat[v]||dfs(mat[v])){
				mat[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		static char s[N];
		cin>>(s+1);
		for(int j=1;j<=m;++j){
			a[i][j]=s[j]=='B';
		}	
	}
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=m+1;++j){
			c[i][j]=a[i-1][j-1]^a[i-1][j]^a[i][j-1]^a[i][j];	
		}
	}
	int ans=0;
	for(int i=2;i<=n+1;++i)
		for(int j=2;j<=m+1;++j)
			ans+=c[i][j];
	ans-=c[n+1][m+1];
	for(int i=2;i<=n;++i){
		if(c[i][m+1]){
			memset(vis,0,sizeof(vis));
			if(dfs(i))c[n+1][m+1]^=1,--ans;
		}	
	}
	ans+=c[n+1][m+1];
	cout<<ans<<'\n';
	return 0;
}