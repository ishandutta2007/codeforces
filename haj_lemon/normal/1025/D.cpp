#include<bits/stdc++.h>
#define ll long long
#define N 710
using namespace std;
int gcd(int x,int y){if (y==0)return x;if (x%y==0)return y;return gcd(y,x%y);}
int n,a[N],g[N][N];
bool dp[N][N][2];
int main(){
//	freopen("d.in","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)g[i][j]=gcd(a[i],a[j]);
	for (int i=1;i<=n;i++){
		if (i!=n&&g[i][i+1]>1)dp[i][i][1]=1;
		if (i!=1&&g[i][i-1]>1)dp[i][i][0]=1;
		dp[i][i-1][0]=dp[i][i-1][1]=1;
		dp[i+1][i][0]=dp[i+1][i][1]=1;
	}
	for (int l=2;l<=n;l++){
		for (int i=1;i+l-1<=n;i++){
			for (int j=i;j<=i+l-1;j++){
				if (dp[i][j-1][1]&&dp[j+1][i+l-1][0]){
					dp[i][i+l-1][1]|=(g[j][i+l]!=1);
					dp[i][i+l-1][0]|=(g[j][i-1]!=1);
				}
			}
		}
	}
	if (dp[1][n][1])puts("Yes");else puts("No");
	return 0;
}