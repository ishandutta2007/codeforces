#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
#define N 100010
#define M 20
int n,m,cnt[M][M],g[1<<M],dp[1<<M];
string s;
void Solve(){
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n-1;++i){
		++cnt[s[i]-'a'][s[i+1]-'a'];
		++cnt[s[i+1]-'a'][s[i]-'a'];
	}
	for(int i=0;i<(1<<m);++i){
		for(int j=0;j<m;++j){
			if(i>>j&1){
				for(int k=0;k<m;++k){
					if(!(i>>k&1)){
						g[i]+=cnt[j][k];				
					}
				}
			}
		}
	}
	dp[0]=0;
	for(int i=1;i<(1<<m);++i){
		dp[i]=inf;
		for(int j=0;j<m;++j){
			if(i>>j&1){
				dp[i]=min(dp[i],dp[i^(1<<j)]);
			}
		}
		dp[i]+=g[i];
	}
	cout<<dp[(1<<m)-1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}