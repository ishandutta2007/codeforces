#include<cstdio>
#include<cstring>
#pragma GCC optimize(2)
using namespace std;

typedef long long ll;
const int N=1e7+100,maxn=1e7,mod=998244353;

int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int fl[N],nf[N],Ntwo=ni(2),g[N],Mi[N],Ni[N];

int main()
{
	
	Ni[0]=nf[0]=1;
	for(int i=1;i<=maxn;i++) Ni[i]=(ll)Ni[i-1]*2%mod;
	for(int i=1;i<=maxn;i++){
		nf[i]=(ll)(Ni[i]-1+mod)*nf[i-1]%mod;
	}
	nf[maxn]=ni(nf[maxn]);
	for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(Ni[i+1]-1+mod)%mod;
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K,X;
		scanf("%d%d%d",&n,&K,&X);
		
		if(n-K>=0) Mi[K+1]=mi(2,n-K);
		else Mi[K+1]=ni(mi(2,K-n));
		for(int i=K;i>=1;i--) Mi[i]=(ll)Mi[i+1]*2%mod;
		
		fl[0]=nf[0]=g[0]=1;
		for(int i=1;i<=K;i++){
			fl[i]=(ll)(Mi[i]-1+mod)*fl[i-1]%mod;
			g[i]=(ll)g[i-1]*(Ni[K]-Ni[i-1]+mod)%mod;
		}
		
		int Ans;
		if(X==0){
			if(n<=K) Ans=g[n];
			else Ans=0;
		}
		else{
			int Sum=0;
			for(int i=0;i<=K&&i<=n;i++){
				Sum=(Sum+(ll)fl[i]*nf[i]%mod*g[i]%mod*(Ni[K]-Ni[i]+mod))%mod;
			}
			Ans=(ll)Sum*ni(Ni[K]-1+mod)%mod;
		}
		printf("%d\n",Ans);
	}
	
	return 0;
}