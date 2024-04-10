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
int n,k,a[N];
int f[N][42],g[N][42];
vector<int> G[N];
void dfs1(int u,int fa){
	f[u][0]=a[u];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		for(int j=0;j<k;++j){
			f[u][(j+1)%k]^=f[v][j];
		}
	}
}
void dfs2(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		static int h[42];
		memcpy(h,g[u],sizeof(h));
		for(int j=0;j<k;++j){
			h[(j+1)%k]^=f[v][j];
		}
		memcpy(g[v],f[v],sizeof(g[v]));
		for(int j=0;j<k;++j){
			g[v][(j+1)%k]^=h[j];
		}
		dfs2(v,u);			
	}	
}
int main(){
	n=read(),k=read()<<1;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	dfs1(1,0);
	memcpy(g[1],f[1],sizeof(f[1]));
	dfs2(1,0);
	k>>=1;
	for(int u=1;u<=n;++u){
		int sg=0;
		for(int j=k;j<(k<<1);++j){
			sg^=g[u][j];
		}
		putchar(sg?'1':'0');
		putchar(' ');
	}
	return 0;
}