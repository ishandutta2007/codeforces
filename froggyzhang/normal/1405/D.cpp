#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 100010
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
int T,n,A,B,vis[N],dep[N],dA,dB;
vector<int> G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
bool Solve(){
	n=read(),A=read(),B=read(),dA=read(),dB=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(2*dA>=dB)return false;
	dep[0]=-1;
	dfs(A,0);
	if(dep[B]<=dA)return false;
	int root=1;
	for(int i=2;i<=n;++i){
		if(dep[i]>dep[root]){
			root=i;
		}
	}
	dfs(root,0);
	for(int i=1;i<=n;++i){
		if(dep[i]>2*dA)return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"Bob\n":"Alice\n");
	}
	return 0;
}