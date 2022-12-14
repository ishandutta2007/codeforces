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

int A[maxn];
vector<int> edge[maxn];
int sz[maxn];
bool mark[maxn];
int minweight,root;
void dfs1(int x,int fa,int n) {
	int weight=0;
	sz[x]=1;
	for (int v:edge[x]) {
		if (v==fa||mark[v]) continue;
		dfs1(v,x,n); sz[x]+=sz[v];
		weight=max(weight,sz[v]);
	} weight=max(weight,n-sz[x]);
	if (weight<minweight) root=x,minweight=weight;
}
unordered_map<int,int> now;
unordered_map<int,int> MP;
unordered_map<int,LL> ans;
void dfs2(int x,int fa,int gg){
    gg=gcd(gg,A[x]);
    now[gg]++;
    for (int v:edge[x]){
        if (v==fa||mark[v]) continue;
        dfs2(v,x,gg);
    }
}
unordered_map<LL,int> MMP;
inline int getgcd(int x,int y){
    if (MMP[(LL)x*1000000+y]) return MMP[(LL)x*1000000+y];
    else return MMP[(LL)x*1000000+y]=gcd(x,y);
}
void calc(int x){
    MP.clear();
    MP[A[x]]++;
    for (int u:edge[x]){
        if (mark[u]) continue;
        now.clear(); dfs2(u,x,A[x]);
        for(auto P:now) for (auto Q:MP)
            ans[getgcd(P.first,Q.first)]+=(LL)Q.second*P.second;
        for(auto P:now) MP[P.first]+=P.second;
    }
    MP.clear();
}
void dfs3(int x) {
//	debug("dfs3:%d\n",x);
	calc(x); mark[x]=1; ans[A[x]]++;
	for (int v:edge[x]) {
		if (mark[v]) continue;
		minweight=sz[v];
		dfs1(v,0,sz[v]);
		dfs3(root);
	}
}
vector<pair<int,LL> > Ans;
int main() {
    int i,j,n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&A[i]);
    FOR(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }minweight=n;
    dfs1(1,0,n);dfs3(root);
    for (auto now:ans) Ans.push_back(now);
    sort(Ans.begin(),Ans.end());
    for (auto now:Ans) printf("%d %I64d\n",now.first,now.second);
}
/*
*/