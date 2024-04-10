#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=3001;
const int K=3001;
const int iu=20;
ll n,k;
vector<int>a[N];
ll b[N];
vector<ll>last[K];
ll dp[K];
ll ans=0;
void solve(int l,int r){
	//cout << "Solve " << l << ' ' << r << endl;
	//for(int i=0; i<=k ;i++) cout << last[i].back() << ' ';
	//cout << endl;
	if(l==r){
		ll s=0;
		for(int i=0; i<=a[l].size() ;i++){
			//cout << l << ' ' << i << ' ' << s+last[k-i].back() << endl;
			ans=max(ans,s+last[k-i].back());
			if(i==a[l].size()) break;
			s+=a[l][i];
		}
		return;
	}
	int mid=(l+r)/2;
	for(int i=0; i<=k ;i++) dp[i]=last[i].back();
	for(int i=mid+1; i<=r ;i++){
		for(int j=k; j>=a[i].size() ;j--){
			dp[j]=max(dp[j],dp[j-a[i].size()]+b[i]);
		}
	}
	for(int i=0; i<=k ;i++) last[i].push_back(dp[i]);
	solve(l,mid);
	for(int i=0; i<=k ;i++) last[i].pop_back();
	
	for(int i=0; i<=k ;i++) dp[i]=last[i].back();
	for(int i=l; i<=mid ;i++){
		for(int j=k; j>=a[i].size() ;j--){
			dp[j]=max(dp[j],dp[j-a[i].size()]+b[i]);
		}
	}
	for(int i=0; i<=k ;i++) last[i].push_back(dp[i]);
	solve(mid+1,r);
	for(int i=0; i<=k ;i++) last[i].pop_back();
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		ll t;cin >> t;
		a[i].resize(t);
		for(auto &c:a[i]){
			cin >> c;
		}
		a[i].resize(min(t,k));
		for(int j=0; j<a[i].size() ;j++) b[i]+=a[i][j];
	}
	for(int i=0; i<=k ;i++) last[i].push_back(0);
	solve(1,n);
	cout << ans << '\n';
}