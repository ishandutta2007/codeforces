#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
int n,m;
#define Maxn 400010
int len,l;
int r[Maxn];
int C[Maxn],C4[Maxn];
int G[Maxn];//sqrt,sqrt+1
int Ans[Maxn];
int FP(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
void NTT(int *A,int t,int n){
	len=1,l=0;
	while(len<=n)len<<=1,l++;
	for(int i=0;i<len;++i)
	r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<len;++i)
	if(i<r[i])swap(A[i],A[r[i]]);
	for(int i=1;i<len;i<<=1){
		int gn=FP(3,(t*(Mod-1)/(i<<1)+(Mod-1))%(Mod-1));
		for(int j=0;j<len;j+=i<<1){
			int g=1;
			for(int k=0;k<i;++k){
				int x=A[j+k];
				int y=1ll*g*A[j+k+i]%Mod;
				A[j+k]=(x+y)%Mod;
				A[j+k+i]=(x-y+Mod)%Mod;
				g=1ll*g*gn%Mod;
			}
		}
	}
	if(t==-1){
		int inv=FP(len,Mod-2);
		for(int i=0;i<len;++i)A[i]=1ll*A[i]*inv%Mod;
	}
}
void Mul(int *A,int *B,int n){
	NTT(A,1,n);
	NTT(B,1,n);
	for(int i=0;i<len;++i)A[i]=1ll*A[i]*B[i]%Mod;
	NTT(A,-1,n);
}
void Move(int *to,int *fr,int n){
	len=1;l=0;
	while(len<=n)len<<=1,l++;
	for(int i=0;i<n;++i)to[i]=fr[i];
	for(int i=n;i<len;++i)to[i]=0;
}
void Inv(int *Ans,int *A,int n){
	if(n==1){
		Ans[0]=FP(A[0],Mod-2);
		return;
	}
	static int t1[Maxn],t2[Maxn],t3[Maxn];
	Inv(Ans,A,n>>1);
	Move(t1,A,n);
	Move(t2,Ans,n);
	Move(t3,Ans,n);
	Mul(t2,t3,n);
	Mul(t1,t2,n);
	for(int i=0;i<n;++i)Ans[i]=(2ll*Ans[i]-t1[i]+Mod)%Mod;
	for(int i=n;i<n*2;++i)Ans[i]=0;
}
void Sqrt(int *Ans,int *A,int n){
	if(n==1){
		Ans[0]=1;
		return;
	}
	static int t1[Maxn],t2[Maxn],t3[Maxn];
	Sqrt(Ans,A,n>>1);
	Move(t1,Ans,n);
	for(int i=0;i<n;++i)t1[i]=2*t1[i]%Mod;
	Inv(t2,t1,n);
	Move(t3,A,n);
	Mul(t3,t2,n);
	int inv=FP(2,Mod-2);
	for(int i=0;i<n;++i)Ans[i]=(1ll*Ans[i]*inv+t3[i])%Mod;
	for(int i=n;i<n*2;++i)Ans[i]=0;
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar(); }}
int main(){
    len=1;l=0;
	rd(n);rd(m);
	while(len<=m)len<<=1,l++;
	int x;
	for(int i=1;i<=n;++i){
		rd(x);
		C[x]++;
	}
	for(int i=0;i<len;++i){
		C4[i]=4*C[i]%Mod;
		C4[i]=(Mod-C4[i])%Mod;
	}
	C4[0]++;
	if(C4[0]>=Mod)C4[0]-=Mod;
	Sqrt(G,C4,len);
	len=1;l=0;
	while(len<=m)len<<=1,l++;
	G[0]++;
	if(G[0]>=Mod)G[0]-=Mod;
	Inv(Ans,G,len);
	for(int i=1;i<=m;++i)Ans[i]=2ll*Ans[i]%Mod;
	for(int i=1;i<=m;++i)printf("%d\n",Ans[i]);
	return 0;
}