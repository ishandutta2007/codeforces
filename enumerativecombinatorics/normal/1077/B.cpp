#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=924844033;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[110];
int dp[110][2][2];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	for(int i=0;i<110;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)dp[i][j][k]=mod;
	dp[0][0][0]=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(k||!j||!p[i]){
					dp[i+1][k][p[i]]=min(dp[i+1][k][p[i]],dp[i][j][k]);
				}
				if(k||!j||p[i]){
					dp[i+1][k][!p[i]]=min(dp[i+1][k][!p[i]],dp[i][j][k]+1);
				}
			}
		}
	}
	int ret=mod;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)ret=min(ret,dp[a][i][j]);printf("%d\n",ret);
}