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
int dp[2][1<<7][2];
int p7[24];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int A=0;
	int B=0;
	int c=a-1;int d=b-1;
	while(c){
		c/=7;
		A++;
	}
	while(d){
		d/=7;
		B++;
	}
	p7[0]=1;
	for(int i=1;i<24;i++)p7[i]=p7[i-1]*7;
	a--;b--;
	if(!A)A++;
	if(!B)B++;
	dp[0][0][0]=1;
	for(int i=0;i<A+B;i++){
		int t=i%2;
		for(int j=0;j<(1<<7);j++)dp[!t][j][0]=dp[!t][j][1]=0;
		for(int j=0;j<(1<<7);j++){
			for(int k=0;k<2;k++){
				if(!dp[t][j][k])continue;
		//		printf("%d %d %d: %d\n",i,j,k,dp[i][j][k]);
				for(int l=0;l<7;l++){
					if(j&(1<<l))continue;
					int tk=k;
					if(i<A){
						if(k==0&&a/p7[A-i-1]%7<l)continue;
						else if(a/p7[A-i-1]%7>l)tk=1;
					}else{
						if(k==0&&b/p7[A+B-i-1]%7<l)continue;
						else if(b/p7[A+B-i-1]%7>l)tk=1;
					}
					if(i==A-1)tk=0;
					dp[!t][j+(1<<l)][tk]+=dp[t][j][k];
				}
			}
		}
	}
	int ret=0;
	for(int i=0;i<(1<<7);i++)for(int j=0;j<2;j++)ret+=dp[(A+B)%2][i][j];
	printf("%d\n",ret);
}