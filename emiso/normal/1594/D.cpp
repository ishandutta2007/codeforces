#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

struct union_find {
    vector<int> parent, rank_;
    union_find(int n) { init(n); }
    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1, 1);
        for(int i = 0; i <= n; i += 2) rank_[i] = 0;
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(a > b) swap(a, b);
        parent[b] = a;
        rank_[a] += rank_[b];
        return true;
    }
};

ll t = 1, n, m, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    union_find dsu(2*n+2);

    for(int i = 0, u, v; i < m; i++) {
        scanf("%d %d %s", &u, &v, s); str = s;
        if(s[0] == 'i') {
            dsu.join(2*u, 2*v+1);
            dsu.join(2*u+1, 2*v);
        } else if(s[0] == 'c') {
            dsu.join(2*u, 2*v);
            dsu.join(2*u+1, 2*v+1);
        } else assert(false);
    }

    int can = 1;
    for(int i = 1; can && i <= n; i++) {
        if(dsu.find(2*i) == dsu.find(2*i+1)) can = 0;
        else if(dsu.find(2*i) == 2*i) {
            ans += max(dsu.rank_[2*i], dsu.rank_[2*i+1]);
        }
    }

    if(!can) puts("-1");
    else printf("%lld\n", ans);

    if(--t) goto st;
    return 0;
}