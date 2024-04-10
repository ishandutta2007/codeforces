#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,L[131072],k,p[12],B[131072],num[131072],pos[131072],cnt,q;
long long ans[131072],F[17][131072];
short f[128][17][42001],g[128][17][42001],b[17][42001];
char s[22][22],v[22];
inline void dfs(re int x,re int y,re int z,re int xx){
	if(B[z]==n-m){
		x<<=m;
		re int bj=((1<<n)-1)^z;
		for(re int j=0;j<n;++j)
			if(((1<<j)&bj))
			for(re int i=0;i<b[j][pos[bj]];++i)ans[x+i+(s[y][j]<<m-1)]+=1ll*xx*g[i][j][pos[bj]];	
		return;
	}
	for(re int i=0;i<n;++i){
		if(z&(1<<i))continue;
		dfs((x<<1)+s[y][i],i,z|(1<<i),xx);
	}
}
int main(){
//	freopen("s1mple.in","r",stdin);
//	freopen("s1mple.out","w",stdout);
	n=read();
	for(re int i=0;i<(1<<n);++i)B[i]=__builtin_popcount(i);
	for(re int i=2;i<(1<<n);++i)L[i]=L[i>>1]+1;
	m=min(7,n>>1);
	for(re int i=0;i<(1<<n);++i)if(B[i]<=m)num[cnt]=i,pos[i]=cnt,++cnt;
	for(re int i=0;i<n;++i)scanf("%s",s[i]);
	for(re int i=0;i<n;++i)for(re int j=0;j<n;++j)s[i][j]-='0';
	for(re int i=0;i<n;++i)f[0][i][pos[1<<i]]=g[0][i][pos[1<<i]]=1;
	for(re int k=0;k<cnt;++k){
		if(B[num[k]]==m)continue;
		for(re int i=0;i<(1<<m-1);++i)
			for(re int j=0;j<n;++j)
				if(f[i][j][k]||g[i][j][k]){
					re int x=num[k]^((1<<n)-1);
					while(x){
						f[(i<<1)+s[j][L[x&(-x)]]][L[x&(-x)]][pos[num[k]|(x&(-x))]]+=f[i][j][k];
						g[i+(s[L[x&(-x)]][j]<<(B[num[k]]-1))][L[x&(-x)]][pos[num[k]|(x&(-x))]]+=g[i][j][k];
						x^=x&(-x);
					}
				}
	}
	for(re int k=0;k<cnt;++k)
		if(B[num[k]]==m)
			for(re int i=0;i<(1<<m-1);++i)
				for(re int j=0;j<n;++j)
					if(g[i][j][k])b[j][k]=max((int)b[j][k],i+1);
	for(re int k=0;k<cnt;++k){
		if(B[num[k]]==m)
			for(re int i=0;i<(1<<m-1);++i)
				for(re int j=0;j<n;++j)
					if(f[i][j][k])dfs(i,j,num[k],f[i][j][k]);
		}
	for(re int i=0;i<(1<<n-1);++i)printf("%lld ",ans[i]);
}