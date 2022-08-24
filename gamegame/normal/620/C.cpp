#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
map<ll,int>mp;
ll dp[N];
ll prv[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		dp[i]=dp[i-1];
		prv[i]=-1;
		if(mp[x]!=0 && dp[mp[x]-1]+1>dp[i]){
			dp[i]=dp[mp[x]-1]+1;
			prv[i]=mp[x]-1;
		}
		mp[x]=i;
	}
	if(dp[n]==0){
		cout << "-1\n";
		return 0;
	}
	cout << dp[n] << '\n';
	
	vector<int>v;
	v.push_back(n);
	int cur=n;
	while(cur>0){
		if(prv[cur]==-1){
			cur--;
			continue;
		}
		v.push_back(prv[cur]);
		cur=prv[cur];
	}
	reverse(v.begin(),v.end());
	v[0]=0;
	for(int i=0; i<v.size()-1 ;i++){
		cout << v[i]+1 << ' ' << v[i+1] << '\n';
	}
}