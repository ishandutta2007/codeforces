#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
void solve(){
	cin >> n >> m;
	if(n<m){
		cout << m-n << '\n';
	}
	else if(n%2!=m%2) cout << "1\n";
	else cout << "0\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}