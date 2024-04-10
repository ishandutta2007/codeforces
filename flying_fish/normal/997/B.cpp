#include <sstream>
#include <fstream>
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
#include <cassert>
#include <bitset>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)

#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef long long LL;
typedef long long ll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double pi=acos(-1.0);
const double eps=0.00000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a, T b) {
    T ret=1;
    for (; b; b>>=1ll,a=(LL)a*a%M)
        if (b&1) ret=(LL)ret*a%M;
    return ret;
}

const int MAX=3000;
char A[maxn];
bitset<300100> pre,now;
ll solve(int CNT){
    int i,j;
    pre.reset();now.reset();
    now.set(0);
    FOR(i,1,CNT){
        pre=now;now.reset();
        now=(pre<<1)|(pre<<5)|(pre<<10)|(pre<<50);
    }
}
void solve1(ll n){
    int i;
    solve(MAX);
    solve(n);ll ans=0;
    FOR(i,n,n*50) if (now[i]) ans++;
//    FOR(i,n,n*50) if (now[i]) printf("%d ",i);
    printf("%I64d\n",ans);
}
void solve2(ll n){
    int i;
    solve(MAX);
    ll L=n+30000,R=n*50-30000;
    R=max(R,L-1);
    ll ans=(R-L+1);
    FOR(i,1,MAX*50) if (now[i]){
        ll now=n-MAX+i;
        if (now<L) ans++;
        now=(n-MAX)*50+i;
        if (now>R) ans++;
    }printf("%I64d\n",ans);
}
int TaskA(){
    int m,i,j;
    ll n;
//    solve1(1000);solve2(1000);
//    FOR(i,6000,6200) {solve1((ll)i);solve2((ll)i); puts("NO!");}
    scanf("%I64d",&n);
    if (n<=MAX*2) solve1(n);
    else solve2(n);
    return 0;
}
void initialize(){}
int main() {
	int startTime=clock();
	//initialize
	initialize();
	debug("/--- initializeTime: %ld milliseconds ---/\n",clock()-startTime);
	int T=1;
//	scanf("%d",&T);
	startTime=clock();
	while (T--) TaskA();
	debug("/--- computeTime: %ld milliseconds ---/\n",clock()-startTime);
}
/*
500
500
1000000000
*/