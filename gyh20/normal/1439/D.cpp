#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[502],g[502],C[502][502],M,S[502],F[502][502],G[502][502];
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-=M:x;}
int main(){
	n=read(),m=read(),M=read();
	for(re int i=1;i<=n;++i)S[i]=i*(i+1)>>1;
	for(re int i=C[0][0]=1;i<=n;++i)
		for(re int j=C[i][0]=1;j<=n;++j)
			C[i][j]=Mod(C[i-1][j]+C[i-1][j-1]);
	g[0]=1,g[1]=2;
	for(re int i=2;i<=n;++i)
		for(re int j=1;j<=i;++j){
			add(g[i],1ll*g[j-1]*g[i-j]%M*C[i-1][j-1]%M*(i+1)%M);
			add(f[i],1ll*g[j-1]*g[i-j]%M*C[i-1][j-1]%M*(S[j-1]+S[i-j])%M);
			add(f[i],1ll*f[j-1]*g[i-j]%M*C[i-1][j-1]%M*(i+1)%M);
			add(f[i],1ll*g[j-1]*f[i-j]%M*C[i-1][j-1]%M*(i+1)%M);
		}
	G[0][0]=1;
	for(re int i=1;i<=n;++i){
		F[i][i]=f[i],G[i][i]=g[i],G[i][0]=1;
		for(re int j=1;j<i;++j){
			F[i][j]=F[i-1][j],G[i][j]=G[i-1][j];
			for(re int k=1;k<=i;++k)if(i-k+1<=j){
				add(G[i][j],1ll*C[j][i-k+1]*G[k-2][j-(i-k+1)]%M*G[i-k+1][i-k+1]%M);
				add(F[i][j],1ll*C[j][i-k+1]*G[k-2][j-(i-k+1)]%M*F[i-k+1][i-k+1]%M);
				add(F[i][j],1ll*C[j][i-k+1]*F[k-2][j-(i-k+1)]%M*G[i-k+1][i-k+1]%M);
			}
		}
	}
	printf("%d",F[n][m]);
}