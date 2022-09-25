#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,_n,a[N],sum;
double x,ans,dp[N][N*N];
int main(){
	n=read(),x=read();
	_n=n;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<=x/2){
			ans+=a[i],--n,--i;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		sum+=a[i];
		for(int j=i;j>=1;--j){
			for(int k=sum;k>=a[i];--k){
				dp[j][k]+=dp[j-1][k-a[i]]*j/(n-j+1);
			}
		}
	}
	x/=2.0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=sum;++j){
			ans+=dp[i][j]*min((_n+i)*x,1.0*j)/i;	
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}