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
int d[N],rt,f[N],n,T,t[N],vis[N],h[N];
vector<pair<int,int> > A,B;
vector<int> G[N];
int qwq;
void dfs(int u,int fa){
	int cnt=0;
	f[u]=fa;
	int o[2]={0,0};
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(!t[v]){
			if(cnt==2){
				B.emplace_back(h[v],v);	
				t[v]=1;
			}
			else{
				o[cnt]=h[v];
				++cnt;
				if(cnt==2){
					B.emplace_back(o[0],o[1]);
					t[u]=1;
				}
			}
		}
	}
	if(!t[u]){
		h[u]=o[0]?o[0]:u;
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		d[i]=t[i]=vis[i]=h[i]=0;
		G[i].clear();
	}
	qwq=0;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
		++d[u],++d[v];
	}
	for(int i=1;i<=n;++i){
		if(d[i]==1)rt=i;
	}
	A.clear(),B.clear();
	dfs(rt,0);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(t[i]){
			++cnt;
			--d[i],--d[f[i]];
			A.emplace_back(i,f[i]);
		}
	}
	assert((int)A.size()==cnt);
	assert(A.size()==B.size());
	int now=rt;
	printf("%d\n",cnt);
	for(int i=0;i<cnt;++i){
		printf("%d %d %d %d\n",A[i].first,A[i].second,now,B[i].first);
		now=B[i].second;
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}