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

set<ll> S;
vector<ll> V;
vector<pair<char,pll> > ans;
ll ADD(ll x,ll y) {
    // printf("%d + %d = %d\n",x,y,x+y);
    if (!S.count(x+y)) {
        V.push_back(x+y);
        ans.push_back(make_pair('+',make_pair(x,y)));
        S.insert(x+y);
    } 
    return x+y;
}
ll XOR(ll x,ll y) {
    // printf("%d ^ %d = %d\n",x,y,x^y);
    if (!S.count(x^y)) {
        V.push_back(x^y);
        ans.push_back(make_pair('^',make_pair(x,y)));
        S.insert(x^y);
    }
    return x^y;
}
namespace LB {
    typedef long long BaseType;
    const int MaxBit=63;
    struct L_B {
        BaseType b[MaxBit]; bool have_0;
        L_B() {clear();}
        void clear() {memset(b,0,sizeof(b)); have_0=0;}
        BaseType XORMIN(BaseType x) {
            int i;
            rREP(i,MaxBit) if ((b[i]^x)<x) x^=b[i];
            return x;
        }
        void insert(BaseType x) {
            int i;
            rREP(i,MaxBit) if ((x>>i)&1) {
                if (!b[i]) b[i]=x; x=XOR(x,b[i]);
            }
        }
    } A;
}
using namespace LB;
void back() {
    int i,n;
    scanf("%d",&n);
    FOR(i,1,n) {
        int now;
        char s[2]; int a,b;
        scanf("%d%s%d",&a,s,&b);
        if (s[0]=='^') now=a^b;
        else now=a+b;
        pr2(now,32); printf("  %d\n",now);
    }
}
void solve(ll x) {
    V.push_back(x);
    XOR(x,x); ll y=x; int i;
    REP(i,30) y=ADD(y,y);
    srand(time(0));
    while (A.XORMIN(1)) {
        ll x=V[rand()%V.size()],y=V[rand()%V.size()];
        A.insert(ADD(x,y));
        // printf("chk %lld\n",x+y);
        V.push_back(x+y);
        // system("pause");
    }
}
int main() {
    int x;
    scanf("%d",&x);
    solve(x);
    printf("%d\n",(int)ans.size());
    for (auto now:ans) printf("%lld %c %lld\n",now.second.first,now.first,now.second.second);
    // back();
    // pr2(123,32); puts("");
    // pr2(246,32); puts("");
    // pr2(141,32); puts("");
    // pr2(264,32); puts("");
    // pr2(369,32); puts("");
    // pr2(367,32); puts("");
    // pr2(30,32); puts("");
}
/*
*/