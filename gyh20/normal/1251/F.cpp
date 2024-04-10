#include<bits/stdc++.h>
using namespace std;
typedef int cp;
#define M 998244353
#define re register
cp wi[1100002];
int fac[1100002],inv[1100002],rev[1100002];
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
int n,m,ans[1100002],k,cnt[1100002],s1[1100002],s2[1100002],res[1100002],q;
inline int C(re int n,re int m){
	if(n<m)return 0;
	return 1ll*fac[n]*inv[m]%M*inv[n-m]%M;
}
cp A[1100002],B[1100002];
signed main(){
	n=read(),m=read();k=make((n+1)<<1);
	fac[0]=inv[1]=1;
	for(re int i=1;i<=k;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[k]=ksm(fac[k],M-2);inv[0]=1;
	for(re int i=k-1;i;--i)inv[i]=1ll*(i+1)*inv[i+1]%M;
	for(re int i=1;i<=n;++i)++cnt[read()];
	for(re int i=1;i<=1000000;++i)s1[i]=s1[i-1]+(cnt[i]==1),s2[i]=s2[i-1]+(cnt[i]>1);
	for(re int i=1;i<=m;++i){
		re int x=read(),u=s1[x-1],v=s2[x-1];
		memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
		for(int j=0;j<k;++j)A[j]=1ll*C(u,j)*ksm(2,j)%M,B[j]=C(v<<1,j);
		NTT(A,k,1),NTT(B,k,1);
		for(int j=0;j<k;++j)A[j]=1ll*A[j]*B[j]%M;
		NTT(A,k,-1);
		for(int j=0;j<=n;++j)res[j+x+1]=(res[j+x+1]+A[j])%M;
	}
	q=read();
	while(q--)printf("%d\n",res[read()>>1]);
}