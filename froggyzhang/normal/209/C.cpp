#include<bits/stdc++.h>
using namespace std;
#define N 1000100
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
int n,m,d[N],vis[N],odd,ans;
vector<int> t,G[N];
void dfs(int u){
	odd+=d[u]&1;
	vis[u]=1;
	for(auto v:G[u]){
		if(!vis[v])dfs(v);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u],++d[v];
	}
	dfs(1);
	t.push_back(odd);
	for(int i=2;i<=n;++i){
		if(!d[i]||vis[i])continue;
		odd=0;
		dfs(i);
		t.push_back(odd);
	}
	for(auto x:t)ans+=x;
	ans>>=1;
	int zero=0;
	for(int i=1;i<(int)t.size();++i){
		if(!t[i])++zero;
	}
	if(zero)ans+=zero;
	if(!t[0]&&t.size()>1)++ans;
	printf("%d\n",ans);
	return 0;
}