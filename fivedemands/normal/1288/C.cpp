#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll c[2001][2001];
void fuckcarrielam(){
	c[0][0]=1;
	for(int i=1; i<=2000 ;i++){
		for(int j=1; j<=i ;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
		c[i][0]=1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	fuckcarrielam();
	ll n,m;cin >> n >> m;
	ll ans=0;
	cout << c[n+2*m-1][2*m] << '\n';
}