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

int n,a,b;
int A[1007][1007];
int main() {
    int i,j;
    scanf("%d%d%d",&n,&a,&b);
    if (a!=1&&b!=1) return 0*puts("NO");
    if (n==2&&a==1&&b==1) return 0*puts("NO");
    if (n==3&&a==1&&b==1) return 0*puts("NO");
    FOR(i,2,min(n-a+1,n-b+1)) A[i-1][i]=A[i][i-1]=1;
    if (a!=1) a=0;
    puts("YES");
    FOR(i,1,n)
        FOR(j,1,n) if (i!=j) A[i][j]^=a;
    FOR(i,1,n){
        FOR(j,1,n) printf("%d",A[i][j]);
        puts("");
    }
}
/*
*/