#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5010,maxn=5000;
int C[N][N],f[N][N],n,mod,fl[N],nf[N],Mi[N][N];

int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int main()
{
	
	scanf("%d%d",&n,&mod);
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	for(int i=0;i<=maxn;i++) C[i][0]=C[i][i]=1;
	for(int i=2;i<=maxn;i++)
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		
	for(int i=0;i<=n;i++){
		Mi[i][0]=1;
		for(int j=1;j<=n;j++) Mi[i][j]=(ll)Mi[i][j-1]*i%mod;
	}
		
	int Ans=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i/2;j++){
			int t=(ll)fl[i]*C[i-j-1][j-1]%mod*nf[j]%mod;
			Ans=(Ans+(ll)t*C[n][i]%mod*Mi[n-1][j]%mod*Mi[i-j][n-i])%mod;
		}
		
	printf("%d\n",Ans);
	
	return 0;
}