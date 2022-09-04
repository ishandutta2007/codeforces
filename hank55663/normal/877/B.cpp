#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	char c[5005];
	int dp[5005][3];
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	scanf("%s",c+1);
	for(int i=1;c[i]!=0;i++){
		dp[i][0]=dp[i-1][0];
		if(c[i]=='a')
		dp[i][0]++;
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
		if(c[i]=='b')
		dp[i][1]++;
		dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
		if(c[i]=='a')
		dp[i][2]++;
	//	printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
	}
	int len=strlen(c+1);
	printf("%d\n",max(dp[len][0],max(dp[len][1],dp[len][2])));
}