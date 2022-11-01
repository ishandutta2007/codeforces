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
const	int N = 100005;
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

int n;
char op[15],s[100005];
int app[10005],tot[100005];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	int deter=0,ans=0;
	char gtw;
	REP(i,'a','z') tot[i]=1;
	REP(i,1,n){
		scanf("%s%s",op,s+1);
		if(!deter){
			int len=strlen(s+1);
			if(*op=='!'){
				REP(j,'a','z') app[j]=0;
				REP(j,1,len) app[s[j]]=1;
				REP(j,'a','z') if(!app[j]) tot[j]=0;
			}else
			if(*op=='.'){
				REP(j,'a','z') app[j]=0;
				REP(j,1,len) app[s[j]]=1;
				REP(j,'a','z') if(app[j]) tot[j]=0;
			}else{
				tot[s[1]]=0;
			}
			int res=0;
			REP(i,'a','z') if(tot[i]) res++;
			//printf("%d\n",res);
			if(res==1){
				deter=1;
				REP(i,'a','z') if(tot[i]) gtw=i;
			}
		}else{
			if(*op=='?'||*op=='!'){
				if(*op=='!') ans++;
				if(*op=='?'&&s[1]!=gtw) ans++;
			}
		}
	}	

	printf("%d\n",ans);

	return 0;
}