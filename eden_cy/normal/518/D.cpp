#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 2005

typedef double db;

db dp[M][M];
int main() {
	int n,t;
	db p;
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1;
	FOR(i,1,t) {
		FOR(j,0,n) {
			dp[i][j]+=(1-p)*dp[i-1][j];
			dp[i][min(n,j+1)]+=p*dp[i-1][j];
		}
	}
	db res=0;
	FOR(i,0,n) res+=i*dp[t][i];
	printf("%.8lf\n",res);
	return 0;
}