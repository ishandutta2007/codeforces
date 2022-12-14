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

vector<int> edge[maxn];
int fa[maxn];
LL ans,sz[maxn];
void dfs(int x,int f){
    fa[x]=f;sz[x]++;
    for (int v:edge[x])if (v!=f) {
        dfs(v,x);
        sz[x]+=sz[v];
    }
}bool mark[maxn];
int n,u,v;
int main() {
    int i,j,T;
    scanf("%d%d%d",&n,&u,&v);
    FOR(i,1,n-1){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }dfs(u,0);
    LL ans=(LL)n*(n-1);
    int f;
    for (f=v;fa[f]!=u;f=fa[f]);
    ans-=(n-sz[f])*sz[v];
    printf("%I64d\n",ans);
}
/*
*/