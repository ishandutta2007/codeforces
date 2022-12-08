#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

const int N=1010;
const int M=N*N;

struct Edge {
    int a, b, w, i;
    bool operator<(const Edge& e) const { return w>e.w; }
} es[M];
int n, m, q;

PII f[N];
PII get(int x) {
    if(f[x].fi==0) return mp(x, 0);
    PII r=get(f[x].fi);
    r.se^=f[x].se;
    return f[x]=r;
}

int main() {
    scanf("%d%d%d", &n,&m,&q);
    rep(i, 1, m) {
        scanf("%d%d%d", &es[i].a, &es[i].b, &es[i].w);
        es[i].i=i;
    }
    sort(es+1, es+m+1);

    while(q--) {
        int l, r; scanf("%d%d", &l,&r);
        int ans=-1;
        fillchar(f, 0);
        rep(i, 1, m) if(es[i].i>=l && es[i].i<=r) {
            PII u=get(es[i].a), v=get(es[i].b);
            if(u.fi==v.fi) {
                if(u.se==v.se) {
                    ans=es[i].w; break;
                }
            } else {
                f[u.fi]=mp(v.fi, 1^u.se^v.se);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}