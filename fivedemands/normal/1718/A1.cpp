#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
ll dp[N];
void solve(){
	cin >> n;
	map<ll,ll>mp;
	mp[0]=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		b[i]=b[i-1]^a[i];
		dp[i]=dp[i-1];
		if(b[i]==0) dp[i]=max(dp[i],dp[mp[0]]+1);
		else if(mp[b[i]]!=0) dp[i]=max(dp[i],dp[mp[b[i]]]+1);
		mp[b[i]]=i;
	}
	cout << n-dp[n] << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}