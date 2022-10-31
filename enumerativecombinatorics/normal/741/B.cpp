#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int UF[1100];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
vector<int>v[1100];
int p[1100];
int q[1100];
int dp[1100][1100];
int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	for(int i=0;i<a;i++){
		scanf("%d",q+i);
	}
	for(int i=0;i<a;i++)UF[i]=-1;
	for(int i=0;i<b;i++){
		int s,t;scanf("%d%d",&s,&t);s--;t--;UNION(s,t);
	}
	for(int i=0;i<a;i++){
		v[FIND(i)].push_back(i);
	}
	for(int i=0;i<1100;i++)for(int j=0;j<1100;j++)dp[i][j]=-mod;
	dp[0][0]=0;
	for(int i=0;i<a;i++){
		int W=0;
		int B=0;
		for(int j=0;j<v[i].size();j++){
			W+=p[v[i][j]];
			B+=q[v[i][j]];
		}
		for(int j=0;j<=c;j++){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+W<=c)dp[i+1][j+W]=max(dp[i+1][j+W],dp[i][j]+B);
			for(int k=0;k<v[i].size();k++){
				if(j+p[v[i][k]]<=c)dp[i+1][j+p[v[i][k]]]=max(dp[i+1][j+p[v[i][k]]],dp[i][j]+q[v[i][k]]);
			}
		}
	}
	int ret=0;
	for(int i=0;i<=c;i++)ret=max(ret,dp[a][i]);
	printf("%d\n",ret);
}