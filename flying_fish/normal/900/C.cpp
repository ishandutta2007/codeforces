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
const LL maxn=1e5+7;
const double eps=0.00000001;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a,T b){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int MX1,MX2;
int a[maxn];
int cnt[maxn];
int main(){
	int n,i,j;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n){
		if (MX2<a[i]&&a[i]<=MX1) cnt[MX1]++;
		if (MX1<a[i]) cnt[a[i]]--;
		if (a[i]>MX2) MX2=a[i];
		if (MX2>MX1) swap(MX2,MX1);
	}int ans=-2,pos=0;
	FOR(i,1,n) if (cnt[i]>ans) ans=cnt[i],pos=i;
//	printf("%d",ans);
	printf("%d",pos);
}
/*
3
2 1 3

4
3 2 1 4
*/