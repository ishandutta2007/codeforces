#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
ll a[100001],b[100001];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> a[i];
	}
	sort(a+1,a+m+1);
	for(int i=1; i<m ;i++){
		b[i]=a[i+1]-a[i]-1;
	}
	b[m]=n+a[1]-a[m]-1;
	sort(b+1,b+m+1);
	reverse(b+1,b+m+1);
	ll ans=0;
	for(int i=1; i<=m ;i++){
		if(b[i]==4*i-3) ans+=b[i]-1;
		else ans+=b[i]-max(0LL,b[i]-4*i+3);
		//cout << b[i] << ' ' << ans << endl;
	}
	cout << m+ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}