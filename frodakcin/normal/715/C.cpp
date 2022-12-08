#include <iostream>
#include <cstdio>

#include <ctime>
#include <iomanip>

#include <vector>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

struct EDGE {public: int to, d; EDGE(const int& a = -1, const int& b = -1) {to = a, d = b;}};
typedef vector<EDGE> ve;
#define pb push_back
typedef map<int, int> mapii;
#define IT iterator
#define CIT const_iterator

const int MAXN = 1e5 + 100;

const int tot(int n) {
    int r = tll(n);
    for(int i = 2;i * i <= n;i++) {
        if(n%i == 0) {
            n /= i;
            while(n%i == 0) n /= i;
            r = (r/i) * (i - 1);
        }
    }
    if(n > 1) {
        r = (r/n) * (n - 1);
    }
    return r;
}

int N, M;
int Mtot;

int sum(const int& a, const int& b) {
    return ti((tll(a) + tll(b))%M);
}
int prod(const int& a, const int& b) {
    return ti((tll(a) * tll(b))%M);
}
int dif(const int& a, const int& b) {
    return ti((tll(a) - tll(b) + tll(M) * 100)%M);
}
int pow(int b, int p) {
    assert(p >= 0);
    if(p == 0) return 1;
    if(p == 1) return b%M;
    int r = pow(b, p/2);
    r = prod(r, r);
    if(p&1) r = prod(r, b);
    return r;
}
int p10[MAXN];
int p10D[MAXN];
int divp10(const int& d, const int& p) {
    return prod(d, p10D[p]);
}

ll ans;
ve adj[MAXN];

int s[MAXN];
bool r[MAXN];

int dfs_size(const int& n, const int& p = -1) {
    s[n] = 1;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].to == p or r[adj[n][i].to]) continue;
        s[n] += dfs_size(adj[n][i].to, n);
    }
    return s[n];
}
int get_centroid(const int& n, const int& ms, const int& p = -1) {
    assert(s[n] * 2 >= ms);
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].to == p or r[adj[n][i].to]) continue;
        if(s[adj[n][i].to] * 2 > ms) return get_centroid(adj[n][i].to, ms, n);
    }
    return n;
}
int get_centroid(const int& n) {
    return get_centroid(n, dfs_size(n));
}

void inc(mapii& dat, int k) {
    if(dat.find(k) != dat.end()) dat[k]++;
    else dat[k] = 1;
}
int mapget(const mapii& dat, const int& k) {
    mapii::CIT it = dat.find(k);
    if(it == dat.end()) return 0;
    return it->second;
}

void dfs1(ll& ans, mapii& dat, mapii& datb, const int& m, const int& dist, const int& n, const int& p = -1) {
    int v = divp10(dif(0, m), dist);
    inc(dat, v);
    inc(datb, v);
    if(v == 0) ans++;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].to == p or r[adj[n][i].to]) continue;
        dfs1(ans, dat, datb, sum(prod(10, m), adj[n][i].d), dist + 1, adj[n][i].to, n);
    }
}
void dfs2(ll& ans, const mapii& dat, const mapii& datb, const int& m, const int& dist, const int& n, const int& p = -1) {
    ans += mapget(dat, m) - mapget(datb, m);
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].to == p or r[adj[n][i].to]) continue;
        dfs2(ans, dat, datb, sum(m, prod(adj[n][i].d, p10[dist])), dist + 1, adj[n][i].to, n);
    }
}
mapii cnt;
mapii cntb[MAXN];
void solve(ll& ans, const int& n) {
    cnt.clear();
    inc(cnt, 0);
    for(int i = 0;i < adj[n].size();i++) {
        if(r[adj[n][i].to]) continue;
        dfs1(ans, cnt, cntb[i], adj[n][i].d%M, 1, adj[n][i].to, n);
    }
    for(int i = 0;i < adj[n].size();i++) {
        if(r[adj[n][i].to]) continue;
        dfs2(ans, cnt, cntb[i], adj[n][i].d%M, 1, adj[n][i].to, n);
        cntb[i].clear();
    }
}

void work(ll& ans, const int& n) {
    int c = get_centroid(n);
    solve(ans, c);
    r[c] = true;
    for(int i = 0;i < adj[c].size();i++) if(!r[adj[c][i].to]) work(ans, adj[c][i].to);
}

int main() {
    clock_t timer = clock();
    cerr << setprecision(3);
    
    scanf("%d%d", &N, &M);
    Mtot = tot(M);
    
    p10[0] = 1;
    p10D[0] = 1;
    p10D[1] = pow(10, Mtot - 1);
    for(int i = 1;i <= N;i++) {
        p10[i] = prod(p10[i - 1], 10);
        p10D[i] = prod(p10D[i - 1], p10D[1]);
    }
    
    cerr << static_cast<double> (clock() - timer) / CLOCKS_PER_SEC << "\n";
    
    for(int i = 0, a, b, c;i < N - 1;i++) {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].pb(EDGE(b, c));
        adj[b].pb(EDGE(a, c));
    }
    
    for(int i = 0;i < N;i++) r[i] = false;
    ans = 0;
    work(ans, 0);
    
    printf("%lld\n", ans);
    
    cerr << static_cast<double> (clock() - timer) / CLOCKS_PER_SEC << "\n";
    
    return 0;
}