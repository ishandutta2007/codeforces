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
const LL maxn=5e5+107;
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
template<typename T>inline T powMM(T a, T b) {
	T ret=1;
	for (; b; b>>=1ll,a=(LL)a*a%M)
		if (b&1) ret=(LL)ret*a%M;
	return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}
int n,m,q;
char str[maxn];

// QAQ
ll MIN[maxn*4],lazy[maxn*4];
void update(int x,int l,int r,ll val,int L,int R){
	if (l<=L&&R<=r) {MIN[x]+=val; lazy[x]+=val; return;}
	int mid=(L+R)/2;
	if (l<=mid) update(x<<1,l,r,val,L,mid);
	if (mid<r) update(x<<1|1,l,r,val,mid+1,R);
	MIN[x]=min(MIN[x<<1],MIN[x<<1|1])+lazy[x];
	// printf("%d-%d : %lld\n",L,R,MIN[x]);
}
ll query(int x,int l,int r,int L,int R){
	if (l<=L&&R<=r) return MIN[x];
	ll ret=INFF,mid=(L+R)/2;
	if (l<=mid) ret=min(ret,query(x<<1,l,r,L,mid));
	if (mid<r) ret=min(ret,query(x<<1|1,l,r,mid+1,R));
	return ret+lazy[x];
}
vector<pii> edge[maxn];
int in[maxn],out[maxn],tot;
void dfs1(int x,ll dep) {
	in[x]=++tot;
	for (pii e:edge[x]) dfs1(e.first,dep+e.second);
	if (!edge[x].size()) update(1,x,x,dep,1,n);
	else update(1,x,x,INFF,1,n);
	out[x]=tot;
	assert(x==in[x]);
	// printf("upd ok:%d: %d-%d; %d dep=%lld\n",x,in[x],out[x],(int)edge[x].size(),dep);
}
ll ans[maxn];
vector<pair<pii,int> > queries[maxn];
void dfs2(int x){
	for (auto now:queries[x])
		ans[now.second]=query(1,now.first.first,now.first.second,1,n);
	for (pii e:edge[x]){
		int v=e.first,l=e.second;
		update(1,1,n,l,1,n);
		update(1,in[v],out[v],-2*l,1,n);
		dfs2(v);
		update(1,1,n,-l,1,n);
		update(1,in[v],out[v],2*l,1,n);
	}
}
int main() {
	int i;
	scanf("%d%d",&n,&q);
	FOR(i,2,n){
		int f,l;
		scanf("%d%d",&f,&l);
		edge[f].push_back(make_pair(i,l));
	} dfs1(1,0);
	FOR(i,1,q) {
		int l,r,v;
		scanf("%d%d%d",&v,&l,&r);
		queries[v].push_back(make_pair(make_pair(l,r),i));
	} dfs2(1);
	FOR(i,1,q) printf("%lld\n",ans[i]);
}
/*
4
1 10 100 1000
1000 100 10 1
*/