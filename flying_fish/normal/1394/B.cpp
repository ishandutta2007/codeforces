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
const LL M=998244353;
const LL maxn=2e5+107;
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

//mdzz...
//1...
int ans=0,n=0;
int g[17][17][17][17],f[17][17];
int now[17],C[17][17];
void dfs(int k,const int &end,int cnt) {// k:position
    int i;
    // FOR(i,1,k-1) printf("%d ",now[i]); puts(" <- dfs");
    if (k>end) {ans++; return;}
    FOR(i,1,k) if (!f[k][i]) {
        now[k]=i; int j; bool mark=1;
        FOR(j,1,k-1) if (g[j][k][now[j]][now[k]]) mark=0;
        if (!mark) continue;
        dfs(k+1,end,cnt+C[k][i]);
    }
}
int cnt[maxn][10][10];
vector<pair<int,int> > edge[maxn];//dis=k:okay
int main() {
    int m,k;
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m) {
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        edge[u].push_back(make_pair(w,v));
    }
    FOR(i,1,n) {
        sort(edge[i].begin(), edge[i].end());
        int t=edge[i].size();
        REP(j,t) {
            cnt[edge[i][j].second][t][j+1]++;
            C[t][j+1]++;//kth
        }
    }
    FOR(i,1,n) {
        int x,x1,y,y1;
        FOR(x,1,9) FOR(x1,1,x) if (cnt[i][x][x1]) {
            if (cnt[i][x][x1]!=1) f[x][x1]=1;
            FOR(y,x+1,9) FOR(y1,1,y) if (cnt[i][y][y1]) {
                // printf("%d: %d %d %d %d\n",i,x,y,x1,y1);
                g[x][y][x1][y1]=1;
                // g[y][x][y1][x1]=1;
            }
        }
    }
    dfs(1,k,0);
    printf("%d\n",ans);
}
/*
6 1
1 0 0 1 1 1

6 2
1 0 0 1 1 1
*/