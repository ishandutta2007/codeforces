#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,a[N];
ll s[N],dp[N][500];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n+1;++i){
		memset(dp[i],~0x3f,sizeof(dp[i]));
	}
	int ans=1;
	for(int i=n;i>=1;--i){
		dp[i][1]=max(dp[i+1][1],(ll)a[i]);
		for(int j=2;j<=min(n-i+1,499);++j){
			dp[i][j]=max(dp[i][j],dp[i+1][j]);
			if(s[i+j-1]-s[i-1]<dp[i+j][j-1]){
				dp[i][j]=max(dp[i][j],s[i+j-1]-s[i-1]);
			}
			if(dp[i][j]>=0)ans=max(ans,j);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}