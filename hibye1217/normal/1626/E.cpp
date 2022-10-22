#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
#define bnt(x) __builtin_popcount(x)

//#define DEBUG

int bc = 0;
bool blk[300020]; int cnt[300020];
vector<int> adj[300020];
vector<int> gph[300020][2];

void dfs(int now, int par){
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs(nxt, now); cnt[now] += cnt[nxt];
	}
	if (blk[now]){ cnt[now] += 1; }
	if (now == par){ return; }
	int c1 = cnt[now], c2 = bc - cnt[now];
	if (c1 != 0){
		if (c1 == 1){ gph[now][0].push_back(par); }
		else{ gph[now][1].push_back(par); }
	}
	if (c2 != 0){
		if (c2 == 1){ gph[par][0].push_back(now); }
		else{ gph[par][1].push_back(now); }
	}
}

bool ans[300020];
void f(int now){
	ans[now] = 1;
	for (int nxt : gph[now][1]){
		if (ans[nxt]){ continue; }
		f(nxt);
	}
}

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x == 1){ blk[i] = 1; bc += 1; }
	}
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++){
		if (!blk[i]){ continue; }
		if (!ans[i]){ f(i); }
		for (int j : gph[i][0]){ if (!ans[j]){ f(j); } }
	}
	for (int i = 1; i <= n; i++){ cout << ans[i] << ' '; }
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}