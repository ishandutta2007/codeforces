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

int L[N],R[N],stk[N],top;
int S[20][N],lg[N],n,a[N];

int Or(int l, int r){
	int t=lg[r-l+1];
	return S[t][l]|S[t][r-(1<<t)+1];
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	REP(i,1,n) scanf("%d",a+i);
	top=0;
	REP(i,1,n){
		while(top&&a[stk[top]]<a[i])top--;
		if(!top)L[i]=0;else L[i]=stk[top];
		stk[++top]=i;
	}
	memset(stk,0,sizeof stk); top=0;
	PER(i,n,1){
		while(top&&a[stk[top]]<=a[i])top--;
		if(!top)R[i]=n+1;else R[i]=stk[top];
		stk[++top]=i;
	}

	REP(i,1,n) S[0][i]=a[i];
	REP(i,2,n) lg[i]=lg[i>>1]+1;
	REP(i,1,18){
		REP(j,1,n-(1<<i)+1) S[i][j]=S[i-1][j]|S[i-1][j+(1<<(i-1))];
	}

	LL ans=1LL*n*(n+1)/2;

	REP(M,1,n){
		int gl=L[M]+1,gr=M,aim1=M;
		int xl=M,xr=R[M]-1,aim2=M;

		while(gl<=gr){
			int md=(gl+gr)/2;
			if(Or(md,M)==a[M]){
				gr=md-1;
				aim1=md;
			}else{
				gl=md+1;
			}
		}

		while(xl<=xr){
			int md=(xl+xr)/2;
			if(Or(M,md)!=a[M]){
				xr=md-1;
			}else{
				xl=md+1;
				aim2=md;
			}
		}

		ans-=1LL*(aim2-M+1)*(M-aim1+1);

	}

	printf("%lld\n",ans);
	

	return 0;
}