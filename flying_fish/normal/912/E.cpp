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
const LL maxn=1e6+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,i,j;LL k;
vector<LL> V,P;
void dfs(LL x,int *p,int i,int n){
	V.push_back(x);
	for (;i<n;i++)
		if (x<(1e18+7)/p[i])
			dfs(x*p[i],p,i,n);
}
LL check(LL x){
	LL cnt=0;auto last=P.begin();
	for (LL now:V){
		while (last!=P.end()&&(*last)<=x/now) last++;
		cnt+=last-P.begin();
//		cnt+=upper_bound(P.begin(),P.end(),x/now)-P.begin();
//		if (k<=cnt) return cnt;
	}return cnt;
}int p[20];
LL l,r,mid;
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&p[i]);
	scanf("%I64d",&k);
	dfs(1,p,0,n/2);
	sort(V.begin(),V.end());
	P.swap(V);
	dfs(1,p+n/2,0,n-n/2);
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
//	puts("OK");
//	for (LL now:V) printf("%I64d ",now);puts("");
//	for (LL now:P) printf("%I64d ",now);puts("");
//	FOR(i,1,10000) if (check(i)!=check(i-1)) printf("%I64d %I64d  _%d\n",i,check(i)-check(i-1),check(i));
	l=0;r=1e18+7;
	while (l+1<r){
		mid=(l+r)/2;
		if (check(mid)<k) l=mid;
		else r=mid;
	}printf("%I64d\n",r);
}
/*
*/