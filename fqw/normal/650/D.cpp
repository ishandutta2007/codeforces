// 15:31
#include <cassert>
#include <algorithm>
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

const int MAXN=400010;
const int MAXQ=400010;

struct Query {
    int i, new_val;
    int f[2];
};

struct Pos {
    int i, val;
    vector<Query*> qs;
    int f[2];
    bool required;
};

int go(vector<Pos>* as, int o) {
    static const int maxval=1<<30;
    VI vs(as->size()+1, maxval);
    auto get=[&vs](int x) { return int(lower_bound(all(vs), x)-vs.begin()); };
    for(auto& a: *as) {
        for(auto& q: a.qs) q->f[o]=get(q->new_val);
        a.f[o]=get(a.val);
        vs[a.f[o]]=a.val;
    }
    return get(maxval);
}

int main() {
    int n, m; scanf("%d%d", &n,&m);
    vector<Pos> as(n);
    vector<Query> qs(m);
    for(auto& a: as) scanf("%d", &a.val);
    repn(i, n) as[i].i=i;
    for(auto& q: qs) {
        scanf("%d%d", &q.i,&q.new_val);
        --q.i; as[q.i].qs.pb(&q);
    }

    int len=go(&as, 0);

    reverse(all(as));
    for(auto& a: as) a.val*=-1;
    for(auto& q: qs) q.new_val*=-1;
    int len2=go(&as, 1);
    reverse(all(as));
    assert(len2==len);

    VI ids(len, -1);
    for(const auto& a: as) if(a.f[0]+1+a.f[1]==len) {
        int p=a.f[0];
        if(ids[p]==-1) ids[p]=a.i;
            else ids[p]=-2;
    }
    for(auto& a: as)
        a.required=(a.f[0]+1+a.f[1]==len && ids[a.f[0]]==a.i);

    for(const auto& q: qs) {
        int ans=q.f[0]+1+q.f[1];
        setmax(ans, len-(as[q.i].required?1:0));
        printf("%d\n", ans);
    }

    return 0;
}