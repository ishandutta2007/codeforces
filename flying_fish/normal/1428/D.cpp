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

int A[maxn];
queue<pii> q1,q2,q3;
vector<pii> ans;
int main() {
    int tot=0,i,n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&A[i]);
    rFOR(i,1,n) {
        if (A[i]==1) {
            ans.push_back(make_pair(++tot,i));
            q1.push(make_pair(tot,i));
        } else if (A[i]==2) {
            if (!q1.size()) return 0*puts("-1");
            pii v; v=q1.front(); q1.pop();
            ans.push_back(make_pair(v.first,i));
            q2.push(make_pair(v.first,i));
        } else if (A[i]==3) {
            if (!q1.size()&&!q2.size()&&!q3.size()) return 0*puts("-1");
            pii v;
            if (q3.size()) {v=q3.front(); q3.pop();}
            else if (q2.size()) {v=q2.front(); q2.pop();}
            else if (q1.size()) {v=q1.front(); q1.pop();}
            ans.push_back(make_pair(++tot,v.second));
            ans.push_back(make_pair(tot,i));
            q3.push(make_pair(tot,i));
        }
    }
    printf("%d\n",(int)ans.size());
    for (pii v:ans) printf("%d %d\n",n-v.first+1,v.second);
}
/*
100
4
-->>
*/