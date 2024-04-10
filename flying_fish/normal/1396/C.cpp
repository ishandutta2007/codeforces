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
const LL maxn=2e6+107;
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

ll A[maxn][3],t[maxn];//0:dead; 1:remain1
int main() {
    int n,i; scanf("%d",&n);
    ll r1,r2,r3,d;
    scanf("%lld%lld%lld%lld",&r1,&r2,&r3,&d);
    A[0][1]=INFF; A[0][0]=-d;
    FOR(i,1,n) scanf("%lld",&t[i]);
    ll one=min(min(r1,r2),r3);
    FOR(i,1,n) {//0:not should; 1:should 1 time; 2:multiple times
        A[i][0]=A[i][1]=A[i][2]=INFF;//to_right
        ll f0=INFF,f1=INFF;
        min_(f0,r1*t[i]+r3);//done
        min_(f1,r2+one);//should +d later; 
        min_(f1,r1*t[i]+r1+one);
        min_(f1,r3*t[i]+r1+one);
        min_(f1,f0);//once more to this pos
        f1+=d; //force to move costs; move back to this
        min_(A[i][0],A[i-1][0]+f0+d);//d:move
        min_(A[i][0],A[i-1][0]+f1+d+d);//back to this position; back * 2;
        min_(A[i][0],A[i-1][1]+f1+d);//back to this position; done previously

        min_(A[i][1],A[i-1][0]+f1+d);

        min_(A[i][2],A[i-1][0]+f1+d);
        min_(A[i][2],A[i-1][1]+f1+d);
        min_(A[i][2],A[i-1][2]+f1+d);
        if (i==n) {
            ll ans=INFF;
            min_(ans,A[i][0]);
            min_(ans,A[i-1][1]+f0+d);
            min_(ans,A[i-1][1]+f1+d+d);
            min_(ans,A[i-1][2]+f0+d);
            min_(ans,A[i-1][2]+f1+d+d);
            printf("%lld\n",ans);
        }
        // printf("%d: %lld - %lld - %lld; f0,f1=%lld %lld\n",i,A[i][0],A[i][1],A[i][2],f0,f1);
    }
    // printf("%lld\n",min(A[n][0],A[n][1]));
}
/*
2
2 1
2 1
*/