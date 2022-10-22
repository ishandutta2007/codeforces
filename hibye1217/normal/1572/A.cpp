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
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

vector<int> nxt[200020];
int pc[200020];
int dis[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		priority_queue<pi2> pq;
		for (int i = 1; i <= n; i++){
			int m; cin >> m; pc[i] = m;
			while (m--){
				int x; cin >> x; nxt[x].push_back(i);
			}
			if (pc[i] == 0){ pq.push({i, 1}); dis[i] = 1; }
		}
		int cnt = 0;
		while (!pq.empty()){ cnt += 1;
			int now = pq.top().fr, dst = pq.top().sc;
			pq.pop();
			for (int idx : nxt[now]){
				int d = dst; if (now > idx){ d += 1; }
				dis[idx] = max(dis[idx], d);
				pc[idx] -= 1;
				if (pc[idx] == 0){ pq.push({idx, dis[idx]}); }
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){ ans = max(ans, dis[i]); }
		if (cnt != n){ cout << -1 << endl; }
		else{ cout << ans << endl; }
		for (int i = 1; i <= n; i++){
			nxt[i].clear();
			pc[i] = 0; dis[i] = 0;
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