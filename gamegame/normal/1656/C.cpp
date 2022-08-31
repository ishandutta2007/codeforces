#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
map<ll,int>mp;
ll a[N];
void solve(){
	cin >> n;
	bool h1=false;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]==1) h1=true;
	}
	sort(a+1,a+n+1);
	if(!h1){
		cout << "YES\n";
		return;
	}
	for(int i=1; i<n ;i++){
		if(a[i]==a[i+1]-1){
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