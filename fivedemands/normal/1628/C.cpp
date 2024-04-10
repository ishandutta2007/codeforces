#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
const int iu=1e6+1;
ll n,m,k;
const ll mod=1e9+7;
int a[1002][1002];
void solve(){
	cin >> n;
	for(int i=1; i<=n+1 ;i++){
		for(int j=1; j<=n+1 ;j++){
			a[i][j]=0;
		}
	}
	for(int j=2; j<=n ;j++){
		for(int i=1; i<=n ;i++){
			a[i][j]=a[i-1][j-1]^a[i+1][j-1]^a[i][j-2]^1;
			//cout << i << ' ' << j << ' ' << a[i][j] << ' ';
			
		//cout << endl;
		}
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			int x;cin >> x;
			if(a[i][j]) ans^=x;
		}
	}
	cout << ans << '\n';
}
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
	int t;cin >> t;
	while(t--) solve();
}