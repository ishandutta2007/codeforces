#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,K,jb[N],a[N];
ll dp[N],s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		jb[x]=max(jb[x],y);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=K;++i){
		for(int j=1;j<=i;++j){
			dp[i]=min(dp[i],dp[i-j]+s[i]-s[i-j+jb[j]]);
		}
	}
	cout<<dp[K]<<'\n';
	return 0;
}