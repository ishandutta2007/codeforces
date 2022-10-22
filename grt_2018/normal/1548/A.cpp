#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back

using namespace std;
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n, m;
set<int>V[nax];
bool good[nax];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		V[a].insert(b);
		V[b].insert(a);
	}
	for(int i = 1; i <= n; ++i) {
		if(V[i].size() == 0) {
			good[i] = true;
		} else {
			auto it = V[i].end();
			it--;
			if((*it) < i) {
				good[i] = true;
			}
		}
		ans += good[i];
	}
	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int u, v;
			cin >> u >> v;
			V[u].insert(v);
			V[v].insert(u);
			ans -= good[u];
			good[u] = false;
			if(V[u].size() == 0) {
				good[u] = true;
			} else {
				auto it = V[u].end();
				it--;
				if((*it) < u) {
					good[u] = true;
				}
			}
			ans += good[u];
			ans -= good[v];
			good[v] = false;
			if(V[v].size() == 0) {
				good[v] = true;
			} else {
				auto it = V[v].end();
				it--;
				if((*it) < v) {
					good[v] = true;
				}
			}
			ans += good[v];
		} else if(t == 2) {
			int u, v;
			cin >> u >> v;
			V[u].erase(v);
			V[v].erase(u);
			ans -= good[u];
			good[u] = false;
			if(V[u].size() == 0) {
				good[u] = true;
			} else {
				auto it = V[u].end();
				it--;
				if((*it) < u) {
					good[u] = true;
				}
			}
			ans += good[u];
			ans -= good[v];
			good[v] = false;
			if(V[v].size() == 0) {
				good[v] = true;
			} else {
				auto it = V[v].end();
				it--;
				if((*it) < v) {
					good[v] = true;
				}
			}
			ans += good[v];
		} else {
			cout << ans << "\n";
		}
	}
}