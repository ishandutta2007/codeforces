// 9:15
// (next-day)
// 8:06 - 9:03
#include <cassert>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define _ (size_t)
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

const int MAXN=777;
const int MAXL=10001000;

char superstring[MAXL];
int st[MAXN], en[MAXN], original_num[MAXN];
int n, len;

struct Node {
    int child[2];
    int suffix;
    int id;
} nodes[MAXL];
int node_cnt;

bool add(int begin, int end, int id) { // yes
    int x=1; // root
    rep(i, begin, end) {
        int cur=int(superstring[i]-'a');
        if(nodes[x].child[cur]==0)
            nodes[x].child[cur]=++node_cnt;
        x=nodes[x].child[cur];
    }
    if(nodes[x].id>0)
        return false;
    nodes[x].id=id;
    return true;
}

void init() { // yes
    int num; scanf("%d", &num);
    len=n=0;
    node_cnt=1; fillchar(nodes, 0);

    rep(i, 1, num) {
        scanf("%s", superstring+len+1);
        int cl=(int)strlen(superstring+len+1);
        st[n+1]=len+1, en[n+1]=len+cl;
        if(add(st[n+1], en[n+1], n+1)) {
            ++n; len=en[n];
            original_num[n]=i;
        }
    }
}

void build() {
    queue<int> que;
    nodes[1].suffix=1;
    repn(c, 2) {
        if(nodes[1].child[c]==0)
            nodes[1].child[c]=1;
        else {
            que.push(nodes[1].child[c]);
            nodes[nodes[1].child[c]].suffix=1;
        }
    }
    while(!que.empty()) {
        int x=que.front(); que.pop();
        if(nodes[x].id==0) nodes[x].id=nodes[nodes[x].suffix].id;
        repn(c, 2) {
            if(nodes[x].child[c]==0) {
                nodes[x].child[c]=nodes[nodes[x].suffix].child[c];
            } else {
                int y=nodes[x].child[c];
                //if(nodes[y].id==0) nodes[y].id=nodes[x].id;
                que.push(y);
                nodes[y].suffix=nodes[nodes[x].suffix].child[c];
            }
        }
    }
}

bool contains[MAXN][MAXN];
bitset<MAXN> contset[MAXN];

template<size_t N, size_t M> class BipartiteGraph { //{{{
    bool g[N][M], vis[M]; int n, m;
    bool find(int x) {
        for(int y=1; y<=m; ++y)
            if(g[x][y] && !vis[y]) {
                vis[y]=true;
                if(ly[y]==0 || find(ly[y])) {
                    ly[y]=x; lx[x]=y;
                    return true;
                }
            }
        return false;
    }
    void dfs(int x) {
        for(int y=1; y<=m; ++y)
            if(g[x][y] && !vcy[y]) {
                int x0=ly[y]; assert(x0>0 && vcx[x0]);
                vcx[x0]=false; vcy[y]=true;
                dfs(x0);
            }
    }
public:
    int lx[N], ly[M];
    bool vcx[N], vcy[M];
    BipartiteGraph(int _n, int _m) : n(_n), m(_m) {
        assert(n<(int)N && m<(int)M);
        memset(g, false, sizeof(g));
    }
    void addEdge(int i, int j) { g[i][j]=true; }
    void delEdge(int i, int j) { g[i][j]=false; }
    int match() {
        memset(lx, 0, sizeof(lx));
        memset(ly, 0, sizeof(ly));
        int ans=0;
        for(int i=1; i<=n; ++i) {
            memset(vis, false, sizeof(vis));
            if(find(i)) ans++;
        }
        return ans;
    }
    void vc() { // compute vertex cover
        memset(vcx, false, sizeof(vcx));
        memset(vcy, false, sizeof(vcy));
        for(int i=1; i<=n; ++i) if(lx[i]) vcx[i]=true;
        for(int i=1; i<=n; ++i) if(lx[i]==0) dfs(i);
    }
};//}}}

void solve() {
    build();
    fillchar(contains, false);
    rep(i, 1, n) {
        int x=1;
        rep(k, st[i], en[i]) {
            x=nodes[x].child[int(superstring[k]-'a')];
            if(nodes[x].id>0)
                contains[i][nodes[x].id]=true;
        }
        while(x!=1) {
            if(nodes[x].id>0)
                contains[i][nodes[x].id]=true;
            x=nodes[x].suffix;
        }
        contains[i][i]=false;
    }

    rep(i, 1, n) {
        contset[i].reset();
        rep(j, 1, n) contset[i][_ j]=contains[i][j];
    }
    VPI lst;
    rep(i, 1, n) lst.pb(mp(en[i]-st[i], i));
    sort(all(lst));
    for(PII p: lst) { int i=p.se;
        rep(j, 1, n) if(contains[i][j]) contset[i]|=contset[j];
        rep(j, 1, n) contains[i][j]=contset[i][_ j];
    }

/*
    rep(i, 1, n) rep(j, 1, n) if(i!=j) {
        string x(superstring+st[i], superstring+en[i]+1);
        string y(superstring+st[j], superstring+en[j]+1);
        bool sub=(x.find(y)!=string::npos);
        if(sub!=contains[i][j]) {
            printf("sub=%d but wrong\n", sub);
            printf("x=%s\n", x.c_str());
            printf("y=%s\n", y.c_str());
            rep(i, 1, n) rep(j, 1, n) if(contains[i][j]) printf("contains %d %d\n", i, j);
            return;
        }
    }
    */

    //printf("n=%d\n", n);
    //rep(i, 1, n) rep(j, 1, n) if(contains[i][j]) printf("%d %d\n",i,j);
    BipartiteGraph<MAXN,MAXN> *g=new BipartiteGraph<MAXN,MAXN>(n, n);
    rep(i, 1, n) rep(j, 1, n)
        if(contains[i][j])
            g->addEdge(i, j);
    g->match();
    g->vc();

    VI ans;
    rep(i, 1, n) if(!g->vcx[i] && !g->vcy[i]) ans.pb(original_num[i]);
    printf("%d\n", (int)ans.size());
    for(int x: ans) printf("%d ", x); printf("\n");
}

int main() {
    init();
    solve();
    return 0;
}