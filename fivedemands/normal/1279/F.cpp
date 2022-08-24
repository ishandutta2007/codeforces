#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,k,le;
vector<int>v[2];
ll dp[1000001];
ll pf[1000001];
int cnt[1000001];
ll a[1000001];
void doo(int mid){
	for(int i=1; i<=n ;i++){
		dp[i]=dp[i-1];
		cnt[i]=cnt[i-1];
		int prv=max(0,i-le);
		if(dp[i]<dp[prv]+pf[i]-pf[prv]-mid || dp[i]==dp[prv]+pf[i]-pf[prv]-mid && cnt[i]>cnt[prv]+1){
			dp[i]=dp[prv]+pf[i]-pf[prv]-mid;
			cnt[i]=cnt[prv]+1;
		}
	}
}
ll ans=1e9;
void solve(vector<int>&v){
	for(int i=1; i<=n ;i++) a[i]=1;
	for(int i=0; i<v.size() ;i++) a[v[i]]=0;
	for(int i=1; i<=n ;i++) pf[i]=pf[i-1]+a[i];
	int l=0,r=n;
	doo(0);
	if(cnt[n]<=k){
		ans=0;
		return;
	}
	while(l!=r){
		int mid=(l+r)/2;
		doo(mid);
		if(cnt[n]>k) l=mid+1;
		else r=mid;
	}
	doo(l);
	//cout << dp[n]+(k-cnt[n])*l << '\n';
	ll duh=dp[n]+k*l;
	ans=min(ans,n-(ll)v.size()-duh);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> le;
	for(int i=1; i<=n ;i++){
		char c;
		cin >> c;
		if(c>='a') v[0].push_back(i);
		else v[1].push_back(i);
	}
	solve(v[0]);solve(v[1]);
	cout << ans << '\n';
}