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

int K = 16;
int Cnt[205][1 << 18];
char s[105][105];
char las[505][105], fir[505][105];
int n, len[505];

void Mer(int x, int y){
	++n;
	FOR(i, 0, 1 << 18) Cnt[n][i] = Cnt[x][i] | Cnt[y][i];
	len[n] = min(100, len[x] + len[y]);
	REP(i, 1, len[x]) fir[n][i] = fir[x][i];
	REP(i, 1, len[n] - len[x]) fir[n][i + len[x]] = fir[y][i];
	REP(i, 1, len[y]) las[n][i] = las[y][i];
	REP(i, 1, len[n] - len[y]) las[n][i + len[y]] = las[x][i];
	REP(i, 1, K){
		if(i > len[x]) break;
		int xd = 1;
		PER(j, i, 1) xd = xd * 2 + las[x][j] - '0';
		REP(j, 1, K - i){
			if(j > len[y]) break;
			xd = xd * 2 + fir[y][j] - '0';
			Cnt[n][xd] = 1;
		}
	}
}


int ask(int n){	
	int res = 0;
	REP(ans, 0, K){
		int ok = 1;
		FOR(i, (1 << ans), (1 << (ans + 1))){
			if(!Cnt[n][i]){
				ok = 0;
				break;
			}
		}
		if(ok) res = max(res, ans);
	}
	return res;	
}

int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

	scanf("%d", &n);
	REP(i, 1, n){
		scanf("%s", s[i] + 1);
		int len = strlen(s[i] + 1);
		::len[i] = len;
		REP(j, 1, len) fir[i][j] = s[i][j];
		REP(j, 1, len) las[i][j] = s[i][len - j + 1];
		REP(l, 1, len){
			int x = 1;
			Cnt[i][x] = 1;
			REP(r, l, len){
				if(r-l+1>K)break;
				x = x * 2 + s[i][r] - '0';
				Cnt[i][x] = 1;
			}
		}
	}

	int m;
	scanf("%d", &m);
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		Mer(x, y);
		printf("%d\n", ask(n));
	}	
    return 0;
}