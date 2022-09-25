#include<bits/stdc++.h>
using namespace std;
#define N 10005
typedef long long ll;
int n,a[N],l,r,b[N],ans,dp[N],p[N],H;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		H+=a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return b[i]^b[j]?b[i]<b[j]:a[i]>a[j];});
	int L=H-r,R=H-l;
	memset(dp,~0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;++i){
		int u=p[i];
		for(int j=H;j>=a[u];--j){
			dp[j]=max(dp[j],dp[j-a[u]]+b[u]*(j>=L&&j<=R));
		}
	}
	for(int i=1;i<=H;++i)ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return 0;
}