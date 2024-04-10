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

const int N = 1e5+1;
map<pii,int> tri[N];
map<pii,vector<pii>> inc;
vector<tuple<int,pii,int>> adj[N];
vector<int> verts[N];

void solve(int u, int p, list<int>& ans, vector<list<int>::iterator> t) {
	assert(t.size() == 3);
	//cerr<<"@ "<<u<<" w/ "<<*t[0]<<" "<<*t[1]<<" "<<*t[2]<<" from "<<p<<nl;
	for(const auto& [v,e,o] :adj[u]) {
		if(v == p) continue;
		for(int i=0; i<3; i++) {
			if(*t[i] != e.first && *t[i] != e.second) {
				int j = (i+2) % 3;
				vector<list<int>::iterator> nxt = t;
				nxt[i] = ans.insert(t[j], o);
				swap(nxt[i], nxt[j]);
				solve(v, u, ans, nxt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		inc.clear();
		for(int i=1; i<=n; i++) {
			tri[i].clear();
			adj[i].clear();
		}
		for(int i=1; i<n-1; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vector<int> v = { a, b, c };
			sort(v.begin(), v.end());
			tri[v[0]][make_pair(v[1], v[2])] = i;
			tri[v[1]][make_pair(v[0], v[2])] = i;
			tri[v[2]][make_pair(v[0], v[1])] = i;
			inc[make_pair(v[1], v[2])].push_back(make_pair(i, v[0]));
			inc[make_pair(v[0], v[2])].push_back(make_pair(i, v[1]));
			inc[make_pair(v[0], v[1])].push_back(make_pair(i, v[2]));
			verts[i] = move(v);
		}

		queue<int> leaf;
		for(int i=1; i<=n; i++) {
			if(tri[i].size() == 1) {
				leaf.push(i);
			}
		}
		vector<int> rem_order;
		while(!leaf.empty()) {
			int u = leaf.front();
			leaf.pop();
			if(tri[u].empty()) continue;
			for(const auto& [v,i] : tri[u]) {
				const auto& [a,b] = v;
				rem_order.push_back(i);
				tri[a].erase(make_pair(min(u,b), max(u,b)));
				tri[b].erase(make_pair(min(u,a), max(u,a)));
				if(tri[a].size() == 1) {
					leaf.push(a);
				}
				if(tri[b].size() == 1) {
					leaf.push(b);
				}
			}
		}

		for(const auto& [e,v] : inc) {
			if(v.size() > 1) {
				assert(v.size() == 2);
				adj[v[0].first].push_back(make_tuple(v[1].first, e, v[1].second));
				adj[v[1].first].push_back(make_tuple(v[0].first, e, v[0].second));
			}
		}
		list<int> ans;
		for(int v : verts[1]) {
			ans.push_back(v);
		}
		list<int>::iterator s = ans.begin();
		solve(1, 0, ans, { s, next(s), next(next(s)) });

		for(int it : ans) {
			cout << it << " ";
		}
		cout << nl;
		for(int it : rem_order) {
			cout << it << " ";
		}
		cout << nl;
	}

	return 0;
}