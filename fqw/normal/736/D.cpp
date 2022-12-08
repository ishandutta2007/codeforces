#include <algorithm>
#include <bitset>
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

void print(const vector<bitset<2000>>& a) {
    repn(i, sz(a)) {
        repn(j, sz(a)) printf("%d", int(a[i][j]));
        printf("\n");
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    VPI es(m);
    repn(i, m) {
        scanf("%d%d", &es[i].fi, &es[i].se);
        --es[i].fi, --es[i].se;
    }
    vector<bitset<2000>> a(n), b(n);
    repn(k, m) a[es[k].fi][es[k].se]=1;
    repn(i, n) b[i][i]=1;
    repn(i, n) {
        replr(j, i, n) {
            if(a[j][i]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                break;
            }
        }
        assert(a[i][i]);
        replr(j, i+1, n) {
            if(a[j][i]) {
                a[j]^=a[i];
                b[j]^=b[i];
            }
        }
    }
    irepn(i, n) {
        assert(a[i][i]);
        repn(j, i) {
            if(a[j][i]) {
                a[j]^=a[i];
                b[j]^=b[i];
            }
        }
    }
    repn(k, m) {
        printf("%s\n", b[es[k].se][es[k].fi]?"NO":"YES");
    }
    return 0;
}