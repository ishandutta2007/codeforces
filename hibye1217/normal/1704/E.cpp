#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

const ll mod = 998244353;
vector<int> adj[1020]; int cnt[1020];
vector<int> vtx; ll pos[1020][1020];

void Main(){
	int t; cin >> t; while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++){
			cin >> pos[i][0];
			if (pos[i][0] > mod){ pos[i][0] -= mod; }
		}
		while (m--){
			int v, w; cin >> v >> w;
			adj[v].push_back(w); cnt[w] += 1;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++){ if (cnt[i] == 0){ q.push(i); } }
		for (int i = 1; i <= n; i++){
			int now = q.front(); q.pop(); vtx.push_back(now);
			for (int nxt : adj[now]){
				cnt[nxt] -= 1; if (cnt[nxt] == 0){ q.push(nxt); }
			}
		}
		for (int i : vtx){
			ll ptr = 0; int lst = 0;
			for (int now = 0; now <= n; now++){
				ll num = pos[i][now]; if (num == 0){ continue; }
				if (ptr < now){ lst = now; } int nxt = lst+1;
				//cout << "POS " << i << ' ' << now << " = " << num << " -> " << nxt << ' ' << ptr << endl << flush;
				for (int j : adj[i]){
					pos[j][nxt] += num;
					if (pos[j][nxt] > mod){ pos[j][nxt] -= mod; }
				}
				ptr = max(ptr, (ll)lst) + num;
				pos[i][now] = 0;
			}
			if (i == vtx[n-1]){ cout << ptr%mod << endl; }
		}
		for (int i = 1; i <= n; i++){ cnt[i] = 0; adj[i].clear(); } vtx.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}