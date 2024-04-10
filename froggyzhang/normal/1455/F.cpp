#include<bits/stdc++.h>
using namespace std;
#define N 505
typedef long long ll;
string dp[N],s;
int n,k;
char Get(char c){
	if(c=='a'||c=='a'+k-1)return 'a';
	return c-1;	
}
void Solve(){
	cin>>n>>k>>s;
	s=' '+s;
	dp[1]=Get(s[1]);
	for(int i=2;i<=n;++i){
		char c=Get(s[i]);
		dp[i]=dp[i-1]+c;
		dp[i]=min(dp[i],dp[i-1].substr(0,i-2)+s[i]+dp[i-1].back());
		dp[i]=min(dp[i],dp[i-2]+c+s[i-1]);
		if(i>2)dp[i]=min(dp[i],dp[i-2].substr(0,i-3)+s[i]+dp[i-2].back()+s[i-1]);
	}
	cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}