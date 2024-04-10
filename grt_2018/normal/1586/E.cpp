#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10;
int n, m, q;
vi V[nax], T[nax];
vector<pi> G[nax];
int I[nax];
bool vis[nax], done[nax];
pi ed[nax];
vi ans[nax];

void dfs(int x) {
	done[x] = true;
	for(auto nbh : V[x]) if(!done[nbh]) {
		T[x].PB(nbh);
		T[nbh].PB(x);
		dfs(nbh);
	}
}

vi pth, w;

void dfs2(int a, int b) {
	done[a] = true;
	pth.PB(a);
	if(a == b) {
		w = pth;
	}
	for(auto nbh : T[a]) if(!done[nbh]) {
		dfs2(nbh, b);
	}
	pth.pop_back();
}

vi getpth(int a, int b) {	
	for(int i = 1; i <=	n; ++i) {
		done[i] = false;
	}
	dfs2(a, b);
	return w;
}

vi cycle;

void euler(int x) {
	while(I[x] < (int)G[x].size()) {
		auto nbh = G[x][I[x]++];
		if(vis[nbh.ND]) continue;
		vis[nbh.ND] = true;
		euler(nbh.ST);
		cycle.PB(nbh.ND);
	}
}

int main() {_
	cin >> n >> m;
	for(int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	cin >> q;
	for(int a, b, i = 0; i < q; ++i) {
		cin >> a >> b;
		ed[i] = {a, b};
		G[a].PB({b, i});
		G[b].PB({a, i});
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		if((int)G[i].size() & 1) {
			cnt++;
		}
	}
	if(cnt > 0) {
		cout << "NO\n";
		cout << cnt / 2;
		return 0;
	}
	dfs(1);
	cout << "YES\n";
	for(int i = 1; i <= n; ++i) {
		if(I[i] < (int)G[i].size()) {
			cycle.clear();
			euler(i);
			for(int j = 0; j < (int)cycle.size(); ++j) {
				//cerr << "J : " << j << "\n";
				//cerr << cycle[j] << "\n";
				ans[cycle[j]] = getpth(ed[cycle[j]].ST, ed[cycle[j]].ND);
			}
		}
	}
	//cerr << ":::\n";
	for(int i = 0; i < q; ++i) {
		cout << (int)ans[i].size() << "\n";
		for(int x : ans[i]) cout << x << " ";
		cout << "\n";
	}
}