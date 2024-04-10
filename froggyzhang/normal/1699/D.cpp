#include<bits/stdc++.h>
using namespace std;
#define N 5005
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],dp[N],cnt[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n+1;++i){
		dp[i]=-inf;
		int mx=0;
		for(int j=i-1;j>=0;--j){
			if((i-j)&1){
				if(mx<=(i-j)/2&&(a[i]==a[j]||!j||i>n)){
					dp[i]=max(dp[j]+1,dp[i]);
				}
			}
			mx=max(mx,++cnt[a[j]]);
		}
		for(int j=0;j<i;++j){
			--cnt[a[j]];
		}
	}
	cout<<dp[n+1]-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}