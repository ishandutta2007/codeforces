#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define M 103
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,m,P,a[N],s[N],dp[M][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>P;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]%=P;
		s[i]=s[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int j=1;j<=m;++j){
		pair<int,int> mn=make_pair(inf,-1);
		for(int i=1;i<=n;++i){
			mn=min(mn,make_pair(dp[j-1][i-1],i-1));
			dp[j][i]=mn.first+(s[i]-s[mn.second])%P;
		}
	}
	cout<<dp[m][n]<<'\n';
	return 0;
}