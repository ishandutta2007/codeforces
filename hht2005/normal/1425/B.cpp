#include<bits/stdc++.h>
using namespace std;
const int maxn=8e3+10,M=4e3,mod=1e9+7;
int p[maxn],fa[maxn],siz[maxn],pre[maxn][2],now[maxn][2],f[maxn],g[maxn][2],cnt;
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)siz[i]=1,fa[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		if(a==1||b==1)continue;
		siz[get(b)]+=siz[get(a)];
		fa[get(a)]=get(b);
	}
	for(int i=2;i<=n;i++)
		if(fa[i]==i)p[++cnt]=siz[i]+1;
	pre[M][0]=1;
	f[0]=1;
	g[0][0]=1;
	for(int i=1;i<=cnt;i++) {
		for(int j=m;j>=p[i];j--) {
			f[j]=(f[j]+f[j-p[i]])%mod;
			g[j][0]=(g[j][0]+g[j-p[i]][0])%mod;
			g[j][1]=(g[j][1]+g[j-p[i]][1])%mod;
			g[j][1]=(g[j][1]+g[j-p[i]+1][0])%mod;
		}
		g[p[i]-1][1]=(g[p[i]-1][1]+g[0][0])%mod;
		for(int j=M-m;j<=M+m;j++) {
			now[j][0]=(0ll+pre[j][0]+pre[j-p[i]][0]+pre[j+p[i]][0])%mod;
			now[j][1]=(0ll+pre[j][1]+pre[j-p[i]][1]+pre[j+p[i]][1])%mod;
			for(int k=1;k<p[i];k++) {
				now[j][1]=(0ll+now[j][1]+pre[j+2*k-p[i]][0]+pre[j-2*k+p[i]][0])%mod;
				if(k<p[i]-1)now[j][1]=(0ll+now[j][1]+pre[j+2*k-p[i]+1][0]+pre[j-2*k+p[i]-1][0])%mod;
			}
		}
		memcpy(pre,now,sizeof(pre));
	}
	if(m&1)printf("%lld\n",(now[M][1]+4ll*g[m/2][1])%mod);
	else printf("%d\n",(now[M][1]+f[m/2])%mod);
	return 0;
}