#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void solve(){
	cin >> n;
	ll mn=1e9;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		mn=min(mn,a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1; i<=n ;i++){
		if(a[i]==b[i]) continue;
		else if(a[i]%mn!=0){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}