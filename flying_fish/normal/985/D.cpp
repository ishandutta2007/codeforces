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
const LL maxn=1e5+7;
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

LL n,h;
LL l,r,mid;
bool check(LL t){
    if (t>h) {
//        if (2*t-h+1<=n*2/h) return 1;//no use
        LL H=(t+h-1)/2;
        if (H+1>n*2/H) return 0;
        LL _H=H+(t+h-1)%2;
//        printf("%I64d: %I64d\n",t,(_H-h+1)*(_H+h)/2+H*(H+1)/2);
        if ((_H-h+1)*(_H+h)/2+H*(H+1)/2<=n) return 1;
        return 0;
    }else return t+1<=n*2/t;
}
int main() {
    int i;
    scanf("%I64d%I64d",&n,&h);
    l=0;r=n;n--;
    while (l+1<r){
        mid=(l+r)/2;
//        printf("%I64d %I64d %I64d\n",l,r,mid);
        if (check(mid)) l=mid;
        else r=mid;
    }//printf("%I64d %I64d \n",h*(2*r-h+1)/2,r*(r+1)/2);
    printf("%I64d\n",r);
    return 0;
}
/*
100000000000000000 2
*/