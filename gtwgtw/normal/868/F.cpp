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
int a[N];
LL dp[N], xdp[N];
LL Cnt[N], nowans;
int nowl, nowr;

void add(int x){
	nowans += Cnt[a[x]];
	Cnt[a[x]] ++;
}

void del(int x){
	Cnt[a[x]]--;
	nowans -= Cnt[a[x]];
}

void Move(int dl, int dr){
	while(nowr < dr){
		++nowr;
		add(nowr);
	}
	while(nowl > dl){
		--nowl;
		add(nowl);
	}
	while(nowr > dr){
		del(nowr);
		--nowr;
	}
	while(nowl < dl){
		del(nowl);
		++nowl;
	}
}

void work(int L, int R, int xl, int xr){
	if(xl > xr) return;
	int md = (L + R) / 2;
	int pm = xl;
	Move(pm, md);
	int rm = xl;
	for(int pm = xl; pm <= md && pm <= xr; pm ++){
		Move(pm, md);
		LL now = nowans + xdp[pm - 1];
		if(now < dp[md]){
			dp[md] = now;
			rm = pm;
		}
	}
	if(md + 1 <= R){
		Move(rm, md + 1);
		work(md + 1, R, rm, xr);
	}
	Move(xl, L);
	if(L <= md - 1){
		work(L, md - 1, xl, rm);
	}
}

int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	REP(i, 1, n) scanf("%d", a + i);
	
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	REP(i, 1, k){
		memcpy(xdp, dp, sizeof xdp);
		memset(dp, 0x3f, sizeof dp);
		memset(Cnt, 0, sizeof Cnt);
		nowans = 0;
		REP(i, 1, n) add(i);
		nowl = 1;
		nowr = n;
		work(1, n, 1, n);
	}
	
	printf("%lld\n", dp[n]);
	
    return 0;
}