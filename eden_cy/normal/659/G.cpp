#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define INF 0x3f3f3f3f
#define M 1000005

typedef long long ll;
const int Mod=(int)1e9+7;

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}

int high[M];
ll dp[M];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) rd(high[i]);
	FOR(i,1,n) high[i]--;
	ll res=0;
	FOR(i,1,n) {
		res=(res+high[i])%Mod;
		res=(res+min(high[i-1],high[i])*dp[i-1])%Mod;
		dp[i]=min(high[i],high[i+1])%Mod;
		dp[i]=(dp[i]+min(min(high[i-1],high[i]),high[i+1])*dp[i-1])%Mod;
	}
	printf("%lld\n",res);
	return 0;
}