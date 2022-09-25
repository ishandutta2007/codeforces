#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
int n,a[N],ans;
void Solve(){
	static int dp[N][2];
	int pos=max_element(a+1,a+n+1)-a;
	pii R=pii(0,0);
	for(int i=n;i>=pos;--i){
		if(a[i]<R.second)return;
		if(a[i]<R.first)R.second=a[i];
		else R.first=a[i];
	}
	memset(dp,0,sizeof(dp));
	dp[pos][1]=R.second;
	dp[pos][0]=-inf;
	for(int i=pos-1;i>=1;--i){
		dp[i][1]=inf,dp[i][0]=-inf;
		if(a[i]<a[i+1])dp[i][1]=min(dp[i][1],dp[i+1][1]);
		if(a[i]<dp[i+1][0])dp[i][1]=min(dp[i][1],a[i+1]);
		if(a[i]>a[i+1])dp[i][0]=max(dp[i][0],dp[i+1][0]);
		if(a[i]>dp[i+1][1])dp[i][0]=max(dp[i][0],a[i+1]);
	}
	pii L=pii(0,0);
	for(int i=1;i<pos;++i){
		if(a[i]<L.second)return;
		if(a[i]<L.first)L.second=a[i];
		else L.first=a[i];
		if(dp[i][0]>(L.first==a[i]?L.second:L.first))++ans;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	Solve();
	reverse(a+1,a+n+1);
	Solve();
	cout<<ans<<'\n';
	return 0;
}