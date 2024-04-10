#include <set>
#include <map>
#include <list>
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
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 200005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e18;

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
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n,T,a[N],l[N],id[N];

inline int cmp(const int &x,const int &y){
	return a[x]<a[y];
}

int sm[40005];
LL gsm[40005];
VI gg[40005];

void add(int x,int L,int R,int u,int v){
	sm[x]++;
	gsm[x]+=u;
	if(L==R){
		gg[x].pb(v);
		return;
	}
	int md=(L+R)/2;
	if(u<=md) add(x*2,L,md,u,v);
	else add(x*2+1,md+1,R,u,v);
}

LL ask(int u,int L,int R,int k){
	if(L==R) return 1LL*k*L;
	int md=(L+R)/2;
	if(k<=sm[u*2]) return ask(u*2,L,md,k);
	else return gsm[u*2]+ask(u*2+1,md+1,R,k-sm[u*2]);
}

int gk;
void get(int u,int L,int R){
	if(!gk)exit(0);
	if(L==R){
		for(auto v:gg[u]){
			printf("%d ",v);
			gk--;
			if(!gk){puts("");exit(0);}
		}
		return;
	}
	int md=(L+R)/2;
	get(u*2,L,md);
	get(u*2+1,md+1,R);
}

LL ask(int k){
	return ask(1,1,10000,k);
}

void get(int k){
	gk=k;
	get(1,1,10000);
}

void add(int x,int y){
	add(1,1,10000,x,y);
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d",&n,&T);
	REP(i,1,n) scanf("%d%d",a+i,l+i);
	REP(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	int cnt=0,now=n;
	PER(k,n,1){
		while(now>=1&&a[id[now]]>=k){
			add(l[id[now]],id[now]);
			now--;
			cnt++;
		}
		//if(cnt>=k)cout<<ask(k)<<endl;
		if(cnt>=k&&ask(k)<=T){
			printf("%d\n%d\n",k,k);
			get(k); 
			return 0;
		}
	}
	puts("0\n0\n\n");
	return 0;
}