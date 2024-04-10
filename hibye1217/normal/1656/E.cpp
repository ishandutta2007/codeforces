// After Editorial

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

vector<int> adj[100020];

int arr[100020];
void dfs(int now, int pre, int sgn){
	arr[now] = sgn;
	for (int nxt : adj[now]){
		if (nxt == pre){ continue; }
		dfs(nxt, now, -sgn);
	}
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i < n; i++){
			int v, w; cin >> v >> w;
			adj[v].push_back(w); adj[w].push_back(v);
		}
		dfs(1, -1, 1);
		for (int i = 1; i <= n; i++){ cout << (int)(adj[i].size())*arr[i] << ' '; } cout << endl;
		for (int i = 1; i <= n; i++){ adj[i].clear(); }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}