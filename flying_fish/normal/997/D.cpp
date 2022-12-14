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
typedef long long LL;
typedef long long ll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=998244353;
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

inline void add(ll &x,ll y){x+=y; (x>=M)&&(x-=M);}
int k;
int A[maxn];
vector<int> edge[maxn];
int sz[maxn];
bool mark[maxn];
int minweight,root;
void dfs1(int x,int fa,int n) {
	int weight=0; sz[x]=1;
	for (int v:edge[x]) {
		if (v==fa||mark[v]) continue;
		dfs1(v,x,n); sz[x]+=sz[v];
		weight=max(weight,sz[v]);
	} weight=max(weight,n-sz[x]);
	if (weight<minweight) root=x,minweight=weight;
}
vector<int> have;
ll nowans[157];
ll F[4007][157],G[4007][157];//depth
void dfs2(int x,int fa) {
    int i,j;
    have.push_back(x);
	for (int v:edge[x]) {
		if (v==fa||mark[v]) continue;
		dfs2(v,x);
	}
}
void calc(int x){
    int i,j;
    have.clear(); dfs2(x,0);
    FOR(i,0,k*2) for (int x:have)
        F[x][i]=G[x][i]=0;
    G[x][0]=1;F[x][0]=1;//to x
    FOR(i,0,k*2-1) for (int y:have){
        if (G[y][i]) for (int v:edge[y]) if (!mark[v])
            add(G[v][i+1],G[y][i]);
        if ((y!=x||!i)&&F[y][i]) for (int v:edge[y]) if (!mark[v])
            if (v!=x) add(F[v][i+1],F[y][i]);
    }
    for (int y:have){
        FOR(i,0,k*2) if (F[y][i]) FOR(j,0,k*2)
            add(nowans[i+j],F[y][i]*G[y][j]%M);
    }
//    FOR(i,0,k*2) printf("%I64d ",nowans[i]);deputs("");
}
void dfs3(int x) {
//	debug("dfs3:%d\n",x);
	calc(x); mark[x]=1;
	for (int v:edge[x]) {
		if (mark[v]) continue;
		minweight=sz[v];
		dfs1(v,0,sz[v]);
		dfs3(root);
	}
}
ll ans_1[107],ans_2[107];
LL inv[1000002];//inverse
LL fac[1000002];//Factorial
LL C(int n,int m){
    return fac[n]*inv[m]%M*inv[n-m]%M;
}
void solve_cnt(int n,ll ans[]){
    int i,j,x,y;
    FOR(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }FOR(i,0,k) nowans[i]=0;
    minweight=n; dfs1(1,0,n); dfs3(root);
    FOR(i,0,k) ans[i]=nowans[i*2],nowans[i*2]=0;
    FOR(i,1,n) edge[i].clear(),mark[i]=0;
}
int TaskA(){
    int m,i,j;
    int n1,n2;
    scanf("%d%d%d",&n1,&n2,&k);
    if (k&1) return 0*puts("0"); k/=2;
    solve_cnt(n1,ans_1);
    solve_cnt(n2,ans_2);

//    FOR(i,0,k) printf("%I64d ",ans_1[i]);puts("");
//    FOR(i,0,k) printf("%I64d ",ans_2[i]);puts("");
    ll ans=0;
    FOR(i,0,k) ans+=C(k*2,i*2)*ans_1[i]%M*ans_2[k-i]%M;
    ans%=M;
    printf("%I64d\n",ans);
    return 0;
}
void initialize(){
    int i;
    fac[0]=1;
    FOR(i,1,1000000) fac[i]=i*fac[i-1]%M;
    inv[0]=inv[1]=1;
    FOR(i,2,1000000) inv[i]=(M-M/i)*inv[M%i]%M;
    FOR(i,1,1000000) inv[i]=inv[i]*inv[i-1]%M;// inv(n!)
}
int main() {
	int startTime=clock();
	//initialize
	initialize();
	debug("/--- initializeTime: %ld milliseconds ---/\n",clock()-startTime);
	int T=1;
//	scanf("%d",&T);
	startTime=clock();
	while (T--) TaskA();
	debug("/--- computeTime: %ld milliseconds ---/\n",clock()-startTime);
}
/*
5 4 20
1 2
2 3
3 4
4 5
1 2
1 3
1 4

*/