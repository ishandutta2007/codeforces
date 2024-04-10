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
int n,vis[N],m,d[N],cnt,ok[N];
ll ans;
vector<int> G[N];
void dfs(int u){
	vis[u]=1;
	for(auto v:G[u])if(!vis[v])dfs(v);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		ok[u]=1,ok[v]=1;
		G[u].push_back(v);
		G[v].push_back(u);
		if(u==v){
			++cnt;
		}
		else{
			++d[u],++d[v];
		}
	}
	for(int i=1;i<=n;++i)if(ok[i]){dfs(i);break;}
	for(int i=1;i<=n;++i){
		if(ok[i]&&!vis[i])return !printf("0\n");
	}
	ans=1LL*cnt*(m-cnt)+1LL*cnt*(cnt-1)/2;
	for(int i=1;i<=n;++i){
		ans+=1LL*d[i]*(d[i]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}