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
typedef unsigned int ui;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+107;
const double pi=acos(-1.0);
const double eps=0.0000000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline void pr2(T x,int k=64) {ll i; REP(i,k) debug("%d",(x>>i)&1); putchar(' ');}
template<typename T>inline void add_(T &A,int B,ll MOD=M) {A+=B; (A>=MOD) &&(A-=MOD);}
template<typename T>inline void mul_(T &A,ll B,ll MOD=M) {A=(A*B)%MOD;}
template<typename T>inline void mod_(T &A,ll MOD=M) {A%=MOD; A+=MOD; A%=MOD;}
template<typename T>inline void max_(T &A,T B) {(A<B) &&(A=B);}
template<typename T>inline void min_(T &A,T B) {(A>B) &&(A=B);}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
inline ll powMM(ll a, ll b, ll mod=M) {
    ll ret=1;
    for (; b; b>>=1ll,a=a*a%mod)
        if (b&1) ret=ret*a%mod;
    return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

ll getvalue(int x,int y) {//x; ytimes
    if (x<y) return INF;//cannot cut it
    ll div=x/y,sec=x-div*y,fir=y-sec;
    ll ret=fir*div*div+sec*(div+1)*(div+1);
    // printf("%d %d: %lld %lld div=%lld, %lld\n",x,y,fir,sec,div,ret);
    return ret;
}
priority_queue<pair<ll,pii> > Q;//maximum-div
int A[maxn];
int main() {
    int i,n,k;
    ll ans=0;
    scanf("%d%d",&n,&k);
    FOR(i,1,n) {
        scanf("%d",&A[i]);
        ans+=(ll)A[i]*A[i];
        int val=A[i],cnt=1;
        Q.push(make_pair(getvalue(val,cnt)-getvalue(val,cnt+1),make_pair(val,cnt)));
    }
    k-=n;
    while (k--) {
        auto now=Q.top(); Q.pop();
        ans-=now.first;
        // printf("chk %lld -> %d %d\n",now.first,now.second.first,now.second.second);
        int val=now.second.first,cnt=now.second.second+1;
        Q.push(make_pair(getvalue(val,cnt)-getvalue(val,cnt+1),make_pair(val,cnt)));
    }
    printf("%lld\n",ans);
}
/*
100
4
-->>
*/