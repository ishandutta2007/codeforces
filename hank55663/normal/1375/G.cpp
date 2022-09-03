#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int cnt[2];
void dfs(int x,int f,int dis=0){
	cnt[dis&1]++;
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x,dis+1);
		}
	}
	/*dp[x][1][0]=1;
	dp[x][0][0]=0;
	for(auto it:v[x]){
		if(it!=f){
			dfs(it,x);
			dp[x][0][0]+=dp[it][1][0];
			//dp[x][0][1]+=min(dp[it][1][1],dp[it][1][2]);
			dp[x][1][0]+=min(dp[it][0][0],dp[it][1][0]);
			//dp[x][1][1]+=min(dp[it][0][1],dp[it][1][1]);
		}
	}
	int sum=0;
	for(auto it:v[x]){
		if(it!=f){
			sum+=min(dp[it][0][0],dp[it][0][1]);
			sum=min(sum,1000000000);
		}
	}
	dp[x][1][2]=sum+1;
	dp[x][1][1]=1;
	dp[x][0][1]=0;
	for(auto it:v[x]){
		if(it!=f){
			dp[x][1][1]+=min(dp[it][0][1],dp[it][1][1]);
			dp[x][1][1]=min(dp[x][1][1],1000000000);
			dp[x][0][1]+=min(dp[it][1][1],dp[it][1][2]);
			dp[x][0][1]=min(dp[x][0][1],1000000000);
		}
	}
	if(dp[x][1][1]==1)dp[x][1][1]=1e9;
	if(dp[x][0][1]==0)dp[x][0][1]=1e9;
	//printf("%d %d %d\n",x,dp[x][0][0],dp[x][0][1]);
	//printf("%d %d %d %d\n",x,dp[x][1][0],dp[x][1][1],dp[x][1][2]);*/
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	printf("%d\n",min(cnt[0],cnt[1])-1);
	//printf("%d\n",min(min(dp[1][0][1],dp[1][1][1]),dp[1][1][2])-1);
	return 0;
}