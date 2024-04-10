#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int m=2e5;
int T,n,c[N],dp[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=m;++i)c[i]=0,dp[i]=0;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		++c[x];
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		dp[i]+=c[i];
		for(int j=i+i;j<=m;j+=i){
			dp[j]=max(dp[j],dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<n-ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}