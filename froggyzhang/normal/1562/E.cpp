#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
string s;
int n,p[N],dp[N],z[N][N];
void Solve(){
	cin>>n;
	cin>>s;
	s=' '+s+char(1);
	for(int t=1;t<=n;++t){
		z[t][t]=n-t+1;
		for(int i=t+1,l=0,r=0;i<=n;++i){
			if(i<=r)z[t][i]=min(r-i+1,z[t][i-l+t]);
			else z[t][i]=0;
			while(i+z[t][i]<=n&&s[i+z[t][i]]==s[t+z[t][i]])++z[t][i];
			if(i+z[t][i]-1>r){
				l=i,r=i+z[t][i]-1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		dp[i]=n-i+1;
		for(int j=1;j<i;++j){
			if(s[i+z[j][i]]>s[j+z[j][i]])dp[i]=max(dp[i],dp[j]+n-i+1-z[j][i]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}