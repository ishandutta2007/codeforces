#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	if(n<=30) cout << "NO\n";
	else if(n%2==0 && n!=6+10+15+15) cout << "YES\n6 10 15 " << n-31 << '\n'; 
	else cout << "YES\n6 10 14 " << n-30 << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}