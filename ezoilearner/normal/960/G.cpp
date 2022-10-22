#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=998244353;
int n,f,b;
#define Maxn 200010
int r[Maxn];
int fact[Maxn],inv[Maxn];
int Ans[Maxn];
int len,l;
int t1[Maxn],t2[Maxn];
int t3[Maxn];
int FP(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
void NTT(int *A,int n,int t){
	len=1;l=0;
	while(len<=n)len<<=1,l++;
	for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<len;++i)
	if(i<r[i])swap(A[i],A[r[i]]);
	for(int i=1;i<len;i<<=1){
		int gn=FP(3,(t*(Mod-1)/(i<<1)+Mod-1)%(Mod-1));
		for(int j=0;j<len;j+=i<<1){
			int g=1;
			for(int k=0;k<i;++k){
				int x=A[j+k];
				int y=1ll*A[j+k+i]*g%Mod;
				A[j+k]=(x+y)%Mod;
				A[j+k+i]=(x-y+Mod)%Mod;
				g=1ll*g*gn%Mod;
			}
		}
	}
	if(t==-1){
		int Inv=FP(len,Mod-2);
		for(int i=0;i<len;++i)A[i]=1ll*A[i]*Inv%Mod;
	}
} 
void Mul(int *A,int *B,int n){
	NTT(A,n,1);
	NTT(B,n,1);
	for(int i=0;i<len;++i)A[i]=1ll*A[i]*B[i]%Mod;
	NTT(A,n,-1);
}
void solve(int n){//n 
	if(!n){
		Ans[0]=1;
		return;
	}
	solve(n>>1);
	len=1;
	while(len<=n)len<<=1;
	for(int i=0;i<len;++i)t1[i]=t2[i]=t3[i]=0;
	int now=1;
	for(int i=0;i<=n/2;++i)t1[i]=1ll*Ans[i]*fact[i]%Mod;
	for(int i=0;i<=n/2;++i){
		t2[n/2-i]=1ll*now*inv[i]%Mod;
		now=1ll*now*(n/2)%Mod;
	}
	Mul(t1,t2,n);
	for(int i=(n/2);i<=(n/2)*2;++i)t3[i-n/2]=1ll*t1[i]*inv[i-n/2]%Mod;
	Mul(Ans,t3,n);
	if(n&1)
		for(int i=n;i>=0;--i){
			Ans[i]=1ll*Ans[i]*(n-1)%Mod;
			if(i)Ans[i]=(Ans[i]+Ans[i-1])%Mod;
		}
} 
int main(){
	scanf("%d%d%d",&n,&f,&b);
	n--;
	fact[0]=1;
	for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%Mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=2;i<=n;++i)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
	solve(n);
	printf("%d\n",1ll*Ans[f+b-2]*fact[f+b-2]%Mod*inv[b-1]%Mod*inv[f-1]%Mod);
	return 0;
}