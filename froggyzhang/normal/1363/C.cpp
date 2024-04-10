#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 1010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,T,x,siz[N],d[N];
vector<int> G[N];
void dfs(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		for(int i=1;i<=n;++i)d[i]=0,G[i].clear();
		for(int i=1;i<=n-1;++i){
			int u=read(),v=read();
			G[u].push_back(v),G[v].push_back(u);
			++d[u],++d[v];
		}
		if(d[x]<=1){
			printf("Ayush\n");
			continue;
		}
		dfs(x,0);
		int p=0;
		for(auto v:G[x]){
			if(siz[v]&1)p^=1;
		}
		printf(p&1?"Ayush\n":"Ashish\n");
	}
	return 0;
}