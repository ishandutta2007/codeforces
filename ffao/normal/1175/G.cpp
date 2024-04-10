#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(int& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <functional>

int n,k;
int a[21000];

typedef long long num_t;
const num_t oo = (num_t) 1e18;//9;

num_t dp[21000][110];

// int nodes = 0;

struct func_t {
    num_t a, b;
    func_t(num_t a = 0, num_t b = oo) : a(a), b(b) {}
    num_t query(num_t x) const {return a * x + b;}
};
struct node_t {
    node_t *l, *r;
    func_t f;
    node_t(node_t* l = 0, node_t* r = 0, func_t f = func_t()) : l(l), r(r), f(f) {}
    num_t query(num_t x) {return f.query(x);}
};

int used;
node_t nodes[1975893];
node_t* new_node() {return &nodes[used++];}

node_t* upd(node_t* p, int l, int r, int L, int R, func_t f) {
    // dbg("upd", l, r, L, R, f.a, f.b);
    if (l > R || r < L) return p;
    int M = L + ((R - L) >> 1);
    node_t *res = new_node();
    *res = p ? node_t(p->l, p->r, p->f) : node_t();
    // nodes++;

    if (f.query(M) <=  (p ? p->query(M) : oo)) swap(res->f, f);
    if (f.query(L) < res->query(L)) res->l = upd(res->l, l, r, L, M, f);
    if (f.query(R) < res->query(R)) res->r = upd(res->r,l,r,M+1,R, f);

    return res;
}

num_t query(node_t* p, int i, int L, int R) {
    // dbg("query",i,L,R,(int)(p==NULL));
    if (!p) return oo;
    if (i < L || i > R) return oo;
    num_t res = p->query(i);
    // dbg(res);
    if (L < R) {
        res = min(res, query(p->l, i, L, (L + R) >> 1));
        res = min(res, query(p->r, i, ((L + R) >> 1) + 1, R));
    }
    return res;
}

node_t *merge(node_t* left, node_t *right, int lts, int lte, int rts, int rte, int part) {
    int ltsz = lte - lts+1;
    int rtsz = rte - rts+1;

    if (rtsz > ltsz) {
        swap(left,right);
        swap(lte,rte);
        swap(lts,rts);
    }

    for (int i = rts; i <= rte; i++) {
        left = upd(left,0,20000,0,20000,func_t{-i+1,dp[i-1][part-1]});
    }
    
    return left;
}

int stam;
int fr[21000];
node_t* curhullAs[21000][110];
node_t* curhullBs[21000][110]; 

long long go() {
    rep(i,1,k+1) dp[0][i] = oo;
    rep(i,1,n+1) dp[i][0] = oo;
    
    rep(part,1,k+1) {
        // dbg(used);
        used = 0;
        stam = 0;

        for (int i = 1; i <= n; i++) {
            node_t *curhullA = upd(NULL,0,20000,0,20000,func_t{-i+1,dp[i-1][part-1]});

            int up_to = i;
            
            while (stam && a[fr[stam-1]] <= a[i]) {
                int lts = (stam >= 2 ? fr[stam-2]+1 : 1);
                curhullA = merge(curhullAs[stam-1][part], curhullA, lts, up_to-1, up_to, i, part);

                up_to = lts;
                stam--;
            }

            curhullAs[stam][part] = curhullA;

            // int pn = nodes;
            if (part <= i) {
                num_t icp = query(curhullA,a[i],0,20000);
                // dbg("add curB", icp.first, icp.second);
                curhullBs[stam][part] = upd(stam==0 ? NULL : curhullBs[stam-1][part], 0, 20000, 0, 20000, func_t{a[i], icp});
                
                num_t r = query(curhullBs[stam][part],i,0,20000);
                dp[i][part] = r;
                //dbg(i,part,dp[i][part],"comes from", r.second, "incrementing", r.first, "icp was", icp.first);
            }
            else dp[i][part] = oo;

            fr[stam++] = i;
        }

    }

    return dp[n][k];
}

void solve()
{
    re(n,k);
    rep(i,1,n+1) re(a[i]);

    ps(go());
    // dbg(nodes, nodes*16 + (int)sizeof(dp));
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}