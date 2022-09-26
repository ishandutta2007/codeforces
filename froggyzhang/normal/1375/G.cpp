#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
int n,col[N],cnt[2];
vector<int> G[N];
void dfs(int u,int fa){
	col[u]=col[fa]^1;
	++cnt[col[u]];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",min(cnt[0],cnt[1])-1);
	return 0;
}