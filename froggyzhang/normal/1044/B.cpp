#include<bits/stdc++.h>
using namespace std;
#define N 1234
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
int T,n,mark[N],ok[N];
vector<int> G[N];
bool fd;
void Ask(char c,int x){
	printf("%c %d\n",c,x);
	fflush(stdout);
}
void dfs(int u,int fa){
	if(mark[u]){
		Ask('A',u);
		if(ok[read()])fd=true,Ask('C',u);
		return;		
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		mark[i]=ok[i]=0;
		G[i].clear();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int k1=read();
	for(int i=1;i<=k1;++i){
		mark[read()]=1;
	}
	int k2=read();
	int pos=0;
	for(int i=1;i<=k2;++i){
		int x=read();
		ok[x]=1;
		if(i==k2){
			Ask('B',x);
			pos=read();
		}
	}
	if(mark[pos]){
		Ask('C',pos);
		return;
	}
	fd=false;
	dfs(pos,0);
	if(!fd)Ask('C',-1);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}