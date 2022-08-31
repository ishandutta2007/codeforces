#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
typedef pair<ll,int> pli;
ll n,m;
pair<ll,int>a[N];
ll l[N],r[N];
ll dp[N];
ll dp2[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll l,r;cin >> l >> r;
		a[2*i-1]={2*l*1e9-r+l,i};
		a[2*i]={2*r*1e9+r-l+1,-i};
		dp[i]=0;
	}
	sort(a+1,a+2*n+1);
	for(int i=1; i<=2*n ;i++){
		//cout << "ord " << a[i].se << endl;
		int x=abs(a[i].se);
		if(a[i].se>0) l[x]=i;
		else r[x]=i;
	}
	for(int i=1; i<=2*n ;i++){
		if(a[i].se>0) continue;
		int x=-a[i].se;
		for(int j=1; j<i ;j++){
			dp2[j]=dp2[j-1];
			if(a[j].se>0) continue;
			int y=-a[j].se;
			if(l[y]<l[x]) continue;
			dp2[j]=max(dp2[j],dp2[l[y]]+dp[y]);
		}
		dp[x]=dp2[i-1]+1;
		//cout << "dp  " << x << ' ' << dp[x] << endl;
	}
	for(int j=1; j<=2*n ;j++){
		dp2[j]=dp2[j-1];
		if(a[j].se>0) continue;
		int y=-a[j].se;
		dp2[j]=max(dp2[j],dp2[l[y]]+dp[y]);
	}
	cout  << dp2[2*n] << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	
}