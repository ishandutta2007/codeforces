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
	int k=(n+3)/4;
	for(int i=1; i<=n-k ;i++) cout << 9;
	for(int i=1; i<=k ;i++) cout << 8;
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}