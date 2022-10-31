#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int b[3100];
long long dp[3100][3100];
int z[3100];
long long ABS(long long a){
	return max(a,-a);
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++)b[i]-=i;
	for(int i=0;i<a;i++)z[i]=b[i];
		std::sort(z,z+a);
	for(int i=0;i<3100;i++)for(int j=0;j<3100;j++)dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=1;i<=a;i++){
		long long tmp=inf;
		for(int j=0;j<a;j++){
			tmp=min(tmp,dp[i-1][j]);
			dp[i][j]=tmp+ABS(b[i-1]-z[j]);
		}
	}
	long long ret=inf;
	for(int i=0;i<a;i++)ret=min(ret,dp[a][i]);
	printf("%I64d\n",ret);
}