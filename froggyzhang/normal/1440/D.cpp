#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
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
int T,d[N],n,m,k,vis[N];
vector<int> G[N];
bool clique(int S){
	static vector<int> t;
	t.clear();
	t.push_back(S);
	for(auto v:G[S]){
		if(vis[v]==2)continue;
		if(d[v]<k-1)return false;
		t.push_back(v);
	}
	for(auto u:t){
		for(auto v:t){
			if(u==v)break;
			if(!binary_search(G[u].begin(),G[u].end(),v))return false;
		}
	}
	printf("2\n");
	for(auto u:t){
		printf("%d ",u);
	}
	printf("\n");
	return true;
}
void Solve(){
	n=read(),m=read(),k=read();
	queue<int> q;
	for(int i=1;i<=n;++i){
		G[i].clear();
		d[i]=vis[i]=0;
	} 
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u],++d[v];
	}
	for(int i=1;i<=n;++i){
		sort(G[i].begin(),G[i].end());
		if(d[i]<k)vis[i]=1,q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=2;
		if(d[u]==k-1&&1LL*k*(k-1)<=2*m){
			if(clique(u))return;
		}
		for(auto v:G[u]){
			if(--d[v]<k&&!vis[v])vis[v]=1,q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vector<int> ans;
			for(int u=1;u<=n;++u){
				if(!vis[u])ans.push_back(u);
			}
			printf("1 %d\n",(int)ans.size());
			for(auto x:ans){
				printf("%d ",x);
			}
			printf("\n");
			return;
		}
	}
	printf("-1\n");		
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}