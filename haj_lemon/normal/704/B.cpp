#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
#define N 10010
using namespace std;
struct Info{ll a,b,c,d,x;}a[N];
ll dp[N][2];
int n,s,t;
int main(){
	cin>>n>>s>>t;
	for (int i=1;i<=n;i++)cin>>a[i].x;
	for (int i=1;i<=n;i++)cin>>a[i].a;
	for (int i=1;i<=n;i++)cin>>a[i].b;
	for (int i=1;i<=n;i++)cin>>a[i].c;
	for (int i=1;i<=n;i++)cin>>a[i].d;
	for (int i=1;i<=n;i++)a[i].a+=a[i].x,a[i].c+=a[i].x,a[i].b-=a[i].x,a[i].d-=a[i].x;
	for (int i=0;i<=n*2;i++)dp[i][0]=dp[i][1]=INF;
	dp[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			if (i==s){
				dp[j+1][1]=min(dp[j+1][1],dp[j][0]+a[i].d);
				if (j>0)dp[j][1]=min(dp[j][1],dp[j][0]+a[i].c);
			}
			if (i==t){
				dp[j+1][1]=min(dp[j+1][1],dp[j][0]+a[i].b);
				if (j>0)dp[j][1]=min(dp[j][1],dp[j][0]+a[i].a);
			}
			if (i!=s&&i!=t){
				int g;
				if (i>max(s,t)) g=1;else g=0;
				if (i<max(s,t)||j>1)dp[j+1][1]=min(dp[j+1][1],dp[j][0]+a[i].b+a[i].d);
				if (j>g){
					if (j>1||i<s)dp[j][1]=min(dp[j][1],dp[j][0]+a[i].b+a[i].c);
					if (j>1||i<t)dp[j][1]=min(dp[j][1],dp[j][0]+a[i].a+a[i].d);
				}
				if (j>1){
					dp[j-1][1]=min(dp[j-1][1],dp[j][0]+a[i].a+a[i].c);
				}
			}
		}
		for (int j=0;j<=i;j++)dp[j][0]=dp[j][1],dp[j][1]=INF;
	}
	cout<<dp[1][0]<<endl;
	return 0;
}