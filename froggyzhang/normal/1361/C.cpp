#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 4000050
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
int n,a[N],b[N],d[N],vis[N],nxt[N];
vector<int> ans,G[N];
void dfs(int u){
	while(!G[u].empty()){
		int v=G[u].back();
		G[u].pop_back();
		if(vis[v])continue;
		vis[v]=vis[((v-1)^1)+1]=1;
		dfs(nxt[v]);
		ans.push_back(((v-1)^1)+1);
		ans.push_back(v);
	}
}
bool Solve(int k){
	for(int i=0;i<(1<<k);++i){
		G[i].clear();d[i]=0;
	}
	ans.clear();
	int p=(1<<k)-1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		int x=(a[i]&p),y=(b[i]&p);
		G[x].push_back(2*i-1),G[y].push_back(i<<1);
		++d[x],++d[y];
		nxt[2*i-1]=y,nxt[i<<1]=x;
	}
	for(int i=0;i<(1<<k);++i){
		if(d[i]&1)return false;
	}
	dfs(nxt[1]);
	return (int)ans.size()==(n<<1);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
	}
	for(int i=20;i>=0;--i){
		if(Solve(i)){
			printf("%d\n",i);
			for(auto x:ans){
				printf("%d ",x);
			}
			break;
		}
	}
	
	return 0;
}