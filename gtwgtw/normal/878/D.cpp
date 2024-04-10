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
const	int N = 100005;
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

int v[100005][15],cnt,n,k,q;
bitset<4100> A[100050];
int id[100005][15],cmpd;

int cmp(const int &a,const int &b){
	return v[cmpd][a]<=v[cmpd][b];
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d%d",&n,&k,&q);

	REP(i,1,k) REP(j,1,n) scanf("%d",&v[j][i]);

	REP(i,1,k){
		FOR(j,0,1<<k) if((j>>(i-1))&1) A[i].set(j);
	}

	REP(i,1,n){
		REP(j,1,k) id[i][j]=j;
		cmpd=i;
		sort(id[i]+1,id[i]+k+1,cmp);
	}

	int xk=k;
	REP(i,1,q){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			++k;
			A[k]=A[x]&A[y];
		}else
		if(t==2){
			++k;
			A[k]=A[x]|A[y];
		}else{
			int S=0,ans;
			REP(j,1,xk){
				int u=id[y][j];
				S|=1<<(u-1);
				if(A[x][S]){
					ans=v[y][u];
					break;
				}
			}
			printf("%d\n",ans);
		}
	}

	return 0;
}