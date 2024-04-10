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

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,w,h;

vector< pair<int, int> > grp[310000];
vector< pair<int, int> > grp2[310000];
int g[310000];

pair<int,int> ans[110000];

void solve()
{
    re(n,w,h);

    rep(i,0,n) {
        int pi, ti, gi; re(gi,pi,ti);

        g[i] = gi;
        int k = pi - ti + 100000;
        
        grp[k].push_back({pi, i});
        grp2[k].push_back({pi, i});
    }

    rep(i,0,310000) if (!grp[i].empty()) {
        sort(all(grp[i]), [](pii a, pii b) {
            if (g[a.second] != g[b.second]) return g[a.second] < g[b.second];
            if (g[a.second] == 1) return a.first > b.first;
            else return a.first < b.first;
        });

        sort(all(grp2[i]), [](pii a, pii b) {
            if (g[a.second] != g[b.second]) return g[a.second] > g[b.second];
            if (g[a.second] == 1) return a.first > b.first;
            else return a.first < b.first;
        });

        // dbg("group");
        rep(j,0,sz(grp[i])) {
            // dbg(grp[i][j].second, "from", grp2[i][j].second);
            if (g[grp2[i][j].second] == 2) ans[grp[i][j].second] = {w, grp2[i][j].first};
            else ans[grp[i][j].second] = {grp2[i][j].first, h};
        }
    }

    rep(i,0,n) ps(ans[i].first, ans[i].second);
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}