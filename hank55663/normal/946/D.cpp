#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n,m,K;
	scanf("%d %d %d",&n,&m,&K);
	int cost[505][505];
	for(int i=0;i<505;i++)
		for(int j=0;j<505;j++)
			cost[i][j]=1e9;
	for(int i=1;i<=n;i++){
		char c[505];
		scanf("%s",c);
		vector<int> v;
		for(int j=0;j<m;j++){
			if(c[j]=='1')
				v.pb(j);
		}
		for(int j=0;j<v.size();j++)
			for(int k=j;k<v.size();k++){
				int cnt=v.size()-k+j-1;
				cost[i][cnt]=min(cost[i][cnt],v[k]-v[j]+1);
			}
		cost[i][v.size()]=0;
	}
	int dp[505][505];
	MEM(dp);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=K;j++){
			dp[i][j]=1e9;
			for(int k=0;k<=j;k++)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[i][j-k]);
		}
	int ans=1e9;
	for(int i=0;i<=K;i++)
	ans=min(ans,dp[n][i]);
	printf("%d\n",dp[n][K]);
}