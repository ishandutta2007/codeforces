// 20:56
// 21:03 - 
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int MAXN=555;
const int MOD=int(1e9)+7;

int f[2][MAXN][MAXN];
char str[MAXN][MAXN];
int n, m;

void addto(int x, int &y) {
    y+=x; if(y>=MOD) y-=MOD;
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%s", str[i]+1);

    fillchar(f, 0);
    int ans=0, o1=0, o2=1;
    f[o1][1][n]=1;
    rep(i, 1, n) {
        fillchar(f[o2], 0);
        rep(j, 1, m) rep(k, i, n) {
            int l=(n-k+m)-(i-1+j-1);
            if(l<j || l>m) continue;
            if(str[i][j]!=str[k][l])
                continue;
            int val=f[o1][j][k];
            if((k-i)+(l-j)<=1) { addto(val, ans); continue; }
            addto(val, f[o2][j][k-1]);
            addto(val, f[o2][j][k]);
            addto(val, f[o1][j+1][k-1]);
            addto(val, f[o1][j+1][k]);
        }
        swap(o1, o2);
    }
    printf("%d\n", ans);
    
    return 0;
}