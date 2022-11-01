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

int n;
char op[15];
int gt[15][5];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	FOR(i,0,10) gt[i][0]=0,gt[i][1]=1;
	REP(i,1,n){
		char op[5];
		scanf("%s",op);
		int x;
		scanf("%d",&x);
		if(*op=='|'){
			FOR(j,0,10){
				gt[j][0]|=(x>>j)&1;
				gt[j][1]|=(x>>j)&1;
			}
		}
		if(*op=='^'){
			FOR(j,0,10){
				gt[j][0]^=(x>>j)&1;
				gt[j][1]^=(x>>j)&1;
			}
		}
		if(*op=='&'){
			FOR(j,0,10){
				gt[j][0]&=(x>>j)&1;
				gt[j][1]&=(x>>j)&1;
			}
		}
	}

	int And=0,Xor=0,Or=0;

	FOR(i,0,10){
		if(gt[i][0]==0&&gt[i][1]==0){
			continue;
		}
		if(gt[i][0]==0&&gt[i][1]==1){
			And|=1<<i;
		}
		if(gt[i][0]==1&&gt[i][1]==0){
			And|=1<<i;
			Xor|=1<<i;
		}
		if(gt[i][0]==1&&gt[i][1]==1){
			And|=1<<i;
			Or|=1<<i;
		}
	}

	printf("3\n& %d\n^ %d\n| %d\n",And,Xor,Or);
	

	return 0;
}