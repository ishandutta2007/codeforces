#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 10005
#define N 105

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,ll b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll C[N][N];
ll dp[N][M];
ll Tmp[N][N];
int main() {
	FOR(i,0,100) {
		C[i][0]=1;
		FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	int n,K;ll m;
	scanf("%d%lld%d",&n,&m,&K);
	FOR(i,1,n) FOR(j,0,n) Tmp[i][j]=Fast(C[n][j],(m-i+n)/n);
	dp[0][0]=1;
	FOR(i,1,n) {
		FOR(j,0,min(K,(i-1)*n)) if(dp[i-1][j]) {
			FOR(k,0,min(K-j,n)) {
				dp[i][j+k]=(dp[i][j+k]+dp[i-1][j]*Tmp[i][k])%Mod;
			}
		}
	}
	printf("%lld\n",(dp[n][K]+Mod)%Mod);
	return 0;
}