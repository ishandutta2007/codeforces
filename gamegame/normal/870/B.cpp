#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N],c[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ll mn=1e18;
	ll mx=-1e18;
	b[0]=mn;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
		b[i]=min(b[i-1],a[i]);
	}
	if(m==1) return cout << mn << '\n',0;
	if(m>=3) return cout << mx << '\n',0;
	ll ans=-1e18;
	mn=1e18;
	for(int i=n; i>=2 ;i--){
		mn=min(mn,a[i]);
		ans=max(ans,max(b[i-1],mn));
	}
	cout << ans << '\n';
}