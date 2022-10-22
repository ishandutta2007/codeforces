// GIVE ME WRONG ANSWER ON TEST 2

#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n, m;
vector<int> v[200020], w[200020];
int dep[200020], ans[200020];
bool chk[200020];

void bfs(int now){
	queue<pii> q;
	q.push({1, 0}); chk[1] = true;
	while (!q.empty()){
		int now = q.front().fr, dis = q.front().sc;
		q.pop();
		dep[now] = ans[now] = dis;
		//cout << "BFS " << now << ' ' << dis << endl;
		for (int nxt : v[now]){
			if (chk[nxt]) continue;
			q.push({nxt, dis+1}); chk[nxt] = true;
		}
	}
}

void f(int st){
	priority_queue<pii> pq;
	for (int i = 1; i <= n; i++){
		pq.push({ dep[i], i });
	}
	while (!pq.empty()){
		int dis = pq.top().fr, now = pq.top().sc;
		pq.pop();
		if (chk[now]) continue;
		chk[now] = true;
		for (int nxt : v[now]){
			if (dep[now] < dep[nxt]){
				if (ans[now] <= ans[nxt]) continue;
				ans[now] = ans[nxt];
			}
			else{
				if (ans[now] <= dep[nxt]) continue;
				ans[now] = dep[nxt];
			}
		}
	}
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		while (m--){
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			w[y].push_back(x);
		}
		memset(chk, 0, sizeof(chk));
		bfs(1);
		memset(chk, 0, sizeof(chk));
		f(1);
		for (int i = 1; i <= n; i++){
			cout << ans[i] << ' ';
			v[i].clear(); w[i].clear();
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}