#include <bitset>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int N=2010;

struct Formula {
    bitset<N> g[N]; int r[N];
    int n, m;
    bool ok;

    int op(int x) const { return x<=n ? x+n : x-n; }

    void init(int _n, int _m) {
        n=_n; m=_m;
        rep(i, 1, n*2) g[i].reset();
        rep(i, 1, m) {
            int a, b; scanf("%d%d", &a,&b);
            if(a<0) a=-a+n;
            if(b<0) b=-b+n;
            g[op(a)][b]=g[op(b)][a]=1;
        }
        rep(i, 1, n*2) g[i][i]=1;
        rep(k, 1, n*2) rep(i, 1, n*2) {
            if(g[i][k]) g[i]|=g[k];
        }

        ok=true;
        rep(x, 1, n) if(g[x][x+n] && g[x+n][x]) ok=false;
        if(ok) {
            fillchar(r, 0xff);
            rep(x, 1, n*2) if(g[op(x)][x]) color(x);
        }
    }

    void color(int x) {
        if(r[x]>=0) return;
        r[x]=1, r[op(x)]=0;
        rep(y, 1, n*2) if(g[x][y]) color(y);
    }

    void solve(int c1=-1, int c2=-1) {
        if(c1>0) color(c1);
        if(c2>0) color(c2);
        rep(i, 1, n*2) if(r[i]<0) color(i);
        rep(i, 1, n) printf("%d ", r[i]); printf("\n");
    }
};

bool solve(int n, Formula& f, Formula& g) {
    if(!f.ok) return false;
    if(!g.ok) {
        f.solve(); return true;
    }
    rep(i, 1, n*2) {
        if(f.r[i]!=0 && g.r[i]==0) {
            f.solve(i); return true;
        }
    }
    rep(i, 1, n*2) rep(j, 1, n*2) if(f.r[i]<0 && f.r[j]<0) {
        if(!f.g[i][j] && g.g[i][j]) {
            f.solve(i, f.op(j)); return true;
        }
    }
    return false;
}

int main() {
    static Formula f, g;
    int n, m1, m2; scanf("%d%d%d", &n,&m1,&m2);
    f.init(n, m1);
    g.init(n, m2);
    if(!solve(n, f, g) && !solve(n, g, f)) {
        printf("SIMILAR\n");
    }
    return 0;
}