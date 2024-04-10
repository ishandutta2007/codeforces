#include <algorithm>
#include <unordered_map>
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

int main() {
    int n; scanf("%d", &n);
    vector<VPI> es(n);
    replr(i, 1, n) {
        int j; char ch;
        scanf("%d %c", &j,&ch);
        --j;
        es[i].pb(mp(j, 1<<(ch-'a')));
        es[j].pb(mp(i, 1<<(ch-'a')));
    }
    const int K=22;

    VI ans(n);
    typedef unordered_map<int, int> T;
    const function<T*(int, int, int, int)> dfs=[&](int dep, int x, int fa, int label) {
        T* cur=new T();
        setmax((*cur)[label], dep);
        for(const auto& e: es[x]) {
            if(e.fi!=fa) {
                T* tmp=dfs(dep+1, e.fi, x, label^e.se);
                setmax(ans[x], ans[e.fi]);
                if(sz(*tmp)>sz(*cur)) {
                    swap(cur, tmp);
                }
                for(const auto& kv: *tmp) {
                    repn(i, K+1) {
                        int want=kv.fi;
                        if(i<K) want^=1<<i;
                        const auto it=cur->find(want);
                        if(it!=cur->end()) {
                            setmax(ans[x], kv.se+it->se-dep*2);
                        }
                    }
                }
                for(const auto& kv: *tmp) {
                    setmax((*cur)[kv.fi], kv.se);
                }
            }
        }
        return cur;
    };
    dfs(0, 0, -1, 0);
    repn(i, n) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}