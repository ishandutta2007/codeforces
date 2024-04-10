#include<bits/stdc++.h>
using namespace std;
#define N 2005
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
int n;
class Graph{
public:
	vector<int> G[N];
	int l[N],r[N],m,w[N][N],siz[N];
	void dfs(int u){
		for(auto v:G[u]){
			dfs(v);
			siz[u]+=siz[v]+1;
			l[u]=min(l[u],l[v]);
			r[u]=max(r[u],r[v]);
		}
		w[l[u]][r[u]]=max(w[l[u]][r[u]],siz[u]+(u!=1));
	}
	void init(){
		m=read();
		for(int i=2;i<=m;++i){
			int fa=read();
			G[fa].push_back(i);
		}
		for(int i=1;i<=m;++i){
			l[i]=n+1,r[i]=0;
		}
		for(int i=1;i<=n;++i){
			int x=read();
			l[x]=r[x]=i;
		}
		dfs(1);
	}
}T1,T2;
int dp[N];
int main(){
	n=read();
	T1.init();
	T2.init();
	for(int i=1;i<=n;++i){
		for(int j=i;j>=1;--j){
			dp[i]=max(dp[i],dp[j-1]+max(T1.w[j][i],T2.w[j][i]));	
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}