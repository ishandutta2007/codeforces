#include <cstdio>
#include <cstring>
#include <algorithm>

int n, h[5005];
int dp[5005][5005][2];
/*dp[i][j][k]ijk

k=0:
k=1:i-2
dp[1][0][0]=0
*/

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i) scanf("%d", &h[i]);
	std::memset(dp, 127, sizeof(dp));
	dp[1][0][0]=0;
	h[0]=-999999; h[n+1]=-999999;
	h[n+2]=-9999999;
	for (int i=1;i<=n+2;++i) {
		for (int j=0;j<=((i)>>1);++j) {
			//if (i==5&&j==2) printf("!");
			//printf("|%d %d|", dp[i][j][0], dp[i][j][1]);
			dp[i+1][j][0]=std::min(dp[i][j][0], dp[i+1][j][0]);
			dp[i+1][j][0]=std::min(dp[i][j][1], dp[i+1][j][0]);
			if (h[i-1]<h[i]) {
				if (h[i+1]<h[i]) {
					
					dp[i+2][j+1][0]=std::min(dp[i+2][j+1][0], dp[i][j][0]);
				//	if (i==3&&j==1) printf("!%d %d\n", dp[i][j][0], dp[5][2][0]);
				}
				else dp[i+2][j+1][1]=std::min(dp[i+2][j+1][1], dp[i][j][0]+h[i+1]-h[i]+1);
			}else {
				if (h[i+1]<h[i]) dp[i+2][j+1][0]=std::min(dp[i+2][j+1][0], dp[i][j][0]+h[i-1]-h[i]+1);
				else dp[i+2][j+1][1]=std::min(dp[i+2][j+1][1], dp[i][j][0]+h[i+1]-h[i]+1+h[i-1]-h[i]+1);
			}if (i==1) continue;
			if (h[i-2]<=h[i]) {
				if (h[i+1]<h[i]) dp[i+2][j+1][0]=std::min(dp[i+2][j+1][0], dp[i][j][1]);
				else dp[i+2][j+1][1]=std::min(dp[i+2][j+1][1], dp[i][j][1]+h[i+1]-h[i]+1);
			} else {
				if (h[i+1]<h[i]) dp[i+2][j+1][0]=std::min(dp[i+2][j+1][0], dp[i][j][1]+h[i-2]-h[i]);
				else dp[i+2][j+1][1]=std::min(dp[i+2][j+1][1], dp[i][j][1]+h[i-2]-h[i]+h[i+1]-h[i]+1);
			}
		}//printf("\n");
	} for (int i=1;i<=((n+1)>>1);++i) printf("%d ", std::min(dp[n+2][i][0], dp[n+2][i][1]));
	return 0;
}