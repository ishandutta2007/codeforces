#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	ll f=0,b=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(i==1) continue;
		if(a[i]>a[i-1]) b+=a[i]-a[i-1];
		else f+=a[i-1]-a[i];
	}
	//cout << f << ' ' << b << endl;
	if(a[n]-b>=0) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}