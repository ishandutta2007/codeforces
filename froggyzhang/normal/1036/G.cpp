#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 2000020
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
int n,m,dp[N],d[N],tot,g[N],o;
vector<int> G[N],T[N];
queue<int> q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int v=read(),u=read();
		G[u].push_back(v);
		T[v].push_back(u);
		++d[u];
	}
	queue<int> q;
	int s=0;
	for(int i=1;i<=n;++i){
		if(!d[i]){
			dp[i]|=1<<s;
			++s;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:T[u]){
			dp[v]|=dp[u];
			if(!--d[v])q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(T[i].empty()){
			g[++o]=i;
		}
	}
	for(int i=1;i<(1<<s)-1;++i){
		int all=0;
		for(int j=1;j<=s;++j){
			if((i>>j-1)&1){
				all|=dp[g[j]];
			}
		}
		if(__builtin_popcount(i)>=__builtin_popcount(all))return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}