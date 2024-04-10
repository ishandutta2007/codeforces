#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
char s[maxn];
int _,n,ans,a[maxn],dp[maxn][2][2];
void Min(int &x,int y){if (x>y)x=y;}
int main(){
	cin >> _;
	while (_--){
		cin >> s+1; n=strlen(s+1);
        for (int i=0;i<=n;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					dp[i][j][k]=n;
		dp[1][0][0]=0;
		dp[1][1][0]=1;
		for (int i=2;i<=n;i++){
            for (int j=0;j<2;j++)
			for (int k=0;k<2;k++){
				if (j==0&&k==0&&s[i-1]==s[i-2]) continue;
				Min(dp[i][1][j],dp[i-1][j][k]+1);
				if (j==0&&s[i]==s[i-1]) continue;
				if (k==0&&s[i]==s[i-2]) continue;
				Min(dp[i][0][j],dp[i-1][j][k]);
			}
		}
		ans=n;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				Min(ans,dp[n][i][j]);
		cout << ans << endl;
	}
}