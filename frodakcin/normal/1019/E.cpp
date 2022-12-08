#include <iostream>
#include <cstdio>

#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

const ll INF = 1e16;
const ll MAXM = 1e6 + 1000;
const int MAXN = 1e5 + 100;

ll divF(ll n, ll d) {
    assert(d != 0);
    if(d < 0) n *= -1, d *= -1;
    if(n < 0) return -((-n + d - 1)/d);
    return n/d;
}

bool Q;
struct LINE {
    ll m, b;
    mutable ll r;
    LINE(const ll& a, const ll& c) {m = a, b = c;r = -1;}
    LINE(const ll& v) {r = v; m = b = -1;}
    LINE operator + (const LINE& o) const {return LINE(m + o.m, b + o.b);}
    ll operator * (const LINE& o) const {
        if(m == o.m) return b > o.b ? INF : -INF;
        return 1LL + divF(o.b - b, m - o.m);
    }
    bool operator < (const LINE& o) const {
        if(Q) return r < o.r;
        return m != o.m ? m < o.m : b > o.b;
    }
    ll operator [] (const ll& x) const {return m * x + b;}
};
#define IT iterator
struct CHT : multiset<LINE> {
    bool upd(IT c, IT n) {
        if(n == end()) {c->r = INF; return false;}
        if((c->r = *c**n) >= n->r or c->r > MAXM) {return true;}
        return false;
    }
    void ins(const LINE& l) {
        IT n = insert(l), c = n++, p = c;
        while(upd(c, n)) n = erase(n);
        if(p != begin() and upd(--p, c)) upd(p, erase(c));
        while((c = p) != begin() and upd(--p, c)) upd(p, erase(c));
    }
    ll operator [] (const ll& x) {
        Q = true;
        IT t = lower_bound(LINE(x));
        Q = false;
        assert(t != end());
        return (*t)[x];
    }
    void operator += (const CHT& o) { for(LINE l : o) ins(l);}
} final;

int N, M;
struct EDG {int to, a, b;};
typedef vector<EDG> ve;
ve adj[MAXN];

void join(const CHT& a, const CHT& b) {
    CHT::IT it1 = a.begin(), it2 = b.begin();
    while(it1 != a.end() and it2 != b.end()) {
        final.ins(*it1+*it2);
        if(it1->r > it2->r) it2++; else it1++;
    }
}
void dq(vector<CHT>& a, const int& l, const int& r) {
    if(l + 1 == r) return;
    int m = l + ((r - l)>>1);
    dq(a, l, m), dq(a, m, r);
    join(a[l], a[m]);
    a[l]+=a[m];
}

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
    for(int i = 0;i < adj[n].size();i++) if(!r[adj[n][i].to] and adj[n][i].to != p and s[adj[n][i].to] * 2 > ms) return get_centroid(adj[n][i].to, ms, n);
    return n;
}
int get_centroid(const int& n) {return get_centroid(n, dfs_size(n));}
void dfs_sol(CHT& dat, const ll& a, const ll& b, const int& n, const int& p) {
    bool leaf = true;
    for(int i = 0;i < adj[n].size();i++) {
        if(adj[n][i].to == p) continue;
        leaf = false;
        if(r[adj[n][i].to]) continue;
        dfs_sol(dat, a + adj[n][i].a, b + adj[n][i].b, adj[n][i].to, n);
    }
    if(leaf) dat.ins(LINE(a, b));
}
void solve(const int& n) {
    int c = get_centroid(n);
    vector<CHT> l(0);
    for(int i = 0;i < adj[c].size();i++) {
        if(r[adj[c][i].to]) continue;
        l.push_back(CHT());
        dfs_sol(l.back(), tll(adj[c][i].a), tll(adj[c][i].b), adj[c][i].to, c);
        if(l.back().empty()) l.pop_back();
    }
    
    if(l.empty());
    else if(l.size() == 1) final += l[0];
    else dq(l, 0, l.size());
    
    r[c] = true;
    for(int i = 0;i < adj[c].size();i++) if(!r[adj[c][i].to]) solve(adj[c][i].to);
}
#define pb push_back
int main() {
    Q = false;
    
    scanf("%d%d", &N, &M);
    for(int i = 0, u, v, a, b;i < N - 1;i++) {
        scanf("%d%d%d%d", &u, &v, &a, &b);
        adj[u].pb({v, a, b});
        adj[v].pb({u, a, b});
    }
    final.ins(LINE(0, 0));
    solve(1);
    CHT::IT it = final.begin();
    //for(LINE l : final) printf("[f(x) = %lldx + %lld] up to %lld\n", l.m, l.b, l.r);
    for(int i = 0;i < M;i++) {
        while(i >= it->r) it++;
        printf("%lld ", (*it)[i]);
    }
    printf("\n");
    
    return 0;
}