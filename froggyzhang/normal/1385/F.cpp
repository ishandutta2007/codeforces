#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define N 200020
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
int T,n,k,c[N],d[N];
vector<int> G[N];
set<pair<int,int> > s;
void Solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
		c[i]=0;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(k==1){
		printf("%d\n",n-1);
		return;
	}
	int ans=0;
	s.clear();
	for(int i=1;i<=n;++i){
		d[i]=G[i].size();
		if(G[i].size()==1)G[i].clear();
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u]){
			if(d[v]==1)++c[u];
		}
		s.insert(make_pair(c[u],u));
	}
	while(!s.empty()){
		int u=(*--s.end()).second;
		s.erase(--s.end());
		if(c[u]<k)break;
		ans+=c[u]/k;
		d[u]-=c[u]/k*k;
		c[u]%=k;
		if(d[u]==1){
			for(auto v:G[u]){
				if(!G[v].empty()){
					s.erase(make_pair(c[v],v));
					++c[v];
					s.insert(make_pair(c[v],v));
					break;
				}
			}
			G[u].clear();
		}
		else{
			s.insert(make_pair(c[u],u));
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}