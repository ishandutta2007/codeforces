#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
vector<int> prime;
int last[200005];
pii dp[200005][22];
bool solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005];
	map<int,int> m;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		for(auto it:prime){
			while(a[i]%(it*it)==0){
				a[i]/=it*it;
			}
		}
		m[a[i]];
	}
	int idx=0;
	for(auto &it:m){
		it.y=++idx;
	}
	fill(last,last+idx+1,-1);
	for(int j = 0;j<=k;j++)dp[0][j]=mp(1,0);
	for(int i = 1;i<=n;i++){
		a[i]=m[a[i]];
		if(last[a[i]]!=-1){
			for(int j = 0;j<=k;j++){
				if(dp[i-1][j].y>last[a[i]])
				dp[i][j]=dp[i-1][j];
				else
				dp[i][j]=mp(dp[i-1][j].x+1,i);
			}
			for(int j  =1;j<=k;j++){
				if(dp[i][j].x>dp[i-1][j-1].x||(dp[i][j].x==dp[i-1][j-1].x&&dp[i][j].y<dp[i-1][j-1].y))
				dp[i][j]=dp[i-1][j-1];
			}
		}
		else{
			for(int j=0;j<=k;j++){
				dp[i][j]=dp[i-1][j];
			}
		}
	//	for(int j = 0;j<=k;j++){
	//		printf("(%d,%d)",dp[i][j].x,dp[i][j].y);
	//	}
		//printf("\n");
		last[a[i]]=i;
	}
	printf("%d\n",dp[n][k].x);
}
int main(){
	int isprime[4005];
	MEM(isprime);
	for(int i=2;i<=4000;i++){
		if(!isprime[i]){
			prime.pb(i);
			for(int j = i;j<=4000;j+=i)
				isprime[j]=1;
		}
	}
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}