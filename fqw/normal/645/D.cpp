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

const int N=100010;
const int M=100010;

VI es[N]; int deg[N];
int u[M], v[M];
int n, m;

bool ok(int first) {
    rep(i, 1, n) es[i].clear();
    rep(i, 1, first) es[u[i]].pb(v[i]);
    fillchar(deg, 0);
    rep(i, 1, first) deg[v[i]]++;

    int head=-1;
    auto try_select=[&](int x) {
        if(deg[x]==0) {
            if(head>0) return false;
            head=x;
        }
        return true;
    };
    rep(x, 1, n) if(!try_select(x)) return false;
    while(head>0) {
        int x=head; head=-1;
        for(int y: es[x]) if(--deg[y]==0) {
            if(!try_select(y)) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n,&m);
    rep(i, 1, m) scanf("%d%d", &u[i],&v[i]);
    int le=1, ri=m;
    while(le<ri) {
        int mid=(le+ri)/2;
        if(ok(mid)) ri=mid;
            else le=mid+1;
    }
    int ans=ok(le)?le:-1;
    printf("%d\n", ans);
    return 0;
}