#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <unordered_map>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e5+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,m;
char s[maxn];
pair<int,int> dp[maxn];
int len[maxn][2],cnt[maxn];
int main(){
	int i;
	scanf("%d%s%d",&n,s+1,&m);
	FOR(i,1,n){
		cnt[i]=cnt[i-1];
		if (s[i]=='?') cnt[i]++;
	}
	FOR(i,1,n){
		if (s[i]=='a'||s[i]=='?') len[i][1]=len[i-1][0]+1;
		else len[i][1]=0;
		if (s[i]=='b'||s[i]=='?') len[i][0]=len[i-1][1]+1;
		else len[i][0]=0;
		if (i>=m){
			dp[i]=dp[i-1];
			if (len[i][m&1]>=m)
				dp[i]=max(dp[i],make_pair(dp[i-m].first+1,dp[i-m].second-(cnt[i]-cnt[i-m])));
		}
	}
//	printf("%d %d\n",dp[n].first,dp[n].second);
	printf("%d\n",-dp[n].second);
}
/*
*/