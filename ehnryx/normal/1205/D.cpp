#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3+1;
vector<int> adj[N];

////////////////////////////////////////////////////////////////////////
// Centroid Decomposition -- O(nlog(n)) to build (UNTESTED)
// USAGE:
//  1. decompose(u); where u is some vertex in the tree
//  2. centroid tree stored as adjacency list in cent[]
//  3. centroid parents stored in cpar[]
//  4. centroid depth stored in cdepth[]
//  5. centroid subtree vertices stored in csub[] (nlogn memory)
//*!
namespace Centroid {
    vector<int> cent[N];
    int sz[N], cdepth[N], cpar[N];
    unordered_set<int> csub[N];

    int dfs(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p) {
                sz[u] += dfs(v, u);
            }
        }
        return sz[u];
    }

    int centroid(int u, int p) {
        for (int v : adj[u]) {
            if (cdepth[v] == -1 && sz[v] > sz[u]/2) {
                sz[u] -= sz[v];
                sz[v] += sz[u];
                return centroid(v, p);
            }
        }
        // at centroid
        cdepth[u] = cdepth[p] + 1;
        cpar[u] = p;
        if (p != -1) cent[p].push_back(u);
				csub[u].insert(u);
        for(int v : adj[u]) {
            if (cdepth[v] == -1) {
                int cv = centroid(v, u);
                //*! to save vertices in subtree
                for (int it : csub[cv]) {
                    csub[u].insert(it);
                }
                //*/
            }
        }
        return u;
    }

    int decompose(int u) {
        memset(cdepth, -1, sizeof cdepth);
        dfs(u, -1);
        return centroid(u, -1);
    }
}
//*/

struct Edge {
	int a, b, c;
};

vector<Edge> edges;

int dfs(int u, int p, int k) {
	int cnt = 1;
	int c = k;
	for(int v:adj[u]) {
		if(v!=p) {
			edges.push_back({u,v,c});
			int sz = dfs(v,u,k);
			cnt += sz;
			c += sz*k;
		}
	}
	return cnt;
}

void solve(int u, const unordered_set<int>& ch, int k) {
	int c = k;
	for(int v:adj[u]) {
		if(ch.count(v)) {
			edges.push_back({u,v,c});
			c += k*dfs(v,u,k);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin>>n;
	for(int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int c = Centroid::decompose(1);
	//cerr<<"Centroid: "<<c<<nl;

	vector<pii> subs;
	for(int i:Centroid::cent[c]) {
		subs.push_back(pii(Centroid::csub[i].size(),i));
		//cerr<<"sub "<<i<<": "; for(int j:Centroid::csub[i]) cerr<<j<<" ";
		//cerr<<nl;
	}
	sort(subs.begin(),subs.end(),greater<pii>());

	unordered_set<int> ch[2];
	for(pii it:subs) {
		int i = (ch[0].size()<ch[1].size() ? 0 : 1);
		for(int j:Centroid::csub[it.second]) {
			ch[i].insert(j);
		}
	}

//#define DEBUG
#ifdef DEBUG
	cerr<<nl;
	for(int i=0;i<2;i++) {
		cerr<<"group "<<i<<" w/ size "<<ch[i].size()<<nl;
		for(int j:ch[i]) cerr<<j<<" ";
		cerr<<nl;
	}
	cerr<<nl;
	cerr<<"Compare "<<(ch[0].size()+1)*(ch[1].size()+1)-1<<" vs goal "<<2*n*n/9<<nl;
	cerr<<nl;
#endif

	solve(c,ch[0],1);
	solve(c,ch[1],ch[0].size()+1);

	for(Edge e:edges) {
		printf("%d %d %d\n",e.a,e.b,e.c);
	}

	return 0;
}