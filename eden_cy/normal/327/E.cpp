#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 24

typedef long long ll;
const int Mod=(int)1e9+7;

int val[M];
int Num[M];
int dp[1<<M];
ll sum[1<<M];
bool mark[1<<M];
int sz[1<<M];
int main() {
	int n,K;
	scanf("%d",&n);
	FOR(i,0,n-1) scanf("%d",&val[i]);
	scanf("%d",&K);
	FOR(i,1,K) scanf("%d",&Num[i]);
	FOR(i,0,n-1) sz[1<<i]=i;
	FOR(i,1,(1<<n)-1) {
		sum[i]=sum[i^(i&-i)]+val[sz[i&-i]];
		mark[i]=true;
		FOR(j,1,K) if(sum[i]==Num[j]) mark[i]=false;
	}
	dp[0]=1;
	int i,x;
	for(i=1;i<(1<<n);i++) if(mark[i]) {
		for(x=i;x;x^=x&-x) dp[i]=(dp[i]+dp[i^(x&-x)])%Mod;
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}