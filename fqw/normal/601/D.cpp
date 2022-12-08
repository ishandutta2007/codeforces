// 9:15
// 9:23 - 
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

const int N=300010;

int c[N]; char str[N]; int s[N];
VI es[N];
int dif[N];
int n;

struct Node {
    int cnt;
    int child[26];
} tr[N];
int node_cnt;

void merge_sub(int x, int c, int y);
int merge(int x, int y) {
    if(x==0) return y;
    if(y==0) return x;
    repn(i, 26)
        merge_sub(x, i, tr[y].child[i]);
    return x;
}

void merge_sub(int x, int i, int y) {
    tr[x].cnt-=tr[tr[x].child[i]].cnt;
    tr[x].child[i]=merge(tr[x].child[i], y);
    tr[x].cnt+=tr[tr[x].child[i]].cnt;
}

int dfs(int x, int fa) {
    int cur=++node_cnt;
    tr[cur].cnt=1;
    for(int y: es[x]) if(y!=fa) {
        int tmp=dfs(y, x);
        merge_sub(cur, s[y], tmp);
    }
    dif[x]=tr[cur].cnt;
    return cur;
}

void cal_dif() {
    fillchar(tr, 0); node_cnt=0;
    dfs(1, 0);
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &c[i]);
    scanf("%s", str+1);
    rep(i, 1, n) s[i]=int(str[i]-'a');
    rep(i, 1, n-1) {
        int x, y; scanf("%d%d", &x,&y);
        es[x].pb(y); es[y].pb(x);
    }

    cal_dif();

    int mx=-1, cn=0;
    rep(i, 1, n) {
        int x=dif[i]+c[i];
        if(x>mx) mx=x, cn=0;
        if(x==mx) ++cn;
    }
    printf("%d\n%d\n", mx, cn);
    return 0;
}