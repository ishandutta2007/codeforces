#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	a[0]=0;
	int ans=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]<=a[i-1]){
			a[i]++;ans+=a[i]>a[i-1];
		}
		else if(a[i]!=a[i-1]) ans++;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}