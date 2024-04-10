#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;

template <typename cost_t> 
struct mincost {
    struct edge {
        int dest, cap;
        cost_t w;
        int rev;
        edge(int a, int b, int c, int d): dest(a), cap(b), w(c), rev(d) {}
    };

    const cost_t inf = std::numeric_limits<cost_t>::max()/2 - 100;

    std::vector< std::vector<edge> > g;
    std::vector<cost_t> d;
    std::vector<int> p, ed;
    std::vector<bool> inq;
    
    mincost(int n) : g(n), d(n), p(n), ed(n), inq(n) {}
    void add_edge(int a, int b, int c, int d);
    bool spfa(int s, int t, int &f, cost_t &c);
    pair<int, int> operator()(int s, int t);
};
#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);
template<class T> void re(std::vector<T>& a);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


int n;
vector<int> a;

int nxt[110000];
int nxt7[110000];

void solve()
{
    re(n);
    a.resize(n); re(a);

    int tot = 3*n + 3;
    int s0 = 3*n;
    int s = 3*n+1;
    int t = 3*n+2;

    mincost<int> mcmf(tot); 
    mcmf.add_edge(s0, s, 4, 0);

    for (int i = n-1; i >= 0; i--) {
        mcmf.add_edge(s, 3*i, 1, 0);
        mcmf.add_edge(3*i, 3*i+1, 1, -1);
        mcmf.add_edge(3*i+1, t, 1, 0);
        mcmf.add_edge(3*i+2, 3*i, 4, 0);

        if (nxt[a[i]+1] != 0) mcmf.add_edge(3*i+1, 3*nxt[a[i]+1], 4, 0);
        if (nxt[a[i]-1] != 0) mcmf.add_edge(3*i+1, 3*nxt[a[i]-1], 4, 0);
        if (nxt7[a[i]%7] != 0) {
            mcmf.add_edge(3*i+1, 3*nxt7[a[i]%7]+2, 4, 0);
            mcmf.add_edge(3*i+2, 3*nxt7[a[i]%7]+2, 4, 0);
        }

        nxt[a[i]]=i;
        nxt7[a[i]%7]=i;
    }

    ps(-mcmf(s0,t).second);
}


int main() {


    solve();
}


template<typename cost_t>
void mincost<cost_t>::add_edge(int a, int b, int c, int d) {
    g[a].emplace_back(b, c, +d, g[b].size() - 0);
    g[b].emplace_back(a, 0, -d, g[a].size() - 1);
}

template<typename cost_t>
bool mincost<cost_t>::spfa(int s, int t, int &f, cost_t &c) {
    for (int i = 0; i < g.size(); ++i) {
        d[i] = inf;
        p[i] = ed[i] = -1;
        inq[i] = false;
    }
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for (int i = 0; i < g[x].size(); ++i) {
            edge &e = g[x][i];
            if (e.cap > 0 && d[e.dest] > d[x] + e.w) {
                d[e.dest] = d[x] + e.w;
                p[e.dest] = x;
                ed[e.dest] = i;
                if (!inq[e.dest]) q.push(e.dest), inq[e.dest] = true;
            }
        }
    }
    if (d[t] == inf) return false;
    int dlt = inf;
    for (int x = t; x != s; x = p[x]) dlt = min(dlt, g[p[x]][ed[x]].cap);
    for (int x = t; x != s; x = p[x]) {
        edge &e = g[p[x]][ed[x]];
        e.cap -= dlt;
        g[e.dest][e.rev].cap += dlt;
    }
    f += dlt; c += d[t] * dlt;
    return true;
}

template<typename cost_t>
pair<int, int> mincost<cost_t>::operator()(int s, int t) {
    int f = 0;
    cost_t c = 0;
    while (spfa(s, t, f, c));
    return make_pair(f, c);
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}