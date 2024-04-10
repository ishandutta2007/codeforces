#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 2005

typedef long long ll;
const int Mod=(int)1e9+7;

ll dp[M][M];
vector<int> G[M];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,i) if(i%j==0) G[i].push_back(j);
	FOR(i,1,n) dp[1][i]=1;
	FOR(i,2,m) FOR(j,1,n) FOR(k,0,G[j].size()-1) dp[i][j]=(dp[i][j]+dp[i-1][G[j][k]])%Mod;
	ll res=0;
	FOR(i,1,n) res=(res+dp[m][i])%Mod;
	printf("%lld\n",res);
	return 0;
}