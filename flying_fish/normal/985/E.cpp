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

int n,k;LL d;
set<int> S;
LL A[maxn];
int main() {
    int i,j;
    scanf("%d%d%I64d",&n,&k,&d);
    FOR(i,1,n) scanf("%I64d",&A[i]);
    sort(A+1,A+1+n);
    FOR(i,0,n-1) S.insert(i);
    S.insert(INF);
    j=n;
//    FOR(i,1,n) printf("%I64d ",A[i]);puts("");
    rFOR(i,1,n) {
        while (j&&A[i]-A[j]<=d) j--;
//        printf("%d : %d-%d\n",i,j-1,i-k);
        if (!S.count(i)){
            set<int>::iterator it;
            it=S.lower_bound(j);
            while (*it<=i-k){
//                printf("cmp %d %d\n",*it,i-k);
                S.erase(*it);
                it=S.lower_bound(j);
//                printf("->%d\n",*it);
            }
        }
    }if (S.count(0)) puts("NO");
    else puts("YES");
    return 0;
}
/*
100000000000000000 2
*/