#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

vector<pll> adj[100020];
pll dis[100020];

void Main(){
	int n, m; cin >> n >> m;
	while (m--){
		int a, b; ll w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	for (int i = 1; i <= n; i++){
		sort(all(adj[i]), [](pll a, pll b){
			return a.sc < b.sc;
		});
		dis[i] = {1e15, -1};
	}
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push({0, 1}); dis[1] = {0, -1};
	while (!pq.empty()){
		ll dst = pq.top().fr; int now = pq.top().sc;
		pq.pop();
		if (now == n){
			int ptr = n;
			stack<int> st;
			while (ptr != -1){
				st.push(ptr);
				ptr = dis[ptr].sc;
			}
			while (!st.empty()){
				cout << st.top() << ' ';
				st.pop();
			}
			return;
		}
		if (dis[now].fr < dst){ continue; }
		for (pll p : adj[now]){
			int nxt = p.fr; ll d = p.sc;
			if (dis[nxt].fr <= d+dst){ continue; }
			dis[nxt] = {d+dst, now};
			pq.push({d+dst, nxt});
		}
	}
	cout << -1;
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