#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long LL;

bool dfs(int a, int layer, const vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if ( btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(const vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), -1);
		
		cur.clear();
		trav(a,btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		for (int lay = 1;; lay += 2) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if(islast) break;
			if(next.empty()) return res;
			trav(a, next) A[a] = lay + 1;
			cur.swap(next);
		}
		
		rep(a,0,sz(g)) {
			if(dfs(a, 0, g, btoa, A, B))
				++res;
		}
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> deg(n, 0);
		vector<pair<int,int> > s(m);
		vector<vector<int> > r(n);
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			a--; b--;
			s[i] = {a,b};
			deg[a]++;
			deg[b]++;
			r[a].push_back(i);
			r[b].push_back(i);
		}
		vector<vector<int> > g;
		for(int i = 0; i < n; i++){
			for(int q = 0; q < deg[i] - k; q++){
				g.push_back(r[i]);
				g.push_back(r[i]);
			}
		}
		vector<int> btoa(m, -1);
		if(hopcroftKarp(g, btoa) < g.size()){
			for(int i = 0; i < m; i++){
				cout << 0 << " ";
			}
			cout << '\n';
		} else {
			int z = 100000;
			for(int i = 0; i < m; i++){
				if(btoa[i] == -1){
					btoa[i] = z - i;
				} else {
					btoa[i] /= 2;
				}
			}
			for(int i = 0; i < m; i++){
				cout << btoa[i] + 1 << " ";
			}
			cout << '\n';
		}
	}
}