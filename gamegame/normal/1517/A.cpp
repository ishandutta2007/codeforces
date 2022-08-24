#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	if(n%2050!=0){
		cout << "-1\n";return;
	}
	n/=2050;
	ll ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}