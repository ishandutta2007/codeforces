#include<cstdio>
#include<iostream>
#include<cstring>
#define M 998244353
#define re register
using namespace std;
inline int read(){
	int t=0;
	char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int ksm(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
int rev[200002],L,wi[200002];
inline int* NTT(int A[],int n,int f){
	for(re int i=0;i<n;++i)if(rev[i]<i)swap(A[i],A[rev[i]]);
	for(re int i=1;i<n;i<<=1){
		int wn=ksm(3,M-1+f*(M-1)/(i<<1));
		wi[0]=1;for(re int j=1;j<i;++j)wi[j]=1ll*wi[j-1]*wn%M;
		for(re int j=0;j<n;j+=i<<1){
			for(re int k=0;k<i;++k){
				int x=A[j+k],y=1ll*A[j+k+i]*wi[k]%M;
				A[j+k]=((x+y>=M)?(x+y-M):(x+y));A[j+k+i]=((x-y<0)?(x-y+M):(x-y));
			}
		}
	}
	if(f==-1){re int k=ksm(n,M-2);for(re int i=0;i<n;++i)A[i]=1ll*A[i]*k%M;}
	return A;
}
int A[200002],B[200002],C[200002],n1[200002],n2[200002],n3[200002],s1[200002],s2[200002],s3[200002],s4[200002],s5[200002],n,K;
void update(int len){
	memcpy(n1,A,sizeof(n1));memcpy(n2,B,sizeof(n2));memcpy(n3,C,sizeof(n3));
	NTT(n1,len,1);NTT(n2,len,1);NTT(n3,len,1);
	for(int i=0;i<len;i++)s1[i]=1ll*n1[i]*n1[i]%M;
	for(int i=0;i<len;i++)s2[i]=1ll*n2[i]*n2[i]%M;
	for(int i=0;i<len;i++)s3[i]=1ll*n1[i]*n2[i]%M;
	for(int i=0;i<len;i++)s4[i]=1ll*n2[i]*n3[i]%M;
	for(int i=0;i<len;i++)s5[i]=1ll*n3[i]*n3[i]%M;
	NTT(s1,len,-1);NTT(s2,len,-1);NTT(s3,len,-1);NTT(s4,len,-1);NTT(s5,len,-1);
	for(int i=1;i<=K;i++)A[i]=(s1[i]+s2[i-1])%M;A[0]=s1[0];
	for(int i=1;i<=K;i++)B[i]=(s3[i]+s4[i-1])%M;B[0]=s3[0];
	for(int i=1;i<=K;i++)C[i]=(s2[i]+s5[i-1])%M;C[0]=s2[0];
}
int tmp[200002],t1[200002];
void vio(int ok){
	memcpy(tmp,A,sizeof(tmp));
	for(int i=1;i<=min(K,ok);++i)A[i]=(0ll+A[i]+tmp[i-1]+B[i-1])%M;
	memcpy(t1,B,sizeof(t1));memcpy(B,tmp,sizeof(B));memcpy(C,t1,sizeof(C));
}
int gets(int u){int ret=0;for(;u;u>>=1)ret++;return ret;}
int main(){
	n=read();K=read();
	int ln=1;
	for(ln=1;ln<=2*K;ln<<=1)L++;
	for(int i=0;i<ln;++i)rev[i]=(rev[i>>1]>>1)|(i&1)<<(L-1);
	A[0]=1;
	int lg=gets(n);int sum=0;
	for(int i=lg-1;~i;--i){
		update(ln);sum<<=1;
		if(sum==2)C[1]=0;
		if(n&(1<<i))sum|=1,vio(sum);
	}
	for(int i=1;i<=K;++i)printf("%d ",A[i]);
}