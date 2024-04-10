#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

typedef pair<char, int> pci;
vector<pi2> adj[200020];
int dir[200020];
pci ans[200020];
vector<int> dag[200020]; int cnt[200020];

vector<int> vtx;
void dfs(int now, int d){
	dir[now] = d; vtx.push_back(now);
	for (pi2 p : adj[now]){
		int nxt = p.fr;
		if (dir[nxt]){ continue; }
		dfs(nxt, -d);
	}
}

void Main(){
	int n, m; cin >> n >> m;
	while (m--){
		int a, b, t; cin >> t >> a >> b;
		adj[a].push_back({b, t});
		adj[b].push_back({a, t});
	}
	int pos = 1;
	for (int i = 1; i <= n; i++){
		if (dir[i]){ continue; }
		dfs(i, 1);
		for (int v : vtx){
			for (pi2 p : adj[v]){
				int w = p.fr;
				if (dir[v] == dir[w]){ cout << "NO"; return; }
				if (dir[v] > dir[w]){ continue; }
				if (p.sc == 1){ dag[v].push_back(w); cnt[w] += 1; }
				else{ dag[w].push_back(v); cnt[v] += 1; }
			}
		}
		queue<int> q;
		for (int v : vtx){ if (cnt[v] == 0){ q.push(v); } }
		int vl = vtx.size();
		for (int i = 1; i <= vl; i++){
			if (q.empty()){ cout << "NO"; return; }
			int v = q.front(); q.pop();
			ans[v] = { (dir[v] == -1 ? 'L' : 'R'), pos }; pos += 1;
			for (int w : dag[v]){
				cnt[w] -= 1;
				if (cnt[w] == 0){ q.push(w); }
			}
		}
		vtx.clear();
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++){ cout << ans[i].fr << ' ' << ans[i].sc << endl; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}