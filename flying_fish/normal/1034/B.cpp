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
const LL maxn=3e5+7;
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
int n,m,q;
char str[maxn];
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

int i,j,k,t;
vector<int>edge[maxn];
int used[maxn];
queue<int> Q;
int matching[maxn];//
int check[maxn];//matchright
int BFS(int n) {
	static int prev[maxn];//
	int ans=0,i,j;
	memset(matching,-1,sizeof(matching));
	memset(check,-1,sizeof(check));
	FOR(i,1,n) {
		if (matching[i]==-1) {
			while (!Q.empty()) Q.pop();
			Q.push(i);
			prev[i]=-1;
			bool flag=false;
			while (!Q.empty()&&!flag) {
				int u=Q.front(); Q.pop();
				for (j=0; !flag&&j<(int)edge[u].size(); j++) {
					int v=edge[u][j];
					if (check[v]!=i) {
						check[v]=i;
						Q.push(matching[v]);
						if (matching[v]!=-1) prev[matching[v]]=u;
						else {
							flag=1;
							int d=u,e=v;
							while (d!=-1) {
								int t=matching[d];
								matching[d]=e;
								matching[e]=d;
								d=prev[d];
								e=t;
							}
						}
					}
				}
			}
			if (matching[i]!=-1) ans++;
		}
	}
	return ans;
}

int id[1007][1007];
int solve(int n,int m) {//
	int i,j,_i,_j,tot=0;
	FOR(i,1,n) FOR(j,1,m) if (!((i+j)&1)) id[i][j]=++tot;
	int C=tot;
	FOR(i,1,n) FOR(j,1,m) if (((i+j)&1)) id[i][j]=++tot;

	FOR(i,1,n) FOR(j,1,m) if (!((i+j)&1)){
		FOR(_i,max(1,i-3),min(n,i+3)) FOR(_j,max(1,j-3),min(m,j+3))
			if (abs(i-_i)+abs(j-_j)==3){
				// printf("%d(%d %d) -> %d(%d %d)\n",id[i][j],i,j,id[_i][_j],_i,_j);
				edge[id[i][j]].push_back(id[_i][_j]);
			}
	} return n*m-BFS(C)*2;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	ll ans=(ll)n*m;
	if (n>66) n=n%6+66;
	if (m>66) m=m%6+66;
	ans-=solve(n,m);
	printf("%I64d\n",ans);
}
/*
*/