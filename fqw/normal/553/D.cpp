#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
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

VI es[MAXN];
bool is_fort[MAXN];
int n;

bool chosen[MAXN], ans[MAXN];
int needed[MAXN], rest[MAXN];

queue<int> que;
void exclude(int x) {
    assert(chosen[x]);
    chosen[x]=false;
    que.push(x);
}

bool ok(double ratio) {
    rep(i, 1, n) {
        needed[i]=(int)ceil(double(es[i].size())*ratio);
        rest[i]=(int)es[i].size();
    }
    fillchar(chosen, true);
    que=queue<int>();
    rep(i, 1, n) if(is_fort[i]) exclude(i);
    while(!que.empty()) {
        int x=que.front(); que.pop();
        for(int y: es[x])
            if(chosen[y]) {
                --rest[y];
                if(rest[y]<needed[y])
                    exclude(y);
            }
    }
    rep(i, 1, n) if(chosen[i]) return true;
    return false;
}

int main() {
    int m, k;
    scanf("%d%d%d", &n,&m,&k);
    fillchar(is_fort, false);
    repn(i, k) {
        int a; scanf("%d", &a);
        is_fort[a]=true;
    }
    rep(i, 1, n) es[i].clear();
    repn(i, m) {
        int a, b; scanf("%d%d", &a,&b);
        es[a].pb(b), es[b].pb(a);
    }

    rep(i, 1, n) ans[i]=!is_fort[i];
    double le=0, ri=1;
    repn(times, 99) {
        double mid=(le+ri)/2;
        if(ok(mid)) {
            memcpy(ans, chosen, sizeof(ans));
            le=mid;
        }
        else ri=mid;
    }
    //printf("%.9lf\n", ri);
    int cnt=0;
    rep(i, 1, n) if(ans[i]) ++cnt;
    printf("%d\n", cnt);
    rep(i, 1, n) if(ans[i]) printf("%d ", i); printf("\n");

    return 0;
}