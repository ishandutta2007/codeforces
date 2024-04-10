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

unordered_map<LL,LL> MP;
LL solve(LL x){
	if (MP.count(x)) return MP[x];
	LL ret=powMM(2ll,x-1)-1;
	if (ret<0) ret+=M;
	for(LL i=2;i*i<=x;i++) if (x%i==0){
		ret-=solve(i);
		if (ret<0) ret+=M;
		if (x/i!=i) ret-=solve(x/i);
		if (ret<0) ret+=M;
	}return MP[x]=ret%M;
}
int main(){
	LL x,y;
	scanf("%I64d%I64d",&x,&y);
	if (y%x!=0) return 0*puts("0");
	y/=x;MP[1]=1;
	printf("%I64d",solve(y));
}
/*
*/