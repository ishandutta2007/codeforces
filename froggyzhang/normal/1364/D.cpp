#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
#define N 200200
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
int n,m,k,dep[N],vis[N];
vector<int> G[N],st,ans;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	st.push_back(u);
	for(auto v:G[u]){
		if(v==fa)continue;
		if(dep[v]){
			int len=dep[u]-dep[v]+1;
			if(len<=k&&len>0){
				printf("%d\n%d\n",2,len);
				for(int i=(int)st.size()-1;i>=(int)st.size()-len;--i){
					printf("%d ",st[i]);
				}
				exit(0);
			}
			continue;
		} 
		dfs(v,u);
	}
	if(!vis[u]){
		ans.push_back(u);
		for(auto v:G[u])vis[v]=1;
	}
	st.pop_back();
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	printf("1\n");
	for(int i=0;i<(k+1)/2;++i){
		printf("%d ",ans[i]);
	} 
	printf("\n");
	return 0;
}