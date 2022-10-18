#include <bits/stdc++.h>
int n,u,v,size[55];
double f[55][55],C[55][55],g[55],h[55],fac[55];
std::vector<int>ch[55];

void dfs(int u,int pr){
	f[u][0]=1;size[u]=1;
	for(int v:ch[u]){
		if(v==pr)continue;
		dfs(v,u);
		std::memset(g,0,sizeof(g));
		for(int i=0;i<=size[v];++i)
		for(int j=1;j<=size[v];++j){
			if(j<=i)g[i]+=0.5*f[v][j-1];
			else g[i]+=f[v][i];
		}
		std::memset(h,0,sizeof(h));
		for(int i=size[u]-1;i>=0;--i)
		for(int j=size[v];j>=0;--j)
			h[i+j]+=f[u][i]*g[j]*C[i+j][j]*C[size[u]-i-1+size[v]-j][size[u]-i-1];
		for(int i=0;i<size[u]+size[v];++i)f[u][i]=h[i];
		size[u]+=size[v];
	}//size[u]++;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}fac[0]=1;for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}for(int i=1;i<=n;++i){
		std::memset(f,0,sizeof(f));
		dfs(i,0);
		printf("%.7f\n",f[i][n-1]/fac[n-1]);
	}
	return 0;
}