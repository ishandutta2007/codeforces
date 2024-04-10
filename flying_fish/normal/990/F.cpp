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

struct node{
    int to,id,seg;
    node(int _to,int _id,int _seg):to(_to),id(_id),seg(_seg){};
};
vector<node> edge[maxn];
int A[maxn];
int ans[maxn],vis[maxn];
void dfs(int x){
    vis[x]=1;
    for (auto now:edge[x]) if (!vis[now.to]){
        dfs(now.to);
        ans[now.id]+=A[now.to]*now.seg;
        A[x]+=A[now.to];A[now.to]=0;
    }
}
int main() {
    int i,j,n,m;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&A[i]);
    scanf("%d",&m);
    FOR(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(node(v,i,1));
        edge[v].push_back(node(u,i,-1));
    }FOR(i,1,n) if (!vis[i]){
        dfs(i);
        if (A[i]) return 0*puts("Impossible");
    }
//    FOR(i,1,n) printf("%d\n",A[i]);
    puts("Possible");
    FOR(i,1,m) printf("%d\n",ans[i]);
    return 0;
}
/*
*/