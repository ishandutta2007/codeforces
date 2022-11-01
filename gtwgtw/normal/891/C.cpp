#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 500005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int id[N],ux[N],vx[N],wx[N],fa[N],rk[N];
int nows,bel[N],seq[N],ans[N],n,m,q;
VPI B[N];

int cmp(const int &a,const int &b){
	return wx[a]<wx[b];
}

int rec[N],rtot;

int get(int x){
	while(fa[x]!=x) x=fa[x];
	return x;
}

int mer(int x,int y){
	int u=get(x),v=get(y);
	if(rk[u]>rk[v]) swap(u,v);
	if(u==v) return 0;
	rec[++rtot]=u;
	if(rk[u]==rk[v]) ++rk[v];
	fa[u]=v; 
	return 1;
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d",&n,&m);
	REP(i,1,n) fa[i]=i,rk[i]=0;
	REP(i,1,m){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		id[i]=i;
		ux[i]=x;
		vx[i]=y;
		wx[i]=w;
	}

	sort(id+1,id+m+1,cmp);
	int gcnt=0;
	REP(x,1,m){
		++gcnt;
		int y=x;
		while(y<=m&&wx[id[y]]==wx[id[x]])++y;--y;
		REP(w,x,y) bel[id[w]]=gcnt;
		x=y;
	}

	scanf("%d",&q);
	REP(gt,1,q){
		scanf("%d",&nows);
		REP(x,1,nows){
			int xw=0;
			scanf("%d",&xw);
			B[bel[xw]].pb(PII(gt,xw));
		}
	}


	int now=1;
	REP(i,1,gcnt){
		int SZ=B[i].size();
		FOR(u,0,SZ){
			int v=u;
			while(v<SZ&&B[i][v].fi==B[i][u].fi) ++v;--v;
			REP(w,u,v){
//				if(i==2)printf("__%d\n",B[i][w].se);
				if(!mer(ux[B[i][w].se],vx[B[i][w].se])){
					ans[B[i][w].fi]=1;
					break;
				}
			}
			for(;rtot;--rtot) fa[rec[rtot]]=rec[rtot];
			u=v;
		}
		while(now<=m&&bel[id[now]]==i){
			mer(ux[id[now]],vx[id[now]]);
			++now;
		}
		rtot=0;
	}

	REP(i,1,q) if(ans[i]) puts("NO"); else puts("YES");


	return 0;
}