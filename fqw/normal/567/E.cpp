// 20:52
// 21:17 - 
#include <cassert>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <set>
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
typedef pair<LL,int> PLI;
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

struct Edge {
    int y, i; LL len;
    Edge(int b, int c, int k) : y(b), i(k), len(c) {}
};
vector<Edge> es[MAXN], es_in[MAXN];
int ea[MAXN], eb[MAXN], ec[MAXN];
int n, m, s, t;

LL dis1[MAXN], dis2[MAXN];
int pre1[MAXN], pre2[MAXN];

void cal_dis(vector<Edge> edges[], LL d[], int pre[], int start) {
    rep(i, 1, n) d[i]=1LL<<50;
    multiset<PLI> que;
    d[start]=0; pre[start]=0;
    rep(i, 1, n) que.insert(mp(d[i], i));
    while(!que.empty()) {
        int x=que.begin()->se; 
        que.erase(que.begin());
        for(Edge e: edges[x])
            if(d[x]+e.len<d[e.y]) {
                que.erase(que.find(mp(d[e.y], e.y)));
                d[e.y]=d[x]+e.len;
                pre[e.y]=x;
                que.insert(mp(d[e.y], e.y));
            }
    }
}

set<int> L, R;
multiset<LL> solutions;
bool flag[MAXN];

void add_L(int x) {
    for(Edge e: es[x])
        if(R.count(e.y))
            solutions.insert(dis1[x]+dis2[e.y]+e.len);
    L.insert(x);
}

void del_R(int x) {
    for(Edge e: es_in[x])
        if(L.count(e.y))
            solutions.erase(solutions.find(dis1[e.y]+dis2[x]+e.len));
    R.erase(R.find(x));
}

void solve() {
    VI path, path_e;
    for(int x=s; x>0; x=pre2[x]) path.pb(x);
    int len=(int)path.size()-1;
    rep(i, 0, len-1) {
        int x=path[i], y=path[i+1], ind=-1;
        for(Edge e: es[x]) if(e.y==y && dis1[x]+e.len==dis1[y])
            ind=e.i;
        assert(ind>0);
        path_e.pb(ind);
    }
    fillchar(flag, false);
    rep(i, 0, len-1) flag[path_e[i]]=true;

    solutions.clear();
    L.clear();
    R.clear();
    rep(i, 1, n) R.insert(i);

    vector<PLI> lst1, lst2;
    rep(i, 1, n) lst1.pb(mp(dis1[i], i));
    rep(i, 1, n) lst2.pb(mp(dis2[i], i));
    sort(all(lst1), greater<PLI>());
    sort(all(lst2));

    rep(i, 0, len-1) {
        int x=path[i], y=path[i+1];
        while(lst2.size()>0 && lst2.back().fi>=dis2[x]) {
            del_R(lst2.back().se);
            lst2.pop_back();
        }
        while(lst1.size()>0 && lst1.back().fi<dis1[y]) {
            add_L(lst1.back().se);
            lst1.pop_back();
        }
        //printf("x=%d y=%d\n", x,y);
        //printf("  L="); for(int p: L) printf("%d ", p); printf("\n");
        //printf("  R="); for(int p: R) printf("%d ", p); printf("\n");
        if(solutions.size()>=2) {
            auto it=solutions.begin();
            //printf("  sol0=%lld\n",*it);
            ++it;
            //printf("  sol1=%lld dis2[t]=%lld\n",*it,dis1[t]);
            if(*it==dis1[t]) flag[path_e[i]]=false;
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    rep(i, 1, n) es[i].clear(), es_in[i].clear();
    rep(i, 1, m) {
        int a, b, c; scanf("%d%d%d", &a,&b,&c);
        es[a].pb(Edge(b, c, i));
        es_in[b].pb(Edge(a, c, i));
        ea[i]=a, eb[i]=b, ec[i]=c;
    }

    cal_dis(es, dis1, pre1, s);
    cal_dis(es_in, dis2, pre2, t);

    solve();

    rep(i, 1, m) {
        if(flag[i]) { printf("YES\n"); continue; }
        LL d=(dis1[ea[i]]+dis2[eb[i]]+ec[i])-dis1[t]+1;
        if(d<ec[i]) printf("CAN %lld\n", d);
        else printf("NO\n");
    }

    return 0;
}