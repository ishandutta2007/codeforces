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
#include <bitset>
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
template<typename T>inline T powMM(T a,T b,T M){T ret=1;for (;b;b>>=1ll,a=1ll*a*a%M) if (b&1) ret=1ll*ret*a%M;return ret;}

int n,m,k;
LL i,j;
LL ans;
int main(){
    LL a,b,p,x;
//    printf("%d ",powMM(5ll,0ll));
//    printf("%d ",powMM(5ll,M-1));
//    printf("%d ",powMM(5ll,(M-1)*2));
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&x);
    FOR(i,1,p-1){
        LL t=powMM(a,i,p);
        t=powMM(t,p-2,p);
//        printf("\ni=%d\n",i);
//        printf("t1=%d ",t);
        t=(b*t)%p;
//        printf("t2=%d ",t);
        LL T=x/(p-1)*(p-1)+i;
        while (T>x) T-=p;
        while (T+p<=x) T+=p;
//        printf("i=%lld; T=%lld\n",i,T);
        if (T<0) continue;
//        printf("i,t,T=%lld %lld %lld\n",i,t,T);
        LL MAX=T/(p-1);
        t=(t-i+p)%p;
//        printf("t - i=%d\n",t);
        t=(t*powMM(p-1,p-2,p))%p;
//        printf("MAX=%d\n",MAX);
        if (MAX<t) continue;
        ans+=(MAX-t)/p+1;
//        printf("i=%d\n",i);
//        printf("t=%lld; ans+=%lld\n",t,(MAX-t)/p+1);
    }
//    printf("%lld\n",8174ll*powMM(a,8174ll,p)%p);
//    FOR(i,0,x) if ((i*powMM(a,i,p)%p==b))printf("i=%d\n",i);
    printf("%I64d\n",ans);
}
/*
*/