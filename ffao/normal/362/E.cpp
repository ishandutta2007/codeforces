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


using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(long long x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

void pr() {}
void pr(int x) { printf("%d", x); }
void pr(long long x) { printf("%lld", x); }
void pr(double x) { printf("%.15f", x); }
void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }
void pr(std::string x) { printf("%s", x.c_str()); }
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

void pc() { pr("]\n"); }
template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
}

#define dbg(x...) pr("[",#x,"] = ["), pc(x);

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, f;
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, int rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, 0});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, 0});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c - e.f))) {
					e.f += p, adj[e.to][e.rev].f -= p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		REP(L,31) do {
			lvl = ptr = vi(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (auto& e : adj[v])
					if (!lvl[e.to] && (e.c - e.f) >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
};

int n, k;
int c[51][51];
int exists[51][51];

void solve()
{
    re(n,k);
    Dinic flow(n);

    REP(i,n) REP(j,n) {
        re(c[i][j]);
        exists[i][j] = !!c[i][j];
        if (c[i][j]) flow.addEdge(i, j, c[i][j]);
    }

    long long ans = flow.calc(0, n-1);

    while (k) {
        vector<int> dist(n, 1000000000);
        vector< pair<Dinic::Edge*, int> > fr(n);
        set< pii > q;
        dist[0] = 0;
        REP(i,n) q.insert({dist[i], i});

        while (!q.empty()) {
            int v = q.begin()->second;
            if (v == n-1) break;
            q.erase(q.begin());

            for (auto &e : flow.adj[v]) if (exists[v][e.to]) {
                int nd = dist[v] + (e.f >= e.c);
                if (nd < dist[e.to]) {
                    q.erase({dist[e.to], e.to});
                    dist[e.to] = nd;
                    fr[e.to] = {&e, v};
                    q.insert({dist[e.to], e.to});
                }
            }
        }
        
        //dbg(dist[n-1]);
        if (dist[n-1] > k) break;
        k -= dist[n-1];
        ans++;

        int cur = n-1;
        while (cur) {
            //dbg(cur);
            fr[cur].first->f++; 
            cur = fr[cur].second;
        }
        
    }

    ps(ans);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}