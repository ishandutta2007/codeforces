#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];
char c[51][51];
char d[51][51];
char e[51][51];
int cnt[2][226];
void solve(){
	cin >> n;
	a[0]=a[n+1]=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		if(a[i]>a[i-1] && a[i]>a[i+1]){
			ans+=a[i]-max(a[i-1],a[i+1]);
			a[i]=max(a[i-1],a[i+1]);
		}
	}
	for(int i=1; i<=n+1 ;i++){
		ans+=abs(a[i]-a[i-1]);
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}