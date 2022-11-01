#include<bits/stdc++.h>
using namespace std;
#define N 205
const int mod=1e9+7;
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
int p[N][N],n,inv[N],ans,dep[N],ipw2[N<<1],C[N<<1][N<<1],dfn[N],siz[N],lca[N][N],f[N],num;
vector<int> G[N];
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	dfn[u]=++num;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];	
	}
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=f[x];
	while(f[x]^f[y])x=f[x],y=f[y];
	return x==y?x:f[x];
}
inline void Get(int x,int y){
	if(!lca[f[x]][f[y]])Get(f[x],f[y]);
	lca[x][y]=lca[f[x]][f[y]];
}
int main(){
	n=read();
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	ipw2[0]=1;
	for(int i=1;i<=(n<<1);++i){
		ipw2[i]=1LL*ipw2[i-1]*inv[2]%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=(n<<1);++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}	
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int j=1;j<=n;++j)p[0][j]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<j;++k){
				p[i][j]=(p[i][j]+1LL*ipw2[i+k]*C[i-1+k][k])%mod;
			}
		}	
	}
	dep[0]=-1;
	for(int rt=1;rt<=n;++rt){
		num=0;
		dfs(rt,0);
		memset(lca,0,sizeof(lca));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dfn[j]>=dfn[i]&&dfn[j]<=dfn[i]+siz[i]-1){
					lca[i][j]=lca[j][i]=i;
				}	
			}
		}
		
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(!lca[i][j]){
					Get(i,j);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				ans=(ans+p[dep[i]-dep[lca[i][j]]][dep[j]-dep[lca[i][j]]])%mod;	
			}	
		}
	}
	ans=1LL*ans*inv[n]%mod;
	printf("%d\n",ans);
	return 0;
}