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

int wei, tou;
int n;
char s[5], gt[5];

int main(){
#ifdef LOCAL
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
#endif

	scanf("%s", s + 1);
	scanf("%d", &n);
	REP(i, 1, n){
		scanf("%s", gt + 1);
		if(gt[1] == s[1] && gt[2] == s[2]){
			puts("YES");
			return 0;
		}
		if(gt[2] == s[1]) wei = 1;
		if(gt[1] == s[2]) tou = 1;
	}
	
	if(wei && tou){
		puts("YES");
		return 0;
	}
	
	puts("NO");

    return 0;
}