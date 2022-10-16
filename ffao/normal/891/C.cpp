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
template<class T> void re(std::vector<T>& a);

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

int n,m;
const int MOD = 1000000007;

struct DSUrb {
	vi e;
	void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } 
	
	vector<array<int,4>> mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) {
			mod.push_back({MOD,MOD,MOD,MOD});
			return 0;
		}
		if (e[x] > e[y]) swap(x,y);
		mod.push_back({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x;
		return 1;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		if (a[0] != MOD) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

struct edge {
    int u,v;
    int cost;
    bool operator< (const edge& ot) const {
        return cost < ot.cost;
    }
};

DSUrb dsu;
vector<int> queries_per_weight[510000];
vector<int> edges_in_query[510000];

void solve()
{
    re(n,m);
    dsu.init(n);
    
    vector< edge > edges(m);
    for (int i = 0; i < m; i++) {
        re(edges[i].u, edges[i].v, edges[i].cost);
        edges[i].u--; edges[i].v--;
    }

    vector< edge > sorted_edges = edges;
    sort(all(sorted_edges));

    int k; re(k);
    for (int cc = 0; cc < k; cc++) {
        int nk; re(nk);
        edges_in_query[cc].resize(nk);
        re(edges_in_query[cc]);
        for (int i = 0; i < nk; i++) edges_in_query[cc][i]--;

        sort(all(edges_in_query[cc]), [&](int a, int b) {return edges[a] < edges[b];});
        
        for (int i = 0; i < nk; i++) {
            if (i == 0 || edges[edges_in_query[cc][i]].cost != edges[edges_in_query[cc][i-1]].cost) {
                queries_per_weight[edges[edges_in_query[cc][i]].cost].push_back(cc);
            }
        }
    }

    vector<int> cur_idx(k);
    vector<bool> ok(k, true);
    int global_idx = 0;

    for (int w = 1; w <= 510000 && global_idx < m; w++) {
        if (sorted_edges[global_idx].cost != w) continue;

        for (int comp : queries_per_weight[w]) if(ok[comp]) {
            int cur = cur_idx[comp];
            while (cur < sz(edges_in_query[comp]) && edges[edges_in_query[comp][cur]].cost == w) {
                int x = dsu.get(edges[edges_in_query[comp][cur]].u);
                int y = dsu.get(edges[edges_in_query[comp][cur]].v);
                if (x == y) {
                    ok[comp] = false;
                    break;
                }
                dsu.unite(x,y);
                cur++;
            }

            while (cur_idx[comp] < cur) {
                dsu.rollback();
                cur_idx[comp]++;
            }
        }

        while (global_idx < m && sorted_edges[global_idx].cost == w) {
            dsu.unite(sorted_edges[global_idx].u, sorted_edges[global_idx].v);
            global_idx++;
        }
    }

    for (int i = 0; i < k; i++) ps(ok[i] ? "YES" : "NO");
}

int main() {

    solve();
}

void re(int& x) { scanf("%d", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}