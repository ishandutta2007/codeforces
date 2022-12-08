#include <cassert>
#include <set>
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

const int N=300030;

VI es[N];
int n;

int f[N], size[N];
int get(int x) {
    return f[x]==0 ? x : f[x]=get(f[x]);
}

bool solve() {
    int m, k; scanf("%d%d%d",&n,&m,&k);
    rep(i, 1, m) {
        int a, b; scanf("%d%d", &a,&b);
        if(a>b) swap(a, b);
        es[a].pb(b);
    }
    fillchar(f, 0); rep(i, 1, n) size[i]=1;
    static PII cnt[N]; rep(i, 1, n) cnt[i]=mp(1<<30, 0);

    if(n-1-sz(es[1])<k) return false;
    set<int> comps;
    irep(i, n, 1) {
        if(i==1) {
            if(sz(comps)>k) return false;
        }
        set<int> tmp=comps; comps.clear();
        for(int j: es[i]) {
            int rj=get(j);
            if(cnt[rj].fi>i) cnt[rj]=mp(i, 0);
            if(++cnt[rj].se==size[rj]) {
                tmp.erase(rj);
                comps.insert(rj);
            }
        }
        for(int rj: tmp) {
            size[i]+=size[rj];
            f[rj]=i;
        }
        comps.insert(i);
    }
    return comps.size()==1;
}

int main() {
    printf("%s\n", solve()?"possible":"impossible");
    return 0;
}