#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
#define fi first
#define se second
int n;
ll f[250001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> mod;
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=i*f[i-1]%mod;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans=(ans+1LL*(n-i+1)*(n-i+1)%mod*f[i]%mod*f[n-i])%mod;
	}
	cout << ans << '\n';
}