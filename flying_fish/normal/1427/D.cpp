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

int A[maxn],B[maxn];
vector<vector<int> > ans;
int main() {
    int n,i,j,x;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&A[i]);
    while (1) {
        bool mark=0;
        FOR(x,1,n-1) {
            int px,py;
            FOR(i,1,n) if (A[i]==x) px=i;
            FOR(i,1,n) if (A[i]==x+1) py=i;
            if (py<px) {
                vector<int> now;
                if (py-1>0) now.push_back(py-1);//smaller than x
                int mid=px; FOR(i,py,px-1) if (A[i]+1!=A[i+1]) break; mid=i;//could-cut
                if (mid-py+1>0) now.push_back(mid-py+1);
                if (px-mid>0) now.push_back(px-mid);
                if (n-px>0) now.push_back(n-px);
                int pos=0;
                FOR(i,px+1,n) B[++pos]=A[i];
                FOR(i,mid+1,px) B[++pos]=A[i];
                FOR(i,py,mid) B[++pos]=A[i];
                FOR(i,1,py-1) B[++pos]=A[i];
                FOR(i,1,n) A[i]=B[i];
                ans.push_back(now);
                // FOR(i,1,n) printf("%d ",A[i]); printf(" x=%d;px,py=%d %d <- A\n",x,px,py);
                mark=1; break;
            }
        } if (!mark) break;
    }
    printf("%d\n",(int)ans.size());
    for (auto vec:ans) {
        printf("%d",(int)vec.size());
        for (int v:vec) printf(" %d",v);
        puts("");
    }
}
/*
*/