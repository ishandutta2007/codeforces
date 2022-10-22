#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
template <typename T> inline void read(T &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

struct Query {
	int t, a, b;
};

const int N = 2e5;
int dsu[N], sz[N];
int find(int i) {
	if(dsu[i]==-1) return i;
	return dsu[i] = find(dsu[i]);
}
void link(int i, int j) {
	i = find(i); j = find(j);
	if(i!=j) {
		if(sz[i] > sz[j]) swap(i,j);
		dsu[i] = j;
		sz[j] += sz[i] + 1;
	}
}

unordered_set<int> edges[N];
unordered_set<int> skip[N];
unordered_map<int,int> cur[N];
unordered_set<int> vis;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	//cin >> n >> m;
	read(n); read(m);

	vector<Query> queries;
	for(int i=0; i<m; i++) {
		int t, a, b;
		//cin >> t >> a >> b;
		read(t); read(a); read(b);
		queries.push_back({t, min(a,b)-1, max(a,b)-1});
	}

	const int S = 900;
	int last = 0;

	for(int i=0; i<m; i+=S) {
		for(int j=0; j<S && i+j<m; j++) {
			if(queries[i+j].t == 1) {
				int a = queries[i+j].a;
				int b = queries[i+j].b;
				skip[a].insert(b);
				a = (a+1)%n;
				b = (b+1)%n;
				if(a>b) swap(a,b);
				skip[a].insert(b);
			}
		}

		memset(dsu, -1, sizeof dsu);
		memset(sz, 0, sizeof sz);
		for(int u=0; u<n; u++) {
			cur[u].clear();
			for(int v:edges[u]) {
				if(!skip[u].count(v)) {
					link(u,v);
				}
			}
		}

		for(int u=0; u<n; u++) {
			for(int v:skip[u]) {
				if(edges[u].count(v)) {
					cur[find(u)][find(v)] += 1;
					cur[find(v)][find(u)] += 1;
				}
			}
			skip[u].clear();
		}

		for(int j=0; j<S && i+j<m; j++) {
			int a = (queries[i+j].a + last) % n;
			int b = (queries[i+j].b + last) % n;
			if(a>b) swap(a,b);
			//cerr<<"@ q "<<i+j<<" -> "<<queries[i+j].t<<" "<<a<<" "<<b<<nl;
			//cerr<<"graph is: "<<nl; for(int u=0; u<n; u++) {
			//cerr<<u<<": "; for(int v:edges[u]) { //cerr<<v<<" "; }
			//cerr<<nl; }
			//cerr<<nl;

			if(queries[i+j].t == 1) {
				if(edges[a].count(b)) {
					edges[a].erase(b);
					cur[find(a)][find(b)] -= 1;
					if(--cur[find(b)][find(a)] == 0) {
						cur[find(a)].erase(find(b));
						cur[find(b)].erase(find(a));
					}
				} else {
					edges[a].insert(b);
					cur[find(a)][find(b)] += 1;
					cur[find(b)][find(a)] += 1;
				}
			}

			else {
				int s = find(a);
				int t = find(b);
				if(s != t) {
					vis.clear();
					stack<int> dfs;
					dfs.push(s);
					vis.insert(s);
					while(!dfs.empty()) {
						s = dfs.top();
						dfs.pop();
						for(const auto& v:cur[s]) {
							if(v.first == t) {
								s = t;
								break;
							}
							if(!vis.count(v.first)) {
								vis.insert(v.first);
								dfs.push(v.first);
							}
						}
						if(s == t) break;
					}
				}
				last = (s == t);
				//cout << last;
				putchar(last ? '1' : '0');
			}
		}
	}

	//cout << nl;
	putchar(nl);

	return 0;
}