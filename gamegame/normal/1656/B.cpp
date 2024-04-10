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
	cin >> n >> m;
	mp.clear();
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		mp[a[i]]=1;
	}
	bool ok=false;
	for(int i=1; i<=n ;i++){
		ok|=mp[a[i]+m];
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}