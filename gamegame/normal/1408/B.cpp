#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,k;
ll a[N];
void solve(){
	int cnt=0;
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(i>1) cnt+=a[i]>a[i-1];
	}
	if(k==1){
		if(cnt==0) cout << "1\n";
		else cout << "-1\n";
		return;
	}
	cout << max(1LL,(cnt+k-2)/(k-1)) << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}