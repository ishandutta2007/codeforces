#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define V 200005
#define M 1005

typedef long long ll;
const int Mod=(int)1e9+7;

ll dp[2][V];
ll sum[V];
int main() {
	int a,b,t,K;
	scanf("%d%d%d%d",&a,&b,&K,&t);
	int cur=0;
	dp[0][100000]=1;
	FOR(s,1,t) {
		cur^=1;
		memset(dp[cur],0,sizeof(dp[cur]));
		FOR(i,1,200000) sum[i]=(sum[i-1]+dp[!cur][i])%Mod;
//		cerr<<sum[99998]<<endl;
		FOR(i,0,200000) {
			dp[cur][i]=(sum[min(200000,i+K)]-sum[max(0,i-K-1)])%Mod;
		}
//		FOR(i,100000,200000) {
//			if(!dp[!cur][i]) break;
//			FOR(k,0,K) {
//				dp[cur][i+k]=(dp[cur][i+k]+dp[!cur][i])%Mod;
//				if(k!=0) dp[cur][i-k]=(dp[cur][i-k]+dp[!cur][i])%Mod;
//			}
//		}
//		DOR(i,99999,0) {
//			if(!dp[!cur][i]) break;
//			FOR(k,0,K) {
//				dp[cur][i+k]=(dp[cur][i+k]+dp[!cur][i])%Mod;
//				if(k!=0) dp[cur][i-k]=(dp[cur][i-k]+dp[!cur][i])%Mod;
//			}
//		}
	}
	ll res=0;
	FOR(i,0,200000) sum[i]=(sum[i-1]+dp[cur][i])%Mod;
	FOR(i,0,200000) {
		if(a+i-b>0) res=(res+dp[cur][i]*sum[min(200000,a+i-b-1)])%Mod;
//		if(dp[cur][i]) cerr<<i-100000<<" "<<res<<endl;
	}
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}