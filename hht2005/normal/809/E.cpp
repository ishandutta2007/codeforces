#include<bits/stdc++.h>
using namespace std;
const int N=400010,mod=1e9+7;
vector<int>S[N],T[N];
int dfn[N],jp[N][20],dep[N],dfns;
int h[N],sk[N],pos[N],a[N],sum[N],sumd[N];
int g[N],phi[N],ans[N],fl[N],p[N],tot;
int cmp(int a,int b) {
	return dfn[a]<dfn[b];
}
void dfs(int x,int fa) {
	dfn[x]=++dfns;
	dep[x]=dep[fa]+1;
	jp[x][0]=fa;
	for(int i=1;i<20;i++)
		jp[x][i]=jp[jp[x][i-1]][i-1];
	for(int y:S[x])
		if(y!=fa)dfs(y,x);
}
int lca(int a,int b) {
	if(dep[a]<dep[b])swap(a,b);
	for(int i=19;i>=0;i--)
		if(dep[jp[a][i]]>=dep[b])
			a=jp[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)
		if(jp[a][i]!=jp[b][i]) {
			a=jp[a][i];
			b=jp[b][i];
		}
	return jp[a][0];
}
void build(int n) {
	sort(h+1,h+n+1,cmp);
	int top;
	T[sk[top=1]=1].clear();
	h[0]=1;
	for(int i=1;i<=n;i++) {
		if(h[i]==h[i-1])continue;
		int p=lca(h[i],sk[top]),las=0;
		while(dep[sk[top]]>dep[p]) {
			if(las)T[sk[top]].push_back(las);
			las=sk[top--];
		}
		if(p!=sk[top])T[sk[++top]=p].clear();
		if(las)T[p].push_back(las);
		T[sk[++top]=h[i]].clear();
	}
	while(--top)T[sk[top]].push_back(sk[top+1]);
}
void calc(int x,int d) {
	sum[x]=sumd[x]=0;
	if(a[x]%d==0) {
		sum[x]=phi[a[x]];
		sumd[x]=1ll*phi[a[x]]*dep[x]%mod;
	}
	for(int y:T[x]) {
		calc(y,d);
		g[d]=(g[d]+1ll*sumd[x]*sum[y]+1ll*sumd[y]*sum[x])%mod;
		g[d]=(g[d]-2ll*dep[x]*sum[x]%mod*sum[y]%mod+mod)%mod;
		sum[x]=(sum[x]+sum[y])%mod;
		sumd[x]=(sumd[x]+sumd[y])%mod;
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
int main() {
	int n,x,y;
	scanf("%d",&n);
	phi[1]=1;
	for(int i=2;i<=n;i++) {
		if(!fl[i])p[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&p[j]*i<=n;j++) {
			fl[p[j]*i]=1;
			if(i%p[j]==0) {
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		pos[a[i]]=i;
	}
	for(int i=2;i<=n;i++) {
		scanf("%d%d",&x,&y);
		S[x].push_back(y);
		S[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) {
		int cnt=0;
		for(int j=i;j<=n;j+=i)
			h[++cnt]=pos[j];
		build(cnt);
		calc(1,i);
	}
	int Ans=0;
	for(int i=n;i>=1;i--) {
		ans[i]=g[i];
		for(int j=2*i;j<=n;j+=i)
			ans[i]=(ans[i]-ans[j]+mod)%mod;
		Ans=(Ans+1ll*ans[i]*i%mod*qpow(phi[i],mod-2))%mod;
	}
	printf("%lld\n",2ll*Ans*qpow(n,mod-2)%mod*qpow(n-1,mod-2)%mod);
	return 0;
}