#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;int m;
#define maxn 120010
#define pi acos(-1)
const int Mod=1000000007;
const int mod[]={1004535809,998244353,104857601};
int Ans1[3][maxn],Ans2[3][maxn];
int dp[maxn];
int fact[maxn],inv[maxn];
int F1[maxn],F2[maxn];
int r[maxn],l,len;
int Pow(int tmp,int x,int d){
    int ans=1;
    while(x){
        if(x&1)ans=1ll*ans*tmp%d;
        x>>=1;
        tmp=1ll*tmp*tmp%d;
    }
    return ans;
}
struct Ntt{
    int p;
    void ntt(int A[],int t){
    for(int i=0;i<len;++i)
    if(i<r[i])swap(A[i],A[r[i]]);
    for(int i=1;i<len;i<<=1){
       int gn=Pow(3,(t*(p-1)/(i<<1)+p-1)%(p-1),p);
       for(int j=0;j<len;j+=i<<1){
       	  int g=1;
       	  for(int k=0;k<i;++k){
       	  	 int x=A[j+k];
       	  	 int y=1ll*g*A[i+j+k]%p;
       	  	 A[j+k]=(x+y)%p;
       	  	 A[i+j+k]=(x-y+p)%p;
       	  	 g=1ll*g*gn%p;
       	  }
       }	
    }
    if(t==-1){
        int y=Pow(len,p-2,p);
        for(int i=0;i<len;++i)A[i]=1ll*A[i]*y%p;
    }
    }
    void mul(int A[],int B[]){
	    for(int i=0;i<len;++i)A[i]%=p;
	    for(int i=0;i<len;++i)B[i]%=p;
    	ntt(A,1);
    	ntt(B,1);
    	for(int i=0;i<len;++i)A[i]=1ll*A[i]*B[i]%p;
    	ntt(A,-1);
    }
}zjr[3];
ll mul(ll a,ll b,ll D){  
    a=(a%D+D)%D,b=(b%D+D)%D;  
    return ((a*b-(ll)((long double)a/D*b+1e-6)*D)%D+D)%D;  
} 
ll D=1ll*mod[0]*mod[1];
ll inv1=Pow(mod[1],mod[0]-2,mod[0]),inv2=Pow(mod[0],mod[1]-2,mod[1]);
ll inv3=Pow(D%mod[2],mod[2]-2,mod[2]);
int CRT(ll a,ll b,ll c){
	ll C=(mul(a*mod[1],inv1,D)+mul(b*mod[0],inv2,D))%D;
	ll K=((c-C%mod[2]+mod[2])%mod[2])*inv3%mod[2];
	int ans=(K%Mod*(D%Mod)%Mod+C)%Mod;
	return ans;
}
void Mul(int A[],int B[]){
	for(int i=0;i<3;++i){
		for(int j=0;j<len;++j)Ans1[i][j]=A[j],Ans2[i][j]=B[j];
	    zjr[i].mul(Ans1[i],Ans2[i]);
	}
	for(int i=0;i<len;++i)A[i]=CRT(Ans1[0][i],Ans1[1][i],Ans1[2][i]);
}
void init(){
	fact[0]=1;
	for(int i=1;i<=30000;++i)fact[i]=1ll*fact[i-1]*i%Mod;
	inv[1]=1;
	for(int i=2;i<=30000;++i)inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1;
	for(int i=1;i<=30000;++i)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
}
int C(int i,int j){return 1ll*fact[i]*inv[j]%Mod*inv[i-j]%Mod;}
void Solve(ll n){
	if(n==1){
		dp[0]=0;
		for(int i=1;i<=m;++i)dp[i]=1;
		return;
	}
	Solve(n/2);
	for(int i=0;i<len;++i)F1[i]=F2[i]=0;
	for(int i=0;i<=m;++i){
	    F2[i]=1ll*dp[i]*inv[i]%Mod;
		F1[i]=1ll*F2[i]*Pow(2,n/2%(Mod-1)*i%(Mod-1),Mod)%Mod;
	}  
    Mul(F1,F2); 
	for(int i=0;i<=m;++i)dp[i]=1ll*F1[i]*fact[i]%Mod;
	if(n&1){
		for(int i=0;i<len;++i)F1[i]=F2[i]=0;
		for(int i=0;i<=m;++i){
			F2[i]=inv[i]*(i!=0);
			F1[i]=1ll*dp[i]*Pow(2,i,Mod)%Mod*inv[i]%Mod;
		}  
       Mul(F1,F2);
	    for(int i=0;i<=m;++i)dp[i]=1ll*F1[i]*fact[i]%Mod;
	}
}
int main(){
	zjr[0].p=mod[0];zjr[1].p=mod[1];zjr[2].p=mod[2];
	len=1;l=0;
	scanf("%lld%d",&n,&m);
	if(n>m){puts("0");return 0;}
	init();
	while(len<=m*2)len*=2,l++;
	for(int i=0;i<len;++i)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	Solve(n);
	int Zjr=0;
	for(int i=0;i<=m;++i)Zjr=(Zjr+1ll*C(m,i)*dp[i]%Mod)%Mod;
	printf("%d\n",Zjr);
	return 0;
}