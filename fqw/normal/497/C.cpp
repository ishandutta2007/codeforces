#include <algorithm>
#include <set>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
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

const int MAXN=100010;

int a[MAXN], b[MAXN], c[MAXN], d[MAXN], cnt[MAXN];
int ans[MAXN];
int n, m;

int main() {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d%d", &a[i],&b[i]);
    scanf("%d", &m);
    rep(i, 1, m) scanf("%d%d%d", &c[i],&d[i],&cnt[i]);

    vector<pair<PII, int>> parts;
    rep(i, 1, n) parts.pb(mp(mp(a[i],b[i]), i));
    sort(all(parts));
    vector<pair<PII, int>> actors;
    rep(i, 1, m) actors.pb(mp(mp(c[i],d[i]), i));
    sort(all(actors));

    size_t k=0;
    set<pair<int, int>> available;
    bool ok=true;
    for(auto part: parts) {
        while(k<actors.size() && actors[k].fi.fi<=part.fi.fi) {
            available.insert(mp(actors[k].fi.se, actors[k].se));
            ++k;
        }
        auto it=available.lower_bound(mp(part.fi.se, 0));
        if(it==available.end()) {
            ok=false; break;
        }
        int i=it->se;
        ans[part.se]=i;
        --cnt[i];
        if(cnt[i]==0) available.erase(it);
    }

    if(!ok) printf("NO\n");
    else {
        printf("YES\n");
        rep(i, 1, n) printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}