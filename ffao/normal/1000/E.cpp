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


class Biconnected
{
	int intime;
	int cc;
	std::vector<int> vis;

public:
	std::vector< std::pair<int, int> > bridges;
	std::vector<int> comp;
	UnionFind dsu;
	Biconnected(const std::vector<int>* G, int n);
	int biponte(const std::vector<int>* G, int v, int pai);
};


using namespace std;


typedef vector<int> vi;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


vi G[310000];
vi Gb[310000];
int seen[310000];
int n, m;
int d, dist;

void dfs(int i, Biconnected& bc, int cur) {
    if (cur > dist) {
        dist = cur;
        d = i;
    }

    seen[i] = 1;
    for (int x : Gb[i]) {
        if (!seen[x]) dfs(x, bc, cur+1);
    }
}

void solve()
{
    re(n,m);
    REP(i,m) {
        int a, b;
        re(a,b); a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Biconnected biconn(G, n);

    for (int i = 0; i < n; i++) for (int v : G[i]) {
        int a = biconn.dsu.find(i);
        int x = biconn.dsu.find(v);
        if (x != a) Gb[a].push_back(x); 
    }

    for (int i = 0; i < n; i++) if (biconn.dsu.find(i) == i) {
        d = -1; dist = -1;
        memset(seen,0,sizeof(seen));
        dfs(i,biconn,0);
        
        int d1 = d;

        d = -1; dist = -1;
        memset(seen,0,sizeof(seen));
        dfs(d1,biconn,0);

        break;
    }

    ps(dist);
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


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}


int Biconnected::biponte(const std::vector<int>* G, int v, int pai){
	if (vis[v]) return vis[v];
	comp[v] = cc;
	int R = vis[v] = intime++;
	bool ignored_back_edge = false;
	for (int a : G[v]) {
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

Biconnected::Biconnected(const std::vector<int>* G, int n) : dsu(n) {
	vis = std::vector<int>(n, 0);
	comp = std::vector<int>(n, 0);
	intime = 1;
	cc = 0;
	for (int i = 0; i<n; i++) if (!vis[i]) {
		biponte(G, i, -1);
		cc++;
	}
	vis.clear();
}