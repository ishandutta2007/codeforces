#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll n;
ll a[N];
void solve(){
	cin >> n;
	ll s=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		s+=a[i];
	}
	sort(a+1,a+n+1);
	if(s>=a[n]*2 && s%2==0) cout << "HL\n";
	else cout << "T\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}