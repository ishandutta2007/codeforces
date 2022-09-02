#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int dp[40005][200][2];
int n;
int limit[2];
int high[205]={};
int rui[205]={};
int main(){
	FILE *in,*out;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&n);
	fscanf(in,"%d %d",&limit[0],&limit[1]);
	for(int i=1;i<=n;i++){
		fscanf(in,"%d",&high[i]);
		rui[i]=rui[i-1]+high[i];
	}
	for(int i=0;i<40005;i++){
		for(int j=0;j<200;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k]=INF;
			}
		}
	}
	dp[0][0][1]=0;
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=rui[i];j++){
			if(rui[i]-j<=limit[1]){
				dp[j][i][1]=min(dp[j][i-1][1],dp[j][i-1][0]+min(high[i-1],high[i]));
			}else{
				dp[j][i][0]=INF;
			}
		}
		for(int j=high[i];j<=rui[i];j++){
			if(rui[i]-j<=limit[1]){
				dp[j][i][0]=min(dp[j-high[i]][i-1][0],dp[j-high[i]][i-1][1]+min(high[i-1],high[i]));
			}else{
				dp[j][i][0]=INF;
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=limit[0];i++){
		for(int j=0;j<2;j++){
			ans=min(ans,dp[i][n][j]);
		}
	}
	if(ans!=INF){
		fprintf(out,"%d\n",ans);
	}else{
		fprintf(out,"-1\n");
	}
return 0;
}