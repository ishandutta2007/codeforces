#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,mod=1e9+7;
int hea[maxn],nxt[maxn<<1],to[maxn<<1],p[maxn],tot,n;;
long long siz[maxn];
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void dfs(int x,int fa) {
	siz[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa) {
			dfs(to[i],x);
			siz[x]+=siz[to[i]];
		}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(hea,tot=0,sizeof(hea));
		int m,x,y;
		scanf("%d",&n);
		for(int i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d",p+i);
		while(m<n-1)p[++m]=1;
		sort(p+1,p+m+1);
		dfs(1,0);
		for(int i=2;i<=n;i++)siz[i]=siz[i]*(n-siz[i]);
		sort(siz+2,siz+n+1);
		for(int i=2;i<=n;i++)siz[i]%=mod;
		int ans=siz[n];
		for(int i=n-1;i<=m;i++)ans=1ll*ans*p[i]%mod;
		for(int i=n-1;i>=2;i--)
			ans=(ans+1ll*p[i-1]*siz[i])%mod;
		printf("%d\n",ans);
	}
	return 0;
}