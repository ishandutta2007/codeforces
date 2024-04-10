#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,d[N],mx;
vector<int> G[N];
vector<pair<int,int> > ans;
void dfs(int u,int fa,int t){
	int bg=t;
	ans.emplace_back(u,t);
	if(t==mx){
		t-=d[u];
		ans.emplace_back(u,t);
	}
	auto it= --G[u].end();
	if((*it)==fa)--it;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,++t);
		ans.emplace_back(u,t);
		if(t==mx&&(*it)!=v){
			t-=d[u];
			ans.emplace_back(u,t);
		}
	}
	if(u^1&&t+1!=bg){
		ans.emplace_back(u,bg-1);
	}
}
int main(){
	n=read();
	if(n==1)return !printf("1\n1 0\n");
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u],++d[v];
	}
	for(int i=1;i<=n;++i){
		mx=max(mx,d[i]);
	}
	dfs(1,0,0);
	printf("%d\n",(int)ans.size());
	for(auto [u,t]:ans){
		printf("%d %d\n",u,t);
	}
	return 0;
}