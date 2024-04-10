#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
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
int n,m,vis[N],a[N],ans;
vector<int> G[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back(v);
	}
	for(int u=1;u<=n;++u){
		if(!vis[u]){
			vis[u]=a[u]=1;
			for(auto v:G[u])vis[v]=1;
		}
	}
	for(int u=n;u>=1;--u){
		if(a[u]){
			for(auto v:G[u])a[v]=0;
			++ans;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		if(a[i])printf("%d ",i);
	}
	return 0;
}