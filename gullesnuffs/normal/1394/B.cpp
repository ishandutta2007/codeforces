#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
	
set<pair<pair<int, int>, pair<int, int>>> S;
int n, m, k;
int ans = 0;

void rec(vector<int> c) {
	if (sz(c) == k) {
		/*for (int x : c)
			cerr << x << " ";
		cerr << endl;*/
		++ans;
		return;
	}
	rep(i,0,sz(c)+1) {
		c.push_back(i);
		auto p1 = make_pair(i, sz(c));
		bool ok = true;
		rep(j,0,sz(c)) {
			auto p2 = make_pair(c[j], j+1);
			if (S.count(make_pair(p1, p2)))
				ok = false;
		}
		if (ok) {
			rec(c);
		}
		c.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> adj(n);
	rep(i,0,m) {
		int a, b, w;
		cin >> a >> b >> w;
		--a;--b;
		adj[a].emplace_back(w, b);
	}
	vector<set<pair<int, int>>> inadj(n);
	rep(i,0,n) {
		sort(all(adj[i]));
		rep(j,0,sz(adj[i])){
			int to = adj[i][j].second;
			auto p = make_pair(j, sz(adj[i]));
			if (inadj[to].count(p)) {
				S.insert(make_pair(p, p));
			}
			else {
				inadj[to].insert(p);
			}
		}
	}
	rep(i,0,n) {
		for (auto it = inadj[i].begin(); it != inadj[i].end(); ++it) {
			auto it2 = it;
			for (it2++; it2 != inadj[i].end(); ++it2) {
				S.insert(make_pair(*it, *it2));
				S.insert(make_pair(*it2, *it));
			}
		}
	}
	/*for (auto it : S) {
		cerr << it.first.first << " " << it.first.second << "  " << it.second.first << " " << it.second.second << endl;
	}*/
	rec(vector<int>());
	cout << ans << endl;
}