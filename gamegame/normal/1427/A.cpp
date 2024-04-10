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
	m=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		m+=a[i];
	}
	if(m==0){
		cout << "NO\n";return;
	}
	sort(a+1,a+n+1);
	if(m>0){
		
		reverse(a+1,a+n+1);
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}