#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;

int main()
{
	int n,q,c;
	scanf("%d %d %d",&n,&q,&c);
	int dp[105][105][15];
	c++;
	MEM(dp);
	for(int i=0;i<n;i++){
		int x,y,s;
		scanf("%d %d %d",&x,&y,&s);
		for(int i=0;i<c;i++)
		dp[x][y][i]+=(s+i)%c;
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=0;k<c;k++){
				dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k]+dp[i][j][k];
			}
		}
	}
	while(q--){
		int t,x1,y1,x2,y2;
		scanf("%d %d %d %d %d",&t,&x1,&y1,&x2,&y2);
		printf("%d\n",dp[x2][y2][t%c]-dp[x1-1][y2][t%c]-dp[x2][y1-1][t%c]+dp[x1-1][y1-1][t%c]);
	}
}