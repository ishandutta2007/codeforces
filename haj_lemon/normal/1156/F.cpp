#include<bits/stdc++.h>
#define ll long long
#define mo 998244353
#define N 5010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll dp[N][N],a[N],n,jie[N],an[N],x,ansn;
ll po(ll x,ll y){ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
int main(){
	read(n);
	for (int i=1;i<=n;i++){read(x);a[x]++;}
	dp[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			dp[i][j]=dp[i-1][j];
			if (j)dp[i][j]=(dp[i][j]+dp[i-1][j-1]*a[i])%mo;
			if (j){an[j+1]=(an[j+1]+(dp[i-1][j-1]*a[i]%mo)*(a[i]-1))%mo;}
		}
	}
	jie[0]=1;
	for (int i=1;i<=n;i++) jie[i]=jie[i-1]*i%mo;
	for (int i=1;i<=n;i++)ansn=(ansn+an[i]*jie[n-i])%mo;
	cout<<ansn*po(jie[n],mo-2)%mo<<endl;
	return 0;
}