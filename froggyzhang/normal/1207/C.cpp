#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=0x1f3f3f3f3f3f3f3fll;
int n,a,b;
ll dp[N][2];
void Solve(){
	cin>>n>>a>>b;
	string s;
	cin>>s;
	s=' '+s;
	dp[0][0]=b,dp[0][1]=inf;
	for(int i=1;i<=n;++i){
		dp[i][0]=dp[i][1]=inf;
		int c=s[i]-'0';
		for(int j=c;j<=1;++j){
			for(int k=c;k<=1;++k){
				dp[i][k]=min(dp[i][k],dp[i-1][j]+(k+1)*b+abs(j-k)*a);
			}
		}
	}
	cout<<1LL*n*a+dp[n][0]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}