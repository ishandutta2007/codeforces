#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int Mod=1000000007;
const int inv=500000004;
int n;
#define Maxn 131072
#define V 18
int bitscount[Maxn];
int fibs[Maxn];
int s[Maxn];
int A[Maxn],B[Maxn],C[Maxn];
int fx[V][Maxn],fy[V][Maxn];
int Ans[Maxn];
void FWT1(int *A,int n){
	for(int i=2;i<=n;i<<=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=(x+y)%Mod;
		A[j+k+i/2]=(x-y+Mod)%Mod;
	}
}
void UFWT1(int *A,int n){
	for(int i=n;i>=2;i>>=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=1ll*(x+y)*inv%Mod;
		A[j+k+i/2]=1ll*(x-y+Mod)*inv%Mod;
	}
}
void FWT2(int *A,int n){
	for(int i=2;i<=n;i<<=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=(x+y)%Mod;
		A[j+k+i/2]=y;
	}
}
void UFWT2(int *A,int n){
	for(int i=n;i>=2;i>>=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=(x-y+Mod)%Mod;
		A[j+k+i/2]=y;
	}
}
void FWT3(int *A,int n){
	for(int i=2;i<=n;i<<=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=x;
		A[j+k+i/2]=(x+y)%Mod;
	}
}
void UFWT3(int *A,int n){
	for(int i=n;i>=2;i>>=1)
	for(int j=0;j<n;j+=i)
	for(int k=0;k<i/2;++k){
		int x=A[j+k];
		int y=A[j+k+i/2];
		A[j+k]=x;
		A[j+k+i/2]=(y-x+Mod)%Mod;
	}
}
void FST(){
	for(int i=1;i<Maxn;++i)bitscount[i]=bitscount[i>>1]+(i&1?1:0);
	for(int i=0;i<Maxn;++i)fx[bitscount[i]][i]=s[i];
	for(int i=0;i<V;++i)FWT3(fx[i],Maxn);
	for(int i=0;i<V;++i)
	for(int j=0;j<=i;++j)
	for(int k=0;k<Maxn;++k)
	fy[i][k]=(fy[i][k]+1ll*fx[j][k]*fx[i-j][k])%Mod;
	for(int i=0;i<V;++i)UFWT3(fy[i],Maxn);
	for(int i=0;i<Maxn;++i){
	    C[i]=fy[bitscount[i]][i];
	    C[i]=1ll*C[i]*fibs[i]%Mod;
    }
}
void rd(int &x){x=0;char ch=getchar();while(ch<'0'||ch>'9')ch=getchar();while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}}
int main(){
	fibs[0]=0;fibs[1]=1;
	for(int i=2;i<Maxn;++i)fibs[i]=(fibs[i-2]+fibs[i-1])%Mod;
	rd(n);
	int x;
	for(int i=1;i<=n;++i){
		rd(x);
		s[x]++;
	}
	for(int i=0;i<Maxn;++i)A[i]=s[i];
	FWT1(A,Maxn);
	for(int i=0;i<Maxn;++i)A[i]=1ll*A[i]*A[i]%Mod;
	UFWT1(A,Maxn);
	for(int i=0;i<Maxn;++i)A[i]=1ll*A[i]*fibs[i]%Mod;
	for(int i=0;i<Maxn;++i)B[i]=s[i];
	for(int i=0;i<Maxn;++i)B[i]=1ll*B[i]*fibs[i]%Mod;
	FST();
	FWT2(A,Maxn);
	FWT2(B,Maxn);
	FWT2(C,Maxn);
	for(int i=0;i<Maxn;++i)Ans[i]=1ll*A[i]*B[i]%Mod*C[i]%Mod;
	UFWT2(Ans,Maxn);
	int zjr=0;
	for(int i=0;i<=16;++i)zjr=(zjr+Ans[1<<i])%Mod;
	printf("%d\n",zjr);
	return 0;
}