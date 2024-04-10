#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
typedef array<ll,3> out;
vector<out>ans;
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	cout << 3*n << '\n';
	for(int i=1; i<=n ;i+=2){
		for(int j=1; j<=3 ;j++){
			cout << "1 " << i << ' ' << i+1 << '\n';
			cout << "2 " << i << ' ' << i+1 << '\n';
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}