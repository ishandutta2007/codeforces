#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
ll ans=1;
int n,m;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int a[200001];
int b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> b[i];
	}
	ll ans=0;
	ll eq=1;
	ll invm=pw(m,mod-2);
	for(int i=1; i<=n ;i++){
		if(a[i]!=0 && b[i]!=0){
			if(a[i]<b[i]) break;
			if(a[i]>b[i]){
				ans=(ans+eq)%mod;break;
			}
			continue;
		}
		else if(a[i]!=0){
			ans=(ans+eq*(a[i]-1)%mod*invm)%mod;
			eq=(eq*invm)%mod;
		}
		else if(b[i]!=0){
			ans=(ans+eq*(m-b[i])%mod*invm)%mod;
			eq=(eq*invm)%mod;
		}
		else{
			ans=(ans+eq*(m-1)%mod*invm%mod*(mod+1)/2)%mod;
			eq=(eq*invm)%mod;
		}
	}
	cout << ans << '\n';
}