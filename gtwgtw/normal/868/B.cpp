#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
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

long double x[5];
int h, m, s, t1, t2;
long double u1, u2;

int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	
	if(h == 12) h = 0;
	x[1] = h * 30 + 30 * (m / 60. + s / 3600.);
	x[2] = 6 * (m + s / 60.);
	x[3] = 6 * s;
	x[4] = 360;
	
	if(t1 == 12) t1 = 0;
	if(t2 == 12) t2 = 0;
	
	u1 = t1 * 30;
	u2 = t2 * 30;
	
	if(u1 > u2) swap(u1, u2);
	
	sort(x + 1, x + 5);
	
	x[4] = x[1] + 360;
	FOR(i, 1, 4){
		if(x[i] < u1 && u1 < x[i + 1] && x[i] < u2 && u2 < x[i + 1]){
			puts("YES");
			return 0;
		}
		if(x[i] < u2 && u2 < x[i + 1] && x[i] < u1 + 360 && u1 + 360 < x[i + 1]){
			puts("YES");
			return 0;
		}
		if(x[i] < u2 + 360 && u2 + 360 < x[i + 1] && x[i] < u1 + 360 && u1 + 360 < x[i + 1]){
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	
	
	
    return 0;
}