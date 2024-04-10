#include <bits/stdc++.h>
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
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const    int N = 200005;
const 	 LL	 P = 123456789LL;
const    int inf = 1e9;

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

int n, k;
int Gt[1005];
int now[1005];
int sum[15];

int ok(){
	FOR(i, 0, k) if(sum[i] > 0) return 0;
	return 1;
}

void add(int x, int f){
	FOR(i, 0, k) if((x >> i) & 1) sum[i] += f; else sum[i] -= f;
}

void dfs(int x){
	if(x > 1 && ok()){
		puts("YES");
		exit(0);
	}
	if(x > 4) return;
	FOR(i, 0, 1 << k)if(Gt[i]){
		Gt[i]--;
		add(i, 1);
		dfs(x + 1);
		add(i, -1);
		Gt[i]++;
	}
}

int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	
	REP(i, 1, n){
		int b = 0;
		REP(j, 1, k){
			int c = 0;
			scanf("%d", &c);
			b = b * 2 + c;
		}
		Gt[b] ++;
	}
	
	dfs(1);
	
	puts("NO");

    return 0;
}