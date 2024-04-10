#include<stdio.h>
#include<algorithm>
using namespace std;
char str[3010][3010];
int mod=1000000007;
int dp[3010][3010];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%s",str[i]);
	}
	if(str[0][1]=='#'||str[1][0]=='#'){printf("0\n");return 0;}
	dp[1][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(i<a-1&&str[i+1][j]!='#'){
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			}
			if(j<b-1&&str[i][j+1]!='#'){
				dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			}
		}
	}
	long long A=dp[a-1][b-2];
	long long B=dp[a-2][b-1];
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			dp[i][j]=0;
	dp[0][1]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(i<a-1&&str[i+1][j]!='#'){
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
			}
			if(j<b-1&&str[i][j+1]!='#'){
				dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
			}
		}
	}
	long long C=dp[a-1][b-2];
	long long D=dp[a-2][b-1];
	printf("%d\n",(int)((A*D-B*C)%mod+mod)%mod);
}