#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
ll mod=998244353;
int n,m,k;
ll c[2001][2001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	c[0][0]=1;
	for(int i=1; i<=2000 ;i++){
		c[i][0]=1;
		for(int j=1; j<=i ;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	ll ans=c[n-1][k];
	for(int i=1; i<=k ;i++){
		ans=ans*(m-1)%mod;
	}
	ans=ans*m%mod;
	cout << ans << endl;
}