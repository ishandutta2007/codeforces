#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=4e5+100,maxn=4e5,mod=1e9+7;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int a[N],fl[N],nf[N];

int C(int n,int m){
	if(n<m) return 0;
	return (ll)fl[n]*nf[m]%mod*nf[n-m]%mod;
}

int main()
{
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	if(a[0]==0){
		printf("0\n");
		return 0;
	}
	
	int Ans=0;
	for(int i=0;i<=n;i++){
		if(a[i]>0){
			Ans=(Ans+C(a[i]-1+i,i))%mod;
		}
		for(int j=a[i+1];j<a[i];j++){
			Ans=(Ans+C(j+i,i))%mod;
		}
	}
	
	printf("%d\n",(Ans-1+mod)%mod);
	
	return 0;
}