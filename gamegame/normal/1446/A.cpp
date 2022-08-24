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
	cin >> n >> m;
	ll w=m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		if(a[i]>w) continue;
		if(a[i]*2>=w){
			cout << "1\n";
			cout << i << '\n';
			return;
		}
	}
	ll s=0;
	vector<int>v;
	for(int i=1; i<=n ;i++){
		if(a[i]>w) continue;
		s+=a[i];
		v.push_back(i);
		if(s*2>=w){
			cout << v.size() << '\n';
			for(auto c:v) cout << c << ' ';
			cout << '\n';
			return;
		}
	}
	cout << "-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}