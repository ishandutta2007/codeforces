#include<bits/stdc++.h>
#define ll long long
#define N 2010
#define mo 998244353
using namespace std;
ll n,A,B,cg[N],sb[N],dp[N][N],lt[N],an[N];
ll po(ll x,ll y){ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
int main(){
	cin>>n>>A>>B;
	ll Cg=A*po(B,mo-2)%mo,Sb=(1-Cg+mo)%mo;
	cg[0]=1;sb[0]=1;
	for (int i=1;i<=n;i++)cg[i]=cg[i-1]*Cg%mo,sb[i]=sb[i-1]*Sb%mo;
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			dp[i][j]=dp[i-1][j]*cg[j]%mo;
			if (j)dp[i][j]=(dp[i][j]+dp[i-1][j-1]*sb[i-j])%mo;
		}
	}
	lt[1]=1;
	for (int i=2;i<=n;i++){
		lt[i]=1;
		for (int j=1;j<i;j++)lt[i]=(lt[i]+(mo-dp[i][j])*lt[j])%mo;
	}
	an[1]=0;an[0]=0;
	for (int i=2;i<=n;i++){
		for (int j=1;j<i;j++)an[i]=(an[i]+(lt[j]*dp[i][j]%mo)*(an[j]+an[i-j]+j*(i-j)+j*(j-1)/2))%mo;
		an[i]=(an[i]+(lt[i]*dp[i][i]%mo)*(i*(i-1)/2))%mo;
		ll p=(1+(mo-lt[i])*dp[i][i])%mo;
		an[i]=an[i]*po(p,mo-2)%mo;
	}
	cout<<an[n]<<endl;
	return 0;
}