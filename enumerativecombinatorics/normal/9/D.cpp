#include<stdio.h>
#include<algorithm>
using namespace std;
long long dp[100][100];
long long calc(int a,int b){
	if(~dp[a][b])return dp[a][b];
	if(a<b)return dp[a][b]=0;
	if(a==0||a==1)return dp[a][b]=1;
	long long ret=0LL;
	for(int i=0;i<a;i++){
		ret+=-calc(i,b-1)*calc(a-i-1,b-1)+calc(i,b-1)*calc(a-i-1,0)+calc(i,0)*calc(a-i-1,b-1);
	}
	return dp[a][b]=ret;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			dp[i][j]=-1;
	printf("%I64d\n",calc(a,b));
}