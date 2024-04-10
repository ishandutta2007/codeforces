#include<bits/stdc++.h>
#define N 2000005
using namespace std;
const int P=1e9+7;
int fac[N],inv[N],prime[N],flag[N];
int T,n,m,ans,i,cnt,j,x,last,sum;
int Pow(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%P)
	  if (b&1) ret=1ll*ret*a%P;
	return ret;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;}
void work(int sum){
	ans=1ll*ans*C(n+sum-1,n-1)%P;
}
int main(){
	n=2000000;
	for (fac[0]=i=1;i<=n;i++) 
	  fac[i]=1ll*fac[i-1]*i%P;
	for (inv[n]=Pow(fac[n],P-2),i=n-1;i>=0;i--) 
	  inv[i]=1ll*inv[i+1]*(i+1)%P;
	for (i=2;i<=n;i++){
		if (!flag[i]) prime[++cnt]=i,flag[i]=i;
		for (j=1;j<=cnt&&prime[j]*i<=n;j++){
			flag[prime[j]*i]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
  scanf("%d",&T);
	while (T--){
	  scanf("%d%d",&m,&n);ans=1;
	  for (x=m,last=0,sum=0;x>1;x/=flag[x])
	    if (flag[x]!=last) work(sum),sum=1,last=flag[x];else sum++;
	  work(sum);
	  ans=1ll*ans*Pow(2,n-1)%P;
	  printf("%d\n",ans);
	}
}