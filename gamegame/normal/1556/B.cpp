#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
ll test(int t){
	int cnt=0;
	ll cost=0;
	for(int i=1; i<=n ;i++){
		if(a[i]%2==t){
			cnt++;
			cost+=abs(i-(2*cnt-1));
		}
	}
	return cost;
}
void solve(){
	cin >> n;
	int c0=0,c1=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]%2==0) c0++;
		else c1++;
	}
	if(abs(c0-c1)>1){
		cout << "-1\n";
		return;
	}
	ll ans=1e18;
	if(c0>=c1) ans=min(ans,test(0));
	if(c1>=c0) ans=min(ans,test(1));
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}