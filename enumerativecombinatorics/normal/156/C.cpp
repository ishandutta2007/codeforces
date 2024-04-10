#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[101][2600];
char str[128];
int main(){
	int a;
	int mod=1000000007;
	dp[0][0]=1;
	for(int i=0;i<100;i++){
		for(int j=0;j<2600;j++){
			if(!dp[i][j])continue;
			for(int k=0;k<26;k++)dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j])%mod;
		}
	}
	scanf("%d",&a);
	while(a--){
		scanf("%s",str);
		int n=strlen(str);
		int v=0;
		for(int i=0;i<n;i++)v+=str[i]-'a';
		printf("%d\n",(dp[n][v]+1000000006)%mod);
	}
}