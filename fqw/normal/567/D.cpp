// 20:37
// 20:40 - 20:49 - re
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

const int MAXN=200010;

bool vis[MAXN];
int x[MAXN], m; 
int n, k, a, have;

int func(int len) {
    return (len+1)/(a+1);
}

int rt[MAXN], sz[MAXN];
int get_rt(int x) {
    VI v; while(rt[x]!=0) v.pb(x), x=rt[x];
    for(int y: v) rt[y]=x;
    return x;
}

void merge(int x, int y) {
    x=get_rt(x), y=get_rt(y);
    have-=func(sz[x]);
    have-=func(sz[y]);
    rt[x]=y, sz[y]+=sz[x];
    have+=func(sz[y]);
}

void paint(int p) {
    rt[p]=0, sz[p]=1; have+=func(1);
    vis[p]=true;
    if(vis[p-1]) merge(p, p-1);
    if(vis[p+1]) merge(p, p+1);
}

int main() {
    scanf("%d%d%d", &n,&k,&a);
    scanf("%d", &m); 
    fillchar(vis, false);
    rep(i, 1, m) {
        scanf("%d", &x[i]);
        if(vis[x[i]]) x[i]=0; else vis[x[i]]=true;
    }
    VI rest;
    rep(i, 1, n) if(!vis[i]) rest.pb(i);

    fillchar(vis, false);
    have=0;
    for(int p: rest) paint(p);
    if(have>=k) printf("-1\n");
    else {
        while(have<k) {
            if(x[m]>0) paint(x[m]);
            --m;
        }
        printf("%d\n", m+1);
    }

    return 0;
}