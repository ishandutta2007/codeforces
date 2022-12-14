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
#define dbg(x) cerr <<#x<<" = "<<x<<" ;  "
#define dbgln(x) cerr <<#x<<" = "<<x<<endl
typedef unsigned long long ULL;
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=2000+7;
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

int n,m;
bitset<2007> A[maxn],B[maxn];
char s[maxn];
int main() {
    int i,j;
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%s",s);
        REP(j,m) if (s[j]-'0') A[i].set(j);
        B[i]=A[i];
    }FOR(i,1,n) A[i]|=A[i-1];
    rFOR(i,1,n) B[i]|=B[i+1];
    FOR(i,1,n) if ((A[i-1]|B[i+1]).count()==m){
//        printf("%d",i);
        return 0*puts("YES");
    }
    puts("NO");
    return 0;
}
/*
*/