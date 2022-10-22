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

typedef pair<pi2, int> pi3;

// #define DEBUG

vector<int> adj[100020];
vector<pi3> edg; map<pi2, int> mp;
bool chk[100020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i < n; i++){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			mp[{a, b}] = mp[{b, a}] = i-1;
			edg.push_back({ {a, b}, -1 });
		}
		int ptr = 0;
		bool flg = 0;
		for (int i = 1; i <= n; i++){
			if (adj[i].size() > 2){ cout << -1; goto done; }
			if (adj[i].size() == 1){ ptr = i; }
		}
		while (!chk[ptr]){
			chk[ptr] = 1;
			for (int nxt : adj[ptr]){
				if (!chk[nxt]){
					edg[ mp[{ptr, nxt}] ].sc = (flg ? 3 : 2);
					ptr = nxt; break;
				}
			}
			flg ^= 1;
		}
		for (pi3 p : edg){ cout << p.sc << ' '; }
		done: cout << endl;
		edg.clear(); mp.clear();
		for (int i = 1; i <= n; i++){
			adj[i].clear();
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