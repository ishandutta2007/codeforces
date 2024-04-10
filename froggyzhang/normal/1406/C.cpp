#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
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
int T,n,siz[N],maxp[N],rt1,rt2;
vector<int> G[N];
void get_root(int u,int fa){
	siz[u]=1;
	maxp[u]=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		get_root(v,u);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],n-siz[u]);
	if(!rt1||maxp[u]<maxp[rt1]){
		rt1=u,rt2=0;
	}
	else if(maxp[u]==maxp[rt1]){
		rt2=u;
	}
}
pair<int,int> Find(int u,int fa){
	if((int)G[u].size()==1)return make_pair(fa,u);
	for(auto v:G[u]){
		if(v==fa)continue;
		return Find(v,u);
	}
}
void Solve(){
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rt1=rt2=0;
	get_root(1,0);
	if(!rt2){
		printf("%d %d\n",1,G[1][0]);
		printf("%d %d\n",1,G[1][0]);
		return;
	}
	auto t=Find(rt2,rt1);
	printf("%d %d\n",t.first,t.second);
	printf("%d %d\n",rt1,t.second);
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}