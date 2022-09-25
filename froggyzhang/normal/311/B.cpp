#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,K,d[N],a[N];
ll s[N],dp[102][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	for(int i=2;i<=n;++i){
		cin>>d[i];
		d[i]+=d[i-1];
	}
	for(int i=1,p;i<=m;++i){
		cin>>p>>a[i];
		a[i]-=d[p];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		s[i]=s[i-1]+a[i];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	K=min(K,m);
	for(int i=1;i<=K;++i){
		static int q[N],l,r;
		q[l=r=1]=0;
		auto X=[&](int p)->double{
			return p;
		};
		auto Y=[&](int p)->double{
			return dp[i-1][p]+s[p];
		};
		for(int j=1;j<=m;++j){
			while(l<r&&a[j]>=(Y(q[l+1])-Y(q[l]))/(X(q[l+1])-X(q[l])))++l;
			dp[i][j]=dp[i-1][q[l]]+1LL*(j-q[l])*a[j]-(s[j]-s[q[l]]);
			while(l<r&&(Y(q[r])-Y(q[r-1]))/(X(q[r])-X(q[r-1]))>=(Y(j)-Y(q[r-1]))/(X(j)-X(q[r-1])))--r;
			q[++r]=j;
			/*
			for(int k=0;k<j;++k){
				dp[i][j]=min(dp[i][j],dp[i-1][k]+1LL*(j-k)*a[j]-(s[j]-s[k]));
			}
			*/
		}
	}
	cout<<dp[K][m]<<'\n';
	return 0;
}