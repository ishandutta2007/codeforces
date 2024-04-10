#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
int n;
ll ans,dp[N][N];
struct Loan{
	int A,B,k;	
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].A>>a[i].B>>a[i].k;
	}
	sort(a+1,a+n+1,[&](Loan x,Loan y){return x.B>y.B;});
	memset(dp,~0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		ll w=max(0LL,a[i].A-1LL*a[i].B*a[i].k);
		dp[i][0]=dp[i-1][0]+w;
		for(int j=1;j<=i;++j){
			dp[i][j]=max(dp[i-1][j],max(dp[i-1][j]+w,dp[i-1][j-1]+a[i].A-1LL*a[i].B*min(j-1,a[i].k)));
			ans=max(ans,dp[i][j]);	
		}
	}
	cout<<ans<<'\n';
	return 0;
}