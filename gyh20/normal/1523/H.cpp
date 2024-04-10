#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[20002],f[20002][22][32],mx[22][20002],L[20002],A[32],B[32];
inline int ask(re int l,re int r){
	if(r>n)r=n;
	re int tmp=L[r-l+1];
	if(a[mx[tmp][l]]+mx[tmp][l]>a[mx[tmp][r-(1<<tmp)+1]]+mx[tmp][r-(1<<tmp)+1])return mx[tmp][l];
	return mx[tmp][r-(1<<tmp)+1];
}
int main(){
	n=read(),m=read(),L[0]=-1;
	for(re int i=1;i<=n;++i)a[i]=read(),mx[0][i]=i,L[i]=L[i>>1]+1;
	for(re int i=1;i<=20;++i)
		for(re int j=1;j+(1<<i)-1<=n;++j){
			if(a[mx[i-1][j]]+mx[i-1][j]>a[mx[i-1][j+(1<<i-1)]]+mx[i-1][j+(1<<i-1)])mx[i][j]=mx[i-1][j];
			else mx[i][j]=mx[i-1][j+(1<<i-1)];
		}
	for(re int i=1;i<=n;++i)
		for(re int j=0;j<=30;++j)
			f[i][0][j]=ask(i,i+a[i]+j);
	for(re int i=n;i;--i)
		for(re int j=1;j<=20;++j)
			for(re int k=0;k<=30;++k){
				if(i+(1<<j)>n){f[i][j][k]=n;continue;}
				for(re int x=0;x<=k;++x)
					f[i][j][k]=max(f[i][j][k],f[f[i][j-1][x]][j-1][k-x]);
			}
	while(m--){
		re int l=read(),r=read(),K=read(),ans=0;
		if(l==r){puts("0");continue;}
		if(l+a[l]+K>=r){puts("1");continue;}
		memset(A,0,sizeof(A));
		for(re int i=0;i<=K;++i)A[i]=l;
		for(re int i=20;~i;--i){
			for(re int j=0;j<=K;++j)B[j]=A[j];
			for(re int ii=0;ii<=K;++ii)
				for(re int j=0;j+ii<=K;++j)
					A[ii+j]=max(A[ii+j],f[B[ii]][i][j]);
			re bool ia=0;
			for(re int j=0;j<=K;++j)ia|=A[j]+a[A[j]]+K-j>=r;
			if(ia)for(re int j=0;j<=K;++j)A[j]=B[j];
			else ans+=1<<i;
		}printf("%d\n",ans+2);
	}
}