#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[3][N];
ll b[N];
void solve(){
	cin >> n;
	for(int i=0; i<3 ;i++){
		for(int j=0; j<n ;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<n ;i++){
		for(int j=0; j<3 ;j++){
			ll x=a[j][i];
			ll y=b[(i+n-1)%n];
			ll z=b[(i+1)%n];
			if(x!=y && x!=z){
				b[i]=x;
				break;
			}
		}
	}
	for(int i=0; i<n ;i++){
		cout << b[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}