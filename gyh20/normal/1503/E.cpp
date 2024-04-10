#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,ans,g[2032][2032],h[2032][2032],sum[2032][2032],mx[2032],mn[2032],v1[2032],v2[2032];
int main(){
	n=read(),m=read();
	g[0][0]=1;
	re int N=max(n,m);
	for(re int i=0;i<N;++i){
		for(re int j=0;j<=N;++j){
			h[i][j]=g[i][j];
			if(j)add(h[i][j],h[i][j-1]);
		}
		for(re int k=0;k<=N;++k)g[i+1][k]=h[i][k];
	}
	for(re int i=0;i<=m;++i){
		memset(mx,0,sizeof(mx)),memset(mn,0,sizeof(mn));
		for(re int j=1;j<=n;++j)add(mx[j],1ll*g[m-i][n-j]*h[m-i][j-1]%M),add(mn[j],1ll*g[m-i][j-1]*h[m-i][n-j]%M);
		for(re int i=1;i<=n;++i)add(mx[i],mx[i-1]);
		for(re int i=n;i;--i)add(mn[i],mn[i+1]);
		for(re int l=1;l<=n;++l)add(ans,1ll*g[i][l-1]*h[i][n-l]%M*mx[l-1]%M);
		for(re int r=1;r<=n;++r)add(ans,1ll*h[i][r-1]*g[i][n-r]%M*mn[r+1]%M);
	}
	for(re int i=1;i<n;++i){
		for(re int j=2;j<m;++j)v1[j]=1ll*h[n-i][j-2]*g[n-i][m-j+1]%M,add(v1[j],v1[j-1]);
		for(re int j=2;j<m;++j)v2[j]=1ll*g[i][m-j+1]*h[i][j-2]%M,add(v2[j],v2[j-1]);
		for(re int j=2;j<m;++j){
			add(ans,1ll*h[i][m-j-1]*g[i][j]%M*v1[j]%M);
			add(ans,1ll*h[n-i][m-j-1]*g[n-i][j]%M*v2[j]%M);
		}
	}
	printf("%d",ans);
}