#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
#define PB push_back
#define ST first
#define ND second

const int nax = 60;
int n;
ll dp[nax][nax][nax][nax];
int p[nax][nax];
bool t[nax][nax];

int get_sum(int x1,int y1,int x2,int y2) {
	return p[x2][y2] + p[x1-1][y1-1] - p[x2][y1-1] - p[y2][x1-1];
}

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n;i++) {
		for(int j=1; j<=n;j++) {
			char c; scanf(" %c",&c);
			if(c=='#') t[i][j] = 1;
			p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+t[i][j];
		}
	}
	for(int wth = 1; wth<=n; wth++) {
		for(int hgh = 1; hgh<=n; hgh++) {
			for(int i=1; i+hgh-1<=n; i++) {
				for(int j=1; j+wth-1<=n; j++) {
					if(hgh>=wth) {
						dp[i][j][i+hgh-1][j+wth-1] = hgh;
						for(int k = i; k<i+hgh; k++) {
							if(p[k][j+wth-1]-p[k][j-1]-p[k-1][j+wth-1]+p[k-1][j-1]==0) {
								dp[i][j][i+hgh-1][j+wth-1] = min(dp[i][j][i+hgh-1][j+wth-1],dp[i][j][k-1][j+wth-1]+dp[k+1][j][i+hgh-1][j+wth-1]);
							}
						}
					} else {
						dp[i][j][i+hgh-1][j+wth-1] = wth;
						for(int k=j; k<j+wth; k++) {
							if(p[i+hgh-1][k]-p[i-1][k]-p[i+hgh-1][k-1]+p[i-1][k-1]==0) {
								dp[i][j][i+hgh-1][j+wth-1] = min(dp[i][j][i+hgh-1][j+wth-1],dp[i][j][i+hgh-1][k-1]+dp[i][k+1][i+hgh-1][j+wth-1]);
							}
						}
					}
					//printf("%d %d %d %d : %d\n",i,j,i+hgh-1,j+wth-1,dp[i][j][i+hgh-1][j+wth-1]);
				}
			}
		}
	}
	printf("%d",dp[1][1][n][n]);
}