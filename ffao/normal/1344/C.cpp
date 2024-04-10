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

void pr(char x);
void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int n,m;

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority queue for lexic. smallest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
	while (!q.empty()) {
		int i = -q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(-x);
	}
	return ret;
}

void solve()
{
    re(n,m);
    vector<vi> g(n), rg(n);
    vi fwd(n, n+10), bck(n, n+10);

    for (int i = 0; i < m; i++) {
        int u,v; re(u, v); u--; v--;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    vi l = topoSort(g);
    if (sz(l) < n) {
        ps(-1);
        return;
    }

    for (int x : l) {
        bck[x] = x;
        for (int k : rg[x]) bck[x] = min(bck[x], bck[k]);
    }

    reverse(all(l));
    for (int x : l) {
        fwd[x] = x;
        for (int k : g[x]) fwd[x] = min(fwd[x], fwd[k]);
    }

    int ans = 0;
    for (int x = 0; x < n; x++) if (fwd[x] == x && bck[x] == x) ans++;
    ps(ans);
    for (int x = 0; x < n; x++) {
        if (fwd[x] == x && bck[x] == x) pr('A');
        else pr('E');
    }
    ps();
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(int x) { printf("%d", x); }

void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}