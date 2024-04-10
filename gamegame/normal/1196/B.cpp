#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n,m;
ll a[N];
void solve(){
	cin >> n >> m;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		cnt+=a[i]%2;
	}
	if(cnt<m || cnt%2!=m%2) {
		cout << "NO\n";return;
	}
	cout << "YES\n";
	int r=0;
	for(int i=1; i<=n ;i++){
		if(r==m-1) break;
		if(a[i]%2==1){
			cout << i << ' ';
			r++;
		}
		if(r==m-1) break;
	}
	cout << n << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}