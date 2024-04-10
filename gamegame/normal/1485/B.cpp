#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,q,k;
ll a[N],b[N];
void solve(){
	cin >> n >> q >> k;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		cout << k-(r-l)*2+a[r]-a[l]-1 << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	solve();
	//int t;cin >> t;while(t--) solve();
}