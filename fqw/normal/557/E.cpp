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

const int MAXN=5050;
const int MAXNodes=MAXN*MAXN/2;

bool f[MAXN][MAXN], g[MAXN][MAXN];
char s[MAXN];
int n, ind;

int child[MAXNodes][2], cnt[MAXNodes];
int num;

char ans[MAXN];

void dfs(int cur, int d) {
    ind-=cnt[cur];
    if(ind<=0) {
        ans[d]='\0';
        printf("%s\n", ans);
        return;
    }
    repn(c, 2)
        if(child[cur][c]>0) {
            ans[d]=(c==0?'a':'b');
            dfs(child[cur][c], d+1);
            if(ind<=0) return;
        }
}

int main() {
    scanf("%s%d", s+1, &ind);
    n=(int)strlen(s+1);

    fillchar(f, false);
    fillchar(g, false);
    rep(i, 1, n) {
        f[i][i]=g[i][i]=true;
        f[i][i-1]=g[i][i-1]=true;
    }
    irep(i, n, 1) rep(j, i+1, n) {
        f[i][j]=(g[i+1][j-1] && s[i]==s[j]);
        g[i][j]=f[i+1][j-1];
    }

    fillchar(child, 0);
    fillchar(cnt, 0);
    num=1;
    rep(i, 1, n) {
        int cur=1;
        rep(j, i, n) {
            int c=(s[j]=='a'?0:1);
            if(child[cur][c]==0) child[cur][c]=++num;
            cur=child[cur][c];
            if(f[i][j]) ++cnt[cur];
        }
    }
    dfs(1, 0);

    return 0;
}