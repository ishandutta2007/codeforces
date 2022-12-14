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

int a,b,c,d;
int n,p,i,j;
char A[107][107];
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a--;b--;
    int x,y;
    x=1;y=1;
    FOR(i,1,30) FOR(j,1,50) A[i][j]='A';
    while (b--){
        A[x][y]='B';
        y+=2;if (y>50) y=1,x+=2;
    }while (c--){
        A[x][y]='C';
        y+=2;if (y>50) y=1,x+=2;
    }while (d--){
        A[x][y]='D';
        y+=2;if (y>50) y=1,x+=2;
    }FOR(i,31,50) FOR(j,1,50) A[i][j]='B';
    x=32;y=1;
    while (a--){
        A[x][y]='A';
        y+=2;if (y>50) y=1,x+=2;
    }
    printf("%d %d\n",50,50);
    FOR(i,1,50) puts(A[i]+1);
}
/*
*/