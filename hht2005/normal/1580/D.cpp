#include<bits/stdc++.h>
using namespace std;
const int N=4010;
int a[N],ls[N],rs[N],sk[N],siz[N],m;
long long f[N][N];
void dfs(int x) {
	if(!x)return;
	dfs(ls[x]);
	dfs(rs[x]);
	siz[x]=siz[ls[x]]+siz[rs[x]]+1;
	for(int i=0;i<=siz[ls[x]];i++)
		for(int j=0;j<=siz[rs[x]];j++) {
			f[x][i+j]=max(f[x][i+j],f[ls[x]][i]+f[rs[x]][j]-2ll*i*j*a[x]);
			f[x][i+j+1]=max(f[x][i+j+1],f[ls[x]][i]+f[rs[x]][j]+1ll*m*a[x]-(2ll*(i+1)*(j+1)-1)*a[x]);
		}
}
signed main() {
	int n,top=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		int las=0;
		while(top&&a[i]<=a[sk[top]])las=sk[top--];
		if(las)ls[i]=las;
		if(top)rs[sk[top]]=i;
		sk[++top]=i;
	}
	dfs(sk[1]);
	printf("%lld\n",f[sk[1]][m]);
	return 0;
}