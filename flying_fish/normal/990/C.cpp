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

int n,k;
map<int,int> MP;
LL ans;
string A[maxn];
int main() {
    int i,j;
    scanf("%d",&n);
    FOR(i,1,n) cin>>A[i];
    FOR(i,1,n){
        int now=0,okay=1;
        for (auto c:A[i]){
            if (c==')') now--;
            else now++;
            if (now<0) okay=0;
        }if (!okay) continue;
        else MP[now]++;
    }FOR(i,1,n){
        int now=0,MIN=0;
        for (auto c:A[i]){
            if (c==')') now--;
            else now++;
            MIN=min(MIN,now);
        }if (MIN<now||now>0) continue;
        ans+=MP[-now];
    }

    printf("%I64d\n",ans);
    return 0;
}
/*
4
()
()
()
()
*/