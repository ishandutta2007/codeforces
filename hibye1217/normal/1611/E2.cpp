#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define bcnt(x) __builtin_popcount(x)
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const ld eps = 1e-12;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};



// #define DEBUG

vector<int> adj[200020];
vector<int> v;
int dis[200020], dep[200020];
int bef[200020];
bool chk[200020];

void dfs(int now, int par, int dpf){
	dep[now] = dpf; bef[now] = par;
	for (int nxt : adj[now]){
		if (nxt == par){ continue; }
		dfs(nxt, now, dpf+1);
	}
}

void Main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		queue<pi2> q;
		for (int i = 1; i <= k; i++){
			int x; cin >> x; v.push_back(x);
			q.push({x, 1}); dis[x] = 1;
		}
		for (int i = 1; i < n; i++){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		while (!q.empty()){
			int now = q.front().fr, dst = q.front().sc;
			q.pop();
			for (int nxt : adj[now]){
				if (dis[nxt] != 0){ continue; }
				q.push({nxt, dst+1}); dis[nxt] = dst+1;
			}
		}
		dfs(1, -1, 1);
		bool flg = 1;
		int ans = 0;
		for (int i = 2; i <= n; i++){
			if (adj[i].size() != 1){ continue; }
			if (dis[i] > dep[i]){ cout << -1 << endl; goto next; }
		}
		sort(all(v), [](int i1, int i2){ return dep[i1] < dep[i2]; });
		for (int p : v){
			//cout << p << ' ';
			int ptr = p, dpf = 1;
			bool flg = 1;
			while (ptr != -1){
				if (chk[ptr]){ flg = 0; break; }
				if (dep[ptr] >= dpf){ chk[ptr] = 1; }
				dpf += 1; ptr = bef[ptr];
			}
			if (!flg){
				while (ptr != -1){
					if (chk[ptr]){ break; }
					chk[ptr] = 1;
				}
			}
			ans += flg;
			//cout << flg << endl;
		}
		cout << ans << endl;
		next: v.clear();
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			dis[i] = dep[i] = bef[i] = 0;
			chk[i] = 0;
		}
	}
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