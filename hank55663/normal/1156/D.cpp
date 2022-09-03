#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL dp[300005][3];
vector<pii> v[300005];
LL ans=0;
void dfs(int x,int f){
	for(auto it:v[x]){
		if(it.x!=f){
			dfs(it.x,x);
			if(it.y==1){
				dp[x][1]+=dp[it.x][1]+1;
				dp[x][2]+=dp[it.x][0]+dp[it.x][2];
			}
			else{
				dp[x][0]+=dp[it.x][0]+1;
			}
		}
	}
}
void dfs(int x,int f,int sum0,int sum1,int sum2){
	ans+=sum0+sum1+sum2+dp[x][0]+dp[x][1]+dp[x][2];
	for(auto it:v[x]){
		if(it.x!=f){
			if(it.y==1){
				dfs(it.x,x,0,sum1+dp[x][1]-dp[it.x][1],sum2+sum0+dp[x][0]+dp[x][2]-dp[it.x][0]-dp[it.x][2]);
			}
			else{
				dfs(it.x,x,sum0+dp[x][0]-dp[it.x][0],0,0);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<n;i++){
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		v[x].pb(mp(y,d));
		v[y].pb(mp(x,d));
	}
	dfs(1,0);
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);
}