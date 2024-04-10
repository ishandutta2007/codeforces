#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int n,p[N];
int Solve(int S){
	static int vis[N];
	memset(vis,0,sizeof(vis));
	for(int u=S;;u=p[u]){
		if(vis[u])return u;
		vis[u]=1;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
	}
	for(int u=1;u<=n;++u){
		printf("%d ",Solve(u));
	}
	return 0;
}