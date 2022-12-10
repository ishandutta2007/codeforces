#include<bits/stdc++.h>
using namespace std;
const int maxn=210,mod=1e9+7,inv2=5e8+4;
int f[maxn][maxn],jp[maxn][10],dep[maxn],hea[maxn],nxt[maxn<<1],to[maxn<<1],tot;
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa) {
	dep[x]=dep[fa]+1;
	jp[x][0]=fa;
	for(int i=1;i<10;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(int i=hea[x];i;i=nxt[i]) {
		if(to[i]==fa)continue;
		dfs(to[i],x);
	}
}
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int lca(int x,int y) {
	if(dep[x]<dep[y])swap(x,y);
	for(int i=9;i>=0;i--)
		if(dep[jp[x][i]]>=dep[y])
			x=jp[x][i];
	if(x==y)return x;
	for(int i=9;i>=0;i--)
		if(jp[x][i]!=jp[y][i]) {
			x=jp[x][i];
			y=jp[y][i];
		}
	return jp[x][0];
}
signed main() {
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)f[0][i]=1;
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			f[i][j]=1ll*(f[i-1][j]+f[i][j-1])*inv2%mod;
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		dfs(i,0);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) {
				int p=lca(i,j);
				ans=(ans+f[dep[j]-dep[p]][dep[i]-dep[p]])%mod;
			}
	}
	ans=1ll*ans*qpow(n,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}