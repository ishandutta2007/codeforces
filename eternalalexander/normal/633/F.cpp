#include <bits/stdc++.h>
#define maxn 100005
long long f[maxn][4][3]={0},g[4][3];
int n,u,v,w[maxn];
std::vector<int>conj[maxn];

void dfs(int u,int fa){
	f[u][0][1]=f[u][1][2]=w[u];
	for(int i=0;i<conj[u].size();++i){
		int v=conj[u][i];
		if (v==fa)continue;
		dfs(v,u);
		std::memset(g,0,sizeof(g));
		for(int k=0;k<=2;++k){g[k][0]=f[u][k][0];g[k][1]=f[u][k][1];g[k][2]=f[u][k][2];}
		for(int k=0;k<=2;++k){
			for(int l=0;l<=k;++l)g[k][0]=std::max(g[k][0],f[u][l][0]+f[v][k-l][0]);
			for(int l=0;l<k;++l)g[k][2]=std::max(g[k][2],f[u][l][1]+f[v][k-l-1][1]);
			for(int l=0;l<=k;++l)g[k][2]=std::max(g[k][2],f[u][l][2]+f[v][k-l][0]); 
			for(int l=0;l<=k;++l)g[k][1]=std::max(g[k][1],std::max(f[u][l][1]+f[v][k-l][0],f[u][l][0]+f[v][k-l][1]+w[u]));
		}for(int k=0;k<=2;++k){f[u][k][0]=g[k][0];f[u][k][1]=g[k][1];f[u][k][2]=g[k][2];}
	}for(int k=0;k<=2;++k){
		f[u][k][0]=std::max(f[u][k][0],std::max(f[u][k][2],k>0?f[u][k-1][1]:0));
	}//printf("%d:\n",u);
//	for(int i=0;i<=1;++i){for(int k=0;k<=2;++k)printf("%d ",f[u][k][i]);printf("\n");}
}

				

int main(){
//	freopen("attack5.in","r",stdin);
	//freopen("attack.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		conj[u].push_back(v);conj[v].push_back(u);
	}dfs(1,0);
	std::cout<<std::max(f[1][2][0],f[1][2][2]);
	return 0;
}