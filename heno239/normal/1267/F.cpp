#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18)+100;
#define rep(i, n) for(int i=0;i<n;++i)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

int d[1 << 18];
void solve() {
	int n, m, a, b; cin >> n >> m >> a >> b;
	vector<int> u(a), v(b);
	rep(i, a) {
		int x; cin >> x; x--;
		d[x]++; u[i] = x;
	}
	rep(i, b) {
		int x; cin >> x; x--;
		d[x]++; v[i] = x;
	}
	int sum = 0;
	rep(i, n) {
		d[i]++;
		sum += d[i];
	}
	if (sum > n + m - 1) {
		cout << "No" << endl; return;
	}
	int dif = n + m - 1 - sum;
	rep(i, dif) {
		u.push_back(0); d[0]++;
	}
	sum = 0;
	rep(i, m) {
		d[i + n]++;
		sum += d[i + n];
	}
	if (sum > n + m - 1) {
		cout << "No" << endl; return;
	}
	dif = n + m - 1 - sum;
	rep(i, dif) {
		v.push_back(n); d[n]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	vector<P> ans;
	rep(i, n + m)if (d[i] == 1)q.push(i);
	int id1 = 0, id2 = 0;
	rep(i, n + m - 2) {
		int id = q.top(); q.pop();
		if (id < n) {
			int to = v[id2];
			ans.push_back({ id,to });
			d[to]--;
			if (d[to] == 1)q.push(to);
			id2++;
		}
		else {
			int to = u[id1];
			ans.push_back({ id,to });
			d[to]--;
			if (d[to] == 1)q.push(to);
			id1++;
		}
	}
	int fr = q.top(); q.pop(); int to = q.top(); q.pop();
	ans.push_back({ fr,to });
	cout << "Yes" << endl;
	rep(i, n + m - 1) {
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}