#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1000000007;
int n,k,S[5005][5005],ans=0;
int Power(int x,int y,int mod) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&k);
	S[0][0]=1;
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=k; j++) {
			S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mod;
		}
	}
	for(int i=0;i<=k&&i<=n;i++){
		int tmp=1;
		for(int j=n;j>n-i;j--)tmp=1ll*tmp*j%mod;
		ans=(ans+1ll*tmp*S[k][i]%mod*Power(2,n-i,mod)%mod)%mod;
	}
	printf("%d\n",ans);
}