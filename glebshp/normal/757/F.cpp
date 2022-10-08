#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 500 * 1000 + 100;
const int ssize = 20;
const long long inf = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;

long long dist[size];
int par[ssize][size];
vector <pair <int, int> > vertex[size];
vector <int> children[size];
int subsz[size];
int depth[size];
int n, s, m;

int liftup(int v, int d) {
	for (int i = ssize - 1; i >= 0; i--) {
		if (depth[par[i][v]] >= d) {
			v = par[i][v];
		}
	}

	return v;
}

int getlca(int v, int u) {
	if (depth[v] > depth[u])
		swap(v, u);
	u = liftup(u, depth[v]);
	if (u == v)
		return u;
	for (int i = ssize - 1; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	} 

	return par[0][u];
}

void dfs(int v) {
	subsz[v] = 1;
	for (auto& u : children[v]) {
		dfs(u);
		subsz[v] += subsz[u];
	}
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &s);
    s--;
    for (int i = 0; i < m; i++) {
    	int u, v, w;
    	scanf("%d%d%d", &u, &v, &w);
    	u--, v--;

    	vertex[v].pb(mp(u, w));
    	vertex[u].pb(mp(v, w));
    }

    for (int i = 0; i < n; i++)
    	dist[i] = inf;
    set <pair <long long, int> > q;
    dist[s] = 0;

    for (int i = 0; i < n; i++)
    	q.insert(mp(dist[i], i));
    while (!q.empty()) {
    	int cur = q.begin()->sc;
    	q.erase(q.begin());
    	if (cur == s) {
    		par[0][cur] = s;
    	} else {
    		int lca = -1;
    		for (auto& v : vertex[cur]) {
    			if (dist[v.fs] == dist[cur] - v.sc) {
					if (lca == -1) {
						lca = v.fs;
					} else {
						lca = getlca(lca, v.fs);
					}
    			}
    		}
    		par[0][cur] = lca;
    	}
//    	cerr << cur << ' ' << par[0][cur] << ' ' << dist[cur] << ' ' << dist[par[0][cur]] << endl;
    	if (cur == s)
    		depth[cur] = 0;
    	else
	    	depth[cur] = depth[par[0][cur]] + 1;	
    	for (int i = 1; i < ssize; i++) {
    		par[i][cur] = par[i - 1][par[i - 1][cur]];
    	}
    	if (cur != s) {
    		children[par[0][cur]].pb(cur);
    	}

//    	cerr << "size " << cur << ' ' << vertex[cur].size() << endl;
    	for (auto& v : vertex[cur]) {
    		if (dist[v.fs] > dist[cur] + v.sc) {
    			q.erase(mp(dist[v.fs], v.fs));
    			dist[v.fs] = dist[cur] + v.sc;
  				q.insert(mp(dist[v.fs], v.fs));
  //  			cerr << "push " << cur << ' ' << v << endl;
    		}
    	}
    }

    dfs(s);
    int ans = 0;
    for (int i = 0; i < n; i++)
    	if (i != s)
    		ans = max(ans, subsz[i]);

    cout << ans << endl;

    return 0;
}