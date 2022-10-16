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

#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);
void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


class UnionFind
{
public:
	std::vector<int> parent;
	UnionFind(int n);
	int find(int x);
	void link(int a, int b);
};


using namespace std;


typedef pair<int, int> pii;


vector< pair<int, int> > g[1100];
vector< pair< pii, int> > edges;

int n,m;
int s,t;
int seen[1100];
vector<int> pa;

class Biconnected2
{
	int intime;
	int cc;
    int ig;
	std::vector<int> vis;

public:
	std::vector< std::pair<int, int> > bridges;
	std::vector<int> comp;
	UnionFind dsu;
	Biconnected2(const std::vector<pii>* G, int n, int _ig);
	int biponte(const std::vector<pii>* G, int v, int pai);
};

int Biconnected2::biponte(const std::vector<pii>* G, int v, int pai){
	if (vis[v]) return vis[v];
	comp[v] = cc;
	int R = vis[v] = intime++;
	bool ignored_back_edge = false;
	for (pii e : G[v]) if (e.second != ig) {
        int a = e.first;
		if (a == pai && !ignored_back_edge) {
			ignored_back_edge = true;
			continue;
		}
		int r = biponte(G, a, v);
		if (r < R){
			//dsu.link(v, a);
			R = r;
		}
	}
	if (R >= vis[v] && pai != -1) {
		bridges.push_back({ v, pai });
	}
	else if (pai != -1) {
		dsu.link(v, pai);
	}
	
	return R;
}

Biconnected2::Biconnected2(const std::vector<pii>* G, int n, int _ig) : dsu(n) {
	vis = std::vector<int>(n, 0);
	comp = std::vector<int>(n, 0);
    ig = _ig;
	intime = 1;
	cc = 0;
	for (int i = 0; i<n; i++) if (!vis[i]) {
		biponte(G, i, -1);
		cc++;
	}
	vis.clear();
}

bool dfs(int loc, int ig) {
    if (loc == t) return true;
    if (seen[loc]) return false;

    seen[loc]=1;
    for (pii e : g[loc]) if (e.second != ig) {
        int x = e.first;
        pa.push_back(e.second);
        if (dfs(x, ig)) return true;
        pa.pop_back();
    }

    return false;
}

void solve()
{
    re(n,m);
    re(s,t); s--; t--;

    for (int i = 0; i < m; i++) {
        int u,v,c; re(u,v,c); u--; v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
        edges.push_back( {{u,v}, c} );
    }

    pair<long long, pii> ans = {1000000000000000000LL, {-1,-1}};
    if (!dfs(s,-1)) {
        ps(0);
        ps(0);
        ps();
        return;
    }

    vector<int> chk = pa;

    for (int i : chk) {
        Biconnected2 biconn = Biconnected2(g,n,i);
        
        memset(seen,0,sizeof(seen));
        pa.clear();
        if (!dfs(s,i)) {
            ans = min(ans, {edges[i].second, {i,-1}});
        }
        else {
            int m = 1000000001;
            int bst = -1;
            for (int x : pa) {
                if (edges[x].second < m && biconn.dsu.find(edges[x].first.first) != biconn.dsu.find(edges[x].first.second)) {
                    m = edges[x].second;
                    bst = x;
                }
            }

            if (bst != -1) ans = min(ans, {edges[i].second + m, {i, bst}});
        }   
    }

    if (ans.second.first != -1) {
        ps(ans.first);
        if (ans.second.second != -1) {
            ps(2); 
            ps(ans.second.first+1, ans.second.second+1);
        }
        else {
            ps(1);
            ps(ans.second.first+1);
        }
    }
    else {
        ps(-1);
    }
}


int main() {


    solve();
}


UnionFind::UnionFind(int n)
{
	parent = std::vector<int>(n);
	for (int i = 0; i < n; i++) parent[i] = i;
}

int UnionFind::find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void UnionFind::link(int a, int b) {
	int x = find(a), y = find(b);
	parent[y] = x;
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