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
const	int N = 200005;
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

int fa[N],ux[N],vx[N],wx[N],id[N],dj[N],n,m;

int cmp(const int &a,const int &b){
	return wx[a]>wx[b];
}

int get(int u){
	if(fa[u]==u) return u;
	return fa[u]=get(fa[u]);
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d",&n,&m);
	REP(i,1,n) fa[i]=i;
	REP(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ux[i]=u;
		vx[i]=v;
		wx[i]=w;
		id[i]=i;
	}

	sort(id+1,id+m+1,cmp);
	LL ans=0;
	REP(i,1,m){
		int du=ux[id[i]],dv=vx[id[i]],dw=wx[id[i]];
		du=get(du);
		dv=get(dv);
		if(du!=dv){
			if(dj[du]&&dj[dv])continue;
			ans+=dw;
			fa[du]=dv;
			dj[dv]|=dj[du];
		}else{
			if(dj[dv]) continue;
			dj[dv]=1;
			ans+=dw;
		}
	}

	cout<<ans<<endl;


	return 0;
}