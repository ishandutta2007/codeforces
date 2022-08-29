#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
typedef int cp;
#define M 998244353
#define re register
cp wi[262144];
int fac[262144],Inv[262144],ifac[262144],rev[262144];
inline int make(int n){
	int l=ceil(log2(n));n=1<<l;
	for(int i=1;i<n;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
	return n;
}
inline cp ksm(cp x,cp y){
	cp ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
inline cp* NTT(cp A[],int n,int f){
	for(re int i=0;i<n;++i)if(rev[i]<i)swap(A[i],A[rev[i]]);
	for(re int i=1;i<n;i<<=1){
		cp wn=ksm(3,M-1+f*(M-1)/(i<<1));
		wi[0]=1;for(re int j=1;j<i;++j)wi[j]=1ll*wi[j-1]*wn%M;
		for(re int j=0;j<n;j+=i<<1){
			for(re int k=0;k<i;++k){
				cp x=A[j+k],y=1ll*A[j+k+i]*wi[k]%M;
				A[j+k]=((x+y>=M)?(x+y-M):(x+y));A[j+k+i]=((x-y<0)?(x-y+M):(x-y));
			}
		}
	}
	if(f==-1){re int k=ksm(n,M-2);for(re int i=0;i<n;++i)A[i]=1ll*A[i]*k%M;}
	return A;
}
inline int read(){
	int t=0;
	char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void solve(re int A[],re int l,re int r){
	re int len=r-l+1;
	if(len==1){
		A[0]=1,A[1]=M-l;
		return;
	}
	int B[262144],C[262144],k,mid=l+r>>1;
	fill(B,B+((r-l+1)<<1),0);
	fill(C,C+((r-l+1)<<1),0);
	solve(B,l,mid),solve(C,mid+1,r);
    k=make(r-l+2);
	NTT(B,k,1),NTT(C,k,1);
	for(re int i=0;i<k;++i)A[i]=1ll*B[i]*C[i]%M;
	NTT(A,k,-1);
}
int n,m,ans[262144],k;
cp a[262144],b[262144],g[262144];
void Mul(int *f,int *g,int n,int m){	m+=n;n=1;	while(n<m) n<<=1;	for(int i=0;i<n;++i)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);	NTT(f,n,1),NTT(g,n,1);	for(int i=0;i<n;++i)f[i]=1ll*f[i]*g[i]%M;	NTT(f,n,-1);}
void Solve(int *f,int m) {
	if(m==1)return f[1]=1,void(0);
	if(m&1) {
		Solve(f,m-1);
		for(int i=m; i; --i)f[i]=(f[i-1]+1ll*f[i]*(m-1)%M)%M;
		f[0]=1ll*f[0]*(m-1)%M;
	}	else {
		int n=m>>1;
		int res=1;
		Solve(f,n);
		for(int i=0; i<=n; ++i)a[i]=1ll*f[i]*fac[i]%M,b[i]=1ll*res*ifac[i]%M,res=1ll*res*n%M;
		reverse(a,a+n+1);
		Mul(a,b,n+1,n+1);
		for(int i=0; i<=n; ++i)g[i]=1ll*ifac[i]*a[n-i]%M;
		Mul(f,g,n+1,n+1);
		int limit=1;
		while(limit<(n+1)<<1)limit<<=1;
		for(int i=n+1; i<limit; ++i)a[i]=b[i]=g[i]=0;
		for(int i=m+1; i<limit; ++i)f[i]=0;
	}
}
int f[262144],aa,bb;
signed main(){
	n=read()-1;aa=read(),bb=read();m=aa+bb-2;
	if(m<=0)return puts((m<0||n)?"0":"1"),0;
	for(re int i=fac[0]=1;i<=n<<1;++i)fac[i]=1ll*fac[i-1]*i%M;
	ifac[n<<1]=ksm(fac[n<<1],M-2);
	for(re int i=(n<<1)-1;~i;--i)ifac[i]=1ll*ifac[i+1]*(i+1)%M;
	Solve(f,n);if(n==1)f[1]=1;if(n==0)f[0]=1;
	printf("%d",1ll*f[m]*fac[m]%M*ifac[aa-1]%M*ifac[bb-1]%M);
}