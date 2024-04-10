

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
#include <unordered_map>
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

int n,m;
unordered_map<LL,LL> MP;
LL a[maxn],sum[maxn];
LL ans1,ans2;
int main(){
	int i;
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%I64d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		ans2+=i*a[i]-sum[i];
		ans2-=MP[a[i]-1];
		ans2+=MP[a[i]+1];
		if (ans2<0) ans2+=10000000,ans1--;
		ans1+=ans2/10000000;
		ans2-=ans2/10000000*10000000;
		MP[a[i]]++;
	}
	if (ans2<0) ans2+=10000000,ans1--;
//	sort(a+1,a+1+n);
	if (ans1<0){
		ans1=-ans1;
		ans2=-ans2;
		if (ans2<0) ans2+=10000000,ans1--;
		printf("-");
		if (ans1) printf("%I64d%07I64d",ans1,ans2);
		else printf("%I64d\n",ans2);
	}else{
		if (ans1) printf("%I64d%07I64d",ans1,ans2);
		else printf("%I64d\n",ans2);
	}
}
/*
*/