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

char s[100005],A[100005],ss[100005];
int app[100005];
int nxt[100005],len,n,bg[100005],pre[100005];
int b[100005],e[100005];

int vis[100005];
void dfs(int x){
	if(!x) return ;
	if(vis[x]){
		puts("NO");
		exit(0);
	}
	vis[x]=1;
	A[++len]=x+'a'-1;
	dfs(nxt[x]);
}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	REP(i,1,n){
		scanf("%s",s+1);
		int len=strlen(s+1);
		b[i]=e[i-1]+1;
		e[i]=e[i-1]+len;
		REP(j,1,len) app[s[j]-'a'+1]=1;
		FOR(j,1,len){
			if(nxt[s[j]-'a'+1]){
				int nxtx=s[j+1]-'a'+1;
				if(nxtx!=nxt[s[j]-'a'+1]){
					puts("NO");
					exit(0);
				}
			}
			nxt[s[j]-'a'+1]=s[j+1]-'a'+1;
			if(pre[s[j+1]-'a'+1]&&pre[s[j+1]-'a'+1]!=s[j]-'a'+1){
				puts("NO");
				exit(0);
			}
			pre[s[j+1]-'a'+1]=s[j]-'a'+1;
		}
	}

	REP(i,1,26) if(app[i]&&!pre[i]) dfs(i);

	REP(i,1,26) if(app[i]&&!vis[i]){
		puts("NO");
		exit(0);
	}
	
	REP(i,1,n) if(e[i]-b[i]+1>len){
		puts("NO");
		exit(0);
	}

	puts(A+1);

	return 0;
}