#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,p[22],fac[22],inv[22],pos[100002],v[22],ttt,P[22],vis[1<<18],tim;
ll g[22][1<<18],S[22][1<<18],f[22][1<<18],ans[1<<18],h[1<<18];
char s[22][22];
inline void FWT(re ll *A){
	for(re int i=1;i<(1<<n);i<<=1)
		for(re int j=i;j<(1<<n);++j)
			if(j&i)A[j]+=A[j^i];
}
inline void IFWT(re ll *A){
	for(re int i=1;i<(1<<n);i<<=1)
		for(re int j=i;j<(1<<n);++j)
			if(j&i)A[j]-=A[j^i];
}
inline void dfs(re int x,re int y,re int z){
	if(!z){
		--x;re ll s=0;++tim;
		for(re int i=0;i<(1<<n);++i)
			if(__builtin_popcount(((1<<n)-1)^i)&1)s-=g[x][i];
			else s+=g[x][i];
		for(re int i=1;i<=n;++i)P[i]=p[i];
		do{
			re int ss=0;
			for(re int i=1;i<=x;++i)ss=ss<<p[i]-1,ss|=(1<<p[i]-1)-1,ss<<=1;ss>>=1;
			if(vis[ss]!=tim)vis[ss]=tim,ans[ss^((1<<n-1)-1)]+=s;
		}while(next_permutation(p+1,p+x+1));
		for(re int i=1;i<=n;++i)p[i]=P[i];
		return;
	}
	if(y>z)return;
	for(re int i=y;i<=z;++i){
		p[x]=i;
		for(re int j=0;j<(1<<n);++j)g[x][j]=g[x-1][j]*S[i][j];
		dfs(x+1,i,z-i);
	}
}
int main(){
	n=read();
	for(re int j=0;j<(1<<n);++j)g[0][j]=1;
	for(re int i=0;i<n;++i)scanf("%s",s[i]);
	for(re int i=0;i<n;++i)for(re int j=0;j<n;++j)s[i][j]-='0';
	for(re int i=0;i<n;++i)f[i][1<<i]=1;
	for(re int i=0;i<(1<<n);++i)
		for(re int j=0;j<n;++j)
			if(f[j][i])
				for(re int k=0;k<n;++k)if((!(i&(1<<k)))&&s[j][k])f[k][i|(1<<k)]+=f[j][i];
	for(re int i=0;i<(1<<n);++i){
		for(re int j=0;j<n;++j)h[i]+=f[j][i];
		S[__builtin_popcount(i)][i]=h[i];
	}
	for(re int i=0;i<n;++i)FWT(S[i]);
	dfs(1,1,n),IFWT(ans);
	for(re int i=0;i<(1<<n-1);++i)printf("%lld ",ans[(1<<n-1)-i-1]);
}