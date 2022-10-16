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

void pr(int x);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define sz(x) (int)(x).size()

vector<pii> g[110000];
set< pair<int, long long> > s[110000];
vector<int> trains[110000];
int n,m;

long long dst[110000];
vector< pair<long long, long long> > changes;

void dfs(int x) {
    int big = -1;
    int to = -1;
    for (auto p: g[x]) {
        int v = p.first;
        dst[v] = dst[x] + p.second;
        to = v;
        dfs(v);
        if (big == -1 || sz(s[v]) > sz(s[big])) big = v;
    }
    
    swap(s[x], s[big]);

    set< pair<int, long long> > rejects;
    for (auto p : g[x]) if (p.first != big) {
        int v = p.first;
        for (auto p2 : s[v]) rejects.insert( {p2.first, x * 1ll * n + v} );
    }

    for (auto it = rejects.begin(); it != rejects.end(); it++) {
        auto p = *it;
        auto nxt = s[x].lower_bound(p);

        if (nxt != s[x].begin()) {
            auto prv = prev(nxt);
            if (prv->second != p.second) changes.push_back({prv->first + dst[x] + 1, p.first + dst[x]});
        }
        else {
            if (p.second % n != to) changes.push_back({1, p.first + dst[x]});
        }

        if (nxt != s[x].end()) {
            if (next(it) == rejects.end() || nxt->first < next(it)->first) {
                changes.push_back({p.first + dst[x] + 1, nxt->first + dst[x]});
            }
        }

        s[x].insert(p);
    }

    if (!s[x].empty() && s[x].begin()->second / n != x) {
        if (big != to) changes.push_back({1, s[x].begin()->first + dst[x]});
    }

    for (int t : trains[x]) s[x].insert({t, x * 1ll * n + x});
}

void solve()
{
    re(n,m);

    for (int i = 0; i < n-1; i++) {
        int u,v,d;
        re(u,v,d); u--; v--;
        g[u].push_back({v,d});
    }

    for (int i = 0; i < m; i++) {
        int s, t; re(s,t); s--;
        trains[s].push_back(t);
    }

    dfs(0);
    sort(changes.begin(),changes.end());

    multiset<long long> ends;
    long long na = 1;
    int at = 0;
    int changed = 0;

    for (int i = 0; i < sz(changes); i++) {
        if (ends.empty()) na = changes[at].first;
        while (at < sz(changes) && changes[at].first == na) ends.insert(changes[at++].second);

        ends.erase(ends.begin());
        if (!ends.empty() && *ends.begin() == na) {
            break;
        }

        na++;
        changed++;
    }

    if (changed == sz(changes)) ps(-1, sz(changes));
    else {
        int ans = 0;
        for (auto change : changes) if (change.second < na) ans++;
        ps(na, ans);
    }
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}