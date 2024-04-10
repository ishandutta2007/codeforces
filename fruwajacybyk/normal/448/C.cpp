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
#define max_n 100005

using namespace std;
int dp[5005][5005];

int main(){

	int n;
	int ans = 0;
	int u;
	scanf("%d",&n);
	VI v;
	int maxh = 0;
	FOR(i,0,n){
		scanf("%d",&u);
		if(u>n) ans++;
		else{
			v.pb(u);
			maxh = max(u,maxh);
		}
	}
	n = v.size();

	dp[0][0] = 0;
	FOR(i,1,maxh+1) dp[0][i] = i;

	FOR(i,1,n+1){
		FOR(j,0,maxh+1){
			if(j<v[i-1]) dp[i][j] = dp[i-1][j]+1;
			if(j>=v[i-1]) dp[i][j] = dp[i-1][v[i-1]]+(j-v[i-1]);
		}
		for(int j=maxh;j>=1;j--){
			if(dp[i][j]<dp[i][j-1]) dp[i][j-1] = dp[i][j];
		}
	}

	int res = n+5;
	FOR(i,0,maxh+1) res = min(res,dp[n][i]);
	printf("%d\n",res+ans);




	return 0;
}