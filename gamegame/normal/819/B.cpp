#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
const int N=1e6+1;
ll p[N];
ll dp[N];
ll ddp[N];
ll ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		ans[0]+=abs(p[i]-i);
		if(p[i]>=i){
			ddp[0]--;
			ddp[p[i]-i]++;
			ddp[p[i]-i]++;
			ddp[n-i]--;
			dp[n-i]-=(n-p[i])-(p[i]-1);
			ddp[n-i+1]--;
		}
		else{
			ddp[0]++;
			ddp[n-i]--;
			dp[n-i]-=(n-p[i])-(p[i]-1);
			ddp[n-i+1]--;
			ddp[n-i+p[i]]++;
			ddp[n-i+p[i]]++;
		}
	}
	ll gang=0;
	for(int i=0; i<n ;i++){
		gang+=ddp[i];
		dp[i]+=gang;
	}
	for(int i=1; i<n ;i++){
		ans[i]=ans[i-1]+dp[i-1];
	}
	ll mn=2e18;
	for(int i=0; i<n ;i++){
		mn=min(mn,ans[i]);
	}
	for(int i=0; i<n ;i++){
		if(mn==ans[i]){
			cout << mn << ' ' << i << '\n';
			return 0;
		}
	}
}