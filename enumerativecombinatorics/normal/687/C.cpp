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
int dp[510][510];
int c[510];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",c+i);
	vector<int>ans;
	dp[0][0]=1;
	for(int i=0;i<a;i++){
		for(int j=b;j>=0;j--){
			for(int k=b;k>=0;k--){
				if(dp[j][k]){
					if(j+c[i]<=b){
						dp[j+c[i]][k+c[i]]=1;
						dp[j+c[i]][k]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<=b;i++)if(dp[b][i])ans.push_back(i);
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++){
		if(i)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}