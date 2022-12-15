#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

int mod = 1000*1000LL*1000+7;
int dp[2005][2005];
VI dziel[2005];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	FOR(i,0,2005) dziel[i].clear();
	FOR(i,1,n+1){
		for(int j = 1;j*j<=i;j++){
			if(i%j==0){
				dziel[i].pb(j);
				if(j!=i/j) dziel[i].pb(i/j);
			}
		}
	}

	

	FOR(i,1,n+1) dp[1][i] = 1;

	FOR(i,2,k+1){
		FOR(j,1,n+1){
			dp[i][j]=0;
			FOR(u,0,dziel[j].size()){
				dp[i][j] = (dp[i][j]+dp[i-1][j/dziel[j][u]]);
				if(dp[i][j]>=mod) dp[i][j]-=mod;
			}
		}
	}

	int res = 0;
	FOR(i,1,n+1){
		res+=dp[k][i];
		if(res>=mod) res-=mod;
	}
	printf("%d\n",res);
	
	return 0;
}