#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define re register
const int M=998244353;
int rev[524288],wi[524288];
inline int make(int n){
	int l=ceil(log2(n));n=1<<l;
	for(int i=1;i<n;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
	return n;
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
inline void NTT(int *A,int n,int f){
	for(re int i=0;i<n;++i)if(rev[i]<i)swap(A[i],A[rev[i]]);
	for(re int i=1;i<n;i<<=1){
		re int wn=ksm(3,M-1+f*(M-1)/(i<<1));
		wi[0]=1;for(re int j=1;j<i;++j)wi[j]=1ll*wi[j-1]*wn%M;
		for(re int j=0;j<n;j+=i<<1){
			for(re int k=0;k<i;++k){
				re int x=A[j+k],y=1ll*A[j+k+i]*wi[k]%M;
				A[j+k]=((x+y>=M)?(x+y-M):(x+y));A[j+k+i]=((x-y<0)?(x-y+M):(x-y));
			}
		}
	}
	if(f==-1){re int k=ksm(n,M-2);for(re int i=0;i<n;++i)A[i]=1ll*A[i]*k%M;}
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
int p[100002],P[100002];
inline void solve(re int *A,re int *A1,re int l,re int r){
	re int len=r-l+1;
	if(len==1){
		A[0]=1,A[1]=p[l];
		A1[0]=P[l];
		return;
	}
	int B[(r-l+2)<<1],C[(r-l+2)<<1],k,mid=l+r>>1,B1[(r-l+2)<<1],C1[(r-l+2)<<1];
	memset(B,0,sizeof(B)),memset(C,0,sizeof(C)),memset(B1,0,sizeof(B1)),memset(C1,0,sizeof(C1));
	solve(B,B1,l,mid),solve(C,C1,mid+1,r);
    k=make((r-l+1)+1);
	NTT(B,k,1),NTT(C,k,1),NTT(B1,k,1),NTT(C1,k,1);
	for(re int i=0;i<k;++i)A[i]=1ll*B[i]*C[i]%M,A1[i]=(1ll*B1[i]*C[i]+1ll*B[i]*C1[i])%M;
	NTT(A,k,-1),NTT(A1,k,-1);
}
int pool[3200002],n,k,head[100002],cnt,*F[100002],*cur=pool,du[100002],*G[100002],S[100002],sum[100002],fac[100002],inv[100002],siz[100002],ans;
struct edge{int to,next;}e[200002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++du[x],++du[y];}
inline void dfs(re int x,re int y){
	F[x]=cur,cur+=du[x]*4,G[x]=cur,cur+=du[x]*4,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x),siz[x]+=siz[e[i].to],add(sum[x],sum[e[i].to]);
	re int num=0;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)++num,p[num]=siz[e[i].to],P[num]=sum[e[i].to];
	if(num)solve(F[x],G[x],1,num);
	else F[x][0]=1;
	for(re int i=num;i;--i)G[x][i]=(1ll*G[x][i-1]*(n-siz[x])+G[x][i])%M;
	for(re int i=0;i<=min(num,k);++i)add(S[x],1ll*fac[k]*inv[k-i]%M*F[x][i]%M),add(ans,1ll*fac[k]*inv[k-i]%M*G[x][i]%M);
	add(ans,M-1ll*S[x]*sum[x]%M),add(sum[x],S[x]);
}
int main(){
	n=read(),k=read();if(k==1)return printf("%lld",1ll*n*(n-1)/2%M),0;if(n==1)return puts("0"),0;
	for(re int i=fac[0]=1;i<=k;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[k]=ksm(fac[k],M-2);
	for(re int i=k-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	dfs(1,1);
	for(re int i=2;i<=n;++i)add(ans,1ll*S[i]*S[i-1]%M),add(S[i],S[i-1]);
	printf("%d",ans);
}