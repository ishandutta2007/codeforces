#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int M;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,C[5002][5002],f[5002][5002],inv[5002],fac[5002],pw1[5002],pw2[5002];
char s[1000002];
inline int calc(re int x,re int y){
	if(x==y)return 0;
	if(y==0)return 1;
	return 1ll*fac[x-1]*inv[x-y-1]%M;
}
int main(){
	n=read(),M=read(),memset(f,-1,sizeof(f));
	for(re int i=fac[0]=inv[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for(re int i=C[0][0]=1;i<=n;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	for(re int i=1;i<=n;++i){
		re int s=0;
		for(re int j=pw1[0]=pw2[0]=1;j<=n;++j)pw1[j]=1ll*pw1[j-1]*(n-1)%M,pw2[j]=1ll*pw2[j-1]*i%M;
		for(re int j=0;j<=i&&j<=n-i;++j)add(s,1ll*calc(i,i-j)*pw1[j]%M*C[n-i][j]%M*C[i][j]%M*fac[j]%M*pw2[n-i-j]%M);
	//	printf("TTT%d %d %d\n",n,i,s);
		s=1ll*s*C[n][i]%M;//s=1ll*s*ksm(i,n-i)%M; 
		add(ans,s);
	}
	printf("%d",ans);
	/*
	f[0][0][0]=1;
	for(re int i=0;i<n;++i)
		for(re int j=0;j<=i;++j)
			for(re int k=0;k<=n;++k){
				add(f[i+1][j+1][k],1ll*f[i][j][k]*(n-1)%M);
				if(j)add(f[i+1][j-1][k+1],1ll*j*f[i][j][k]%M);
				add(f[i+1][j][k+1],1ll*f[i][j][k]*(n-i-1)%M);
				add(f[i+1][j][k],1ll*f[i][j][k]*k%M);
				printf("AAA%d %d %d %d\n",i,j,k,f[i][j][k]);
			}
	for(re int i=0;i<=n;++i){
		re int s=0;
		for(re int j=0;j<=i;++j)if(j&1)add(s,M-1ll*C[i][j]*C[n-j][i-j]%M*fac[i-j]%M);else add(s,1ll*C[i][j]*C[n-j][i-j]%M*fac[i-j]%M);
		add(ans,1ll*f[n][0][i]*s%M);
		printf("%d %d %d %d\n",n,i,f[n][0][i],s);
	}
	printf("%d",ans);*/
}