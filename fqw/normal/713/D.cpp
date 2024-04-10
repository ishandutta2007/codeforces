#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=1010;
const int LOG=11;

int a[N][N], val[N][N], rmq[N][N][LOG][LOG];
int logv[N];
int n, m;

void prepare() {
    static int l[N][N], u[N][N];
    fillchar(l, 0); fillchar(u, 0);
    rep(i, 1, n) rep(j, 1, m) {
        if(a[i][j]==1) {
            l[i][j]=l[i][j-1]+1;
            u[i][j]=u[i-1][j]+1;
        }
    }
    fillchar(val, 0);
    rep(i, 1, n) rep(j, 1, m) {
        if(a[i][j]==1) {
            val[i][j]=1+min(val[i-1][j-1], min(l[i][j-1], u[i-1][j]));
        }
    }
    fillchar(rmq, 0);
    rep(i, 1, n) rep(j, 1, m) {
        rmq[i][j][0][0]=val[i][j];
    }
    rep(i, 1, n) rep(y, 1, LOG-1) rep(j, 1, m-(1<<y)+1) {
        rmq[i][j][0][y]=max(rmq[i][j][0][y-1], rmq[i][j+(1<<(y-1))][0][y-1]);
    }
    rep(x, 1, LOG-1) rep(i, 1, n-(1<<x)+1) rep(j, 1, m) repn(y, LOG) {
        rmq[i][j][x][y]=max(rmq[i][j][x-1][y], rmq[i+(1<<(x-1))][j][x-1][y]);
    }

    repn(x, LOG) {
        rep(i, 1<<x, min(N-1, (1<<(x+1))-1)) {
            logv[i]=x;
        }
    }
}

int get(int i1, int j1, int i2, int j2) {
    const int x=logv[i2-i1+1], i3=i2-(1<<x)+1;
    const int y=logv[j2-j1+1], j3=j2-(1<<y)+1;
    return max(max(rmq[i1][j1][x][y], rmq[i3][j1][x][y]),
               max(rmq[i1][j3][x][y], rmq[i3][j3][x][y]));
}

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d%d", &n,&m);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
    prepare();

    int t; scanf("%d", &t);
    while(t--) {
        int i1, j1, i2, j2; scanf("%d%d%d%d", &i1,&j1,&i2,&j2);
        int le=0, ri=min(i2-i1+1, j2-j1+1);
        while(le<ri) {
            const int len=(le+ri+1)/2;
            if(get(i1+len-1, j1+len-1, i2, j2)>=len) {
                le=len;
            } else {
                ri=len-1;
            }
        }
        printf("%d\n", le);
    }

    return 0;
}