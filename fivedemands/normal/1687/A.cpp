#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]=b[i-1]+a[i];
	}
	if(m>=n){
		ll ans=m*(m-1)/2-(m-n)*(m-n-1)/2;
		ans+=b[n];
		cout << ans << '\n';
	}
	else{
		ll ans=0;
		for(int i=m; i<=n ;i++){
			ans=max(ans,b[i]-b[i-m]);
		}
		ans+=m*(m-1)/2;
		cout << ans << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}