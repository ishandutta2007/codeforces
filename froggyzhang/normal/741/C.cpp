#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 200010
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
int n,col[N],vis[N],x[N],y[N];
vector<int> G[N]; 
void dfs(int u){
	vis[u]=1;
	for(auto v:G[u]){
		if(vis[v])continue;
		col[v]=col[u]^1;
		dfs(v);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u); 
		x[i]=u,y[i]=v;
	}
	for(int i=1;i<=n;++i){
		G[(i<<1)-1].push_back(i<<1);
		G[i<<1].push_back((i<<1)-1);
	}
	for(int i=1;i<=(n<<1);++i){
		if(!vis[i])dfs(i);
	}
	for(int i=1;i<=n;++i){
		printf("%d %d\n",col[x[i]]+1,col[y[i]]+1);
	}
	return 0;
}