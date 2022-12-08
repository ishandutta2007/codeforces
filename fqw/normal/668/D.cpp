#include <algorithm>
#include <cassert>
#include <map>
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

const int N=100010;

int type[N], t[N], xs[N], ans[N];
int n;

PII tr[N];

void add(int lab, int i, int v) {
    for(; i<=n; i+=i&-i) {
        if(tr[i].fi<lab) tr[i]=mp(lab, 0);
        tr[i].se+=v;
    }
}

int get(int lab, int i) {
    int r=0;
    for(; i>=1; i-=i&-i) {
        if(tr[i].fi==lab) r+=tr[i].se;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d%d%d", &type[i],&t[i],&xs[i]);
    VI ts; rep(i, 1, n) ts.pb(t[i]);
    sort(all(ts)); ts.erase(unique(all(ts)), ts.end());
    rep(i, 1, n) t[i]=int(lower_bound(all(ts), t[i])-ts.begin()+1);

    map<int, VI> x_to_is;
    rep(i, 1, n) x_to_is[xs[i]].pb(i);
    fillchar(tr, 0);
    for(const auto& kv: x_to_is) {
        const int x=kv.first;
        for(int i: kv.second) {
            if(type[i]==1) {
                add(x, t[i], 1);
            } else if(type[i]==2) {
                add(x, t[i], -1);
            } else {
                ans[i]=get(x, t[i]);
            }
        }
    }
    rep(i, 1, n) if(type[i]==3) printf("%d\n", ans[i]);

    return 0;
}