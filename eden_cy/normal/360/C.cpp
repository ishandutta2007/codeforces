#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define N 2005

typedef long long ll;
const int Mod=(int)1e9+7;

ll dp[N][N];
ll sum[N];
char str[N];
int main() {
	int n,K;
	scanf("%d%d",&n,&K);
	scanf("%s",str+1);
	dp[0][0]=sum[0]=1;
	FOR(i,1,n) {
		DOR(j,i-1,0) {
			if((i-j)*(n-i+1)>K) break;
			FOR(k,(i-j)*(n-i+1),K) {
				dp[i][k]=(dp[i][k]+dp[j][k-(i-j)*(n-i+1)]*('z'-str[i]))%Mod;
			}
		}
		FOR(j,0,K) dp[i][j]=(dp[i][j]+sum[j]*(str[i]-'a'))%Mod;
		FOR(j,0,K) sum[j]=(sum[j]+dp[i][j])%Mod;
	}
	printf("%lld\n",sum[K]);
	return 0;
}