#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N
vector<int> v[200005];
int dp[200005][3];//0 use 1 cover 2 wait
vector<int> x;
void dfs(int a,int f,int d){
	int sumx=0,sumy=0,sumz=0;
	int add=1e9;
	if(d==2)
	x.pb(a);
	for(auto it:v[a]){
		if(it!=f){
			dfs(it,a,d+1);
			sumx+=min(dp[it][0],min(dp[it][1],dp[it][2]));
			sumy+=min(dp[it][0],dp[it][1]);
			add=min(add,dp[it][0]-dp[it][1]);
			sumz+=min(dp[it][0],dp[it][1]);
		}
	}
	sumy+=max(add,0);
	dp[a][1]=sumy;
	dp[a][0]=sumx+1;
	dp[a][2]=sumz;
//	printf("%d %d %d\n",a,dp[a][1],dp[a][0]);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0,0);
	int ans=0;
	for(auto it:x){
		ans+=min(dp[it][0],min(dp[it][1],dp[it][2]));
	}
	printf("%d\n",ans);
}