#include <algorithm>
#include <cassert>
#include <numeric>
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

int n; 

VI query(VI ws) {
    printf("%d\n", sz(ws));
    for(int i: ws) printf("%d ", i+1);
    printf("\n");
    fflush(stdout);
    VI r(n);
    repn(i, n) scanf("%d", &r[i]);
    return r;
}

void answer(VI ans) {
    printf("-1\n");
    for(int i: ans) printf("%d ", i);
    printf("\n");
    fflush(stdout);
}

VI range(int size) {
    VI r(size);
    iota(all(r), 0);
    return r;
}

int main() {
    scanf("%d", &n);

    vector<VI> t;
    t.pb(range(n));
    VI ans(n, 1<<30);
    while(1) {
        vector<VI> tmp;
        VI ws1, ws2;
        for(const auto& v: t) {
            if(sz(v)==1) {
                tmp.pb(v); continue;
            }
            VI v1(v.begin(), v.begin()+sz(v)/2);
            VI v2(v.begin()+sz(v)/2, v.end());
            ws1.insert(ws1.end(), all(v1));
            ws2.insert(ws2.end(), all(v2));
            tmp.pb(v1), tmp.pb(v2);
        }
        t=tmp;
        if(ws1.empty() || ws2.empty()) break;
        for(const auto& ws: {ws1, ws2}) {
            vector<bool> asking(n, false);
            for(int i: ws) asking[i]=true;
            VI r=query(ws);
            repn(i, n) if(!asking[i]) setmin(ans[i], r[i]);
        }
    }
    answer(ans);

    return 0;
}