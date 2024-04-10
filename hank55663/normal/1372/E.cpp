#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int l[105][105],r[105][105];
	int now=1;
	//MEM(bln);
	for(int i = 1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 0;j<k;j++){
			int x,y;
			scanf("%d %d",&x,&y);
			for(int a=x;a<=y;a++)l[i][a]=x,r[i][a]=y;
		}
	}
	int dp[105][105];
	MEM(dp);
	for(int i = 0;i<m;i++){
		for(int j = 1;j+i<=m;j++){
			for(int k = j;k<=j+i;k++){
				int cnt=0;
				for(int x=1;x<=n;x++){
					if(l[x][k]>=j&&r[x][k]<=j+i)cnt++;
				}
				dp[j][j+i]=max(dp[j][j+i],cnt*cnt+dp[j][k-1]+dp[k+1][j+i]);
		//		printf("%d\n",cnt);
			}
		//	printf("%d %d %d\n",j,j+i,dp[j][j+i]);
		}
	}
	printf("%d\n",dp[1][m]);
	return 0;
}