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
vector<int>g[110000];
int sz[110000];
double dp[110000];
void dfs(int a){
	sz[a]=1;
	for(int i=0;i<g[a].size();i++){
		dfs(g[a][i]);
		sz[a]+=sz[g[a][i]];
	}
}
void calc(int a,double b){
	dp[a]=b;
	for(int i=0;i<g[a].size();i++){
		calc(g[a][i],b+1+(sz[a]-1-sz[g[a][i]])*0.5);
	}
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a-1;i++){
		int p;scanf("%d",&p);p--;
		g[p].push_back(i+1);
	}
	dfs(0);
	calc(0,0);
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%.12f",dp[i]+1);
	}
	printf("\n");
}