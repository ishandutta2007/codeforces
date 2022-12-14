#include <sstream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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
#define deputs() fprintf(stderr, "\n")
#else
#define debug(...)
#define deputs()
#endif // DEBUG
typedef unsigned long long ULL;
typedef long long LL;
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

LL ans;
int R[maxn],A[maxn];
int main() {
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,0,n) R[i]=i;
    FOR(i,1,m) scanf("%d",&j),R[j]=j+1;
    FOR(i,1,k) scanf("%d",&A[i]);
    rFOR(i,1,n) R[i]=R[R[i]];
    ans=INFF;
    FOR(i,1,k){
        j=n;LL cnt=0;
        while (j&&R[max(0,j-i)]!=j) cnt++,j=R[max(0,j-i)];
        if (!j) ans=min(ans,cnt*A[i]);
    }if (ans==INFF) puts("-1");
    else printf("%I64d\n",ans);
}
/*
*/