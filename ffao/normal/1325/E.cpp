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

template<class T> void re(std::vector<T>& a);

void pr(int x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n;
vector<int> g[1100000];
vector<int> pl;
vector<pii> adj;
int p[1100000];
int dist[1100000];
int par[1100000];
const int MAXP = 1000000;

int go(int x) {
    rep(i,0,sz(pl)) dist[i] = 1000000000;
    
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    par[x] = -1;
    int ans = 1000000000;

    while (!q.empty()) {
        int curv = q.front();
        q.pop();

        for (int c : g[curv]) if (c != par[curv]) {
            if (dist[c] > dist[curv]+1) {
                dist[c] = dist[curv]+1;
                par[c] = curv;
                q.push(c);
            }
            else {
                ans = min(ans, dist[curv] + dist[c] + 1);
            }
        }
    }

    return ans;
}

void solve()
{
    for (int i = 2; i*i <= MAXP; i++) if (!p[i]) {
        for (int j = i*i; j <= MAXP; j += i) p[j] = i;
    }

    pl.push_back(1);
    re(n);
    vi a(n); re(a);

    rep(i,0,n) {
        vector<int> pi;
        while (a[i] != 1) {
            int curp = p[a[i]];
            if (curp == 0) curp = a[i];
            int cnt = 0;
            while (a[i] % curp == 0) {
                a[i] /= curp;
                cnt++;
            }
            if (cnt % 2) {
                pi.push_back(curp);
                pl.push_back(curp);
            }
        }

        if (pi.empty()) {
            ps(1);
            return;
        }

        if (sz(pi) == 1) pi.push_back(1);
        adj.push_back({min(pi[0], pi[1]), max(pi[0], pi[1])});
    }

    sort(all(adj));
    rep(i,0,sz(adj)-1) if (adj[i]==adj[i+1]) {
        ps(2);
        return;
    }

    sort(all(pl));
    pl.erase(unique(all(pl)), pl.end());
    trav(x,adj) {
        x.first = lower_bound(all(pl),x.first) - pl.begin();
        x.second = lower_bound(all(pl),x.second) - pl.begin();
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }

    int ans = 1000000000;
    rep(i,0,sz(pl)) {
        if (pl[i]*1ll*pl[i] > MAXP) break;
        ans = min(ans, go(i));
    }

    ps(ans == 1000000000 ? -1 : ans);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}