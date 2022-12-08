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

const int MAXN=1000010;
const int MAXLog=20;

char s[MAXN], tmp[MAXN];
int n, m;

int lnk[MAXN], go[MAXN][MAXLog];
int a[MAXN], b[MAXN];

void solve(int k, int d0) {
    int cur=0;
    repn(j, d0) for(int i=j; i<k; i+=d0) a[cur++]=i;
    assert(cur==k);

    int maxlog=0; while((1<<maxlog)<=n) ++maxlog;

    repn(i, k) lnk[i]=a[i]+1; lnk[k]=k;
    repn(i, k+1) go[i][0]=lnk[i];
    rep(j, 1, maxlog-1) repn(i, k+1) go[i][j]=go[go[i][j-1]][j-1];

    repn(i, n) {
        int init=max(0, i-n+k), init_pos=i-init;
        int steps=min(i, n-k)+1, rest=steps;
        int x=init;
        irepn(j, maxlog) 
            if(rest>=(1<<j)) {
                int y=go[x][j];
                if(y!=k) {
                    x=y; rest-=(1<<j);
                }
            }
        if(x!=k && rest>0) {
            --rest; x=go[x][0];
        }
        int pos=init_pos-(steps-rest);
        b[i]=pos+x;
        //printf("i=%d init=%d init_pos=%d steps=%d d=%d x=%d pos=%d\n",i,init,init_pos,steps,d,x,pos);
    }
    //repn(i, n) printf("%d ", b[i]); printf("\n");
    repn(i, n) tmp[i]=s[b[i]];
    repn(i, n) s[i]=tmp[i];
}

int main() {
    //*
    gets(s); n=(int)strlen(s);
    scanf("%d", &m);
    while(m--) {
        int k, d; scanf("%d%d", &k,&d);
        solve(k, d);
        s[n]='\0'; puts(s); //printf("%s\n", s);
    }
    /*/
    s[0]='a', s[1]='\0', n=1;
    repn(i, 1000000) {
        solve(1,1);
        }
    //*/
    return 0;
}