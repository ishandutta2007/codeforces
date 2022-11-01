#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

const int MAXN = 1e6 + 1;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <bool> aint(MAXN, true);
	vector <int> pr, lp(MAXN), pos(MAXN);
	for (int i = 2; i < MAXN; i++) {
		if (lp[i] == 0) {
			pr.push_back(i);
			pos[i] = pr.size();
			lp[i] = i;
		}
		for (int j = 0; j < pr.size() && pr[j] <= i && pr[j] * i < MAXN; j++) 
			lp[pr[j] * i] = pr[j];
	}
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int x = sqrt(a[i]);
		if ((x * x == a[i]) || ((x + 1) * (x + 1) == a[i]) || ((x - 1) * (x - 1) == a[i])) {
			cout << 1;
			return 0;
		}
	}
	vector <vector <int>> fact(n);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		while (x != 1) {
			int div = lp[x];
			int cnt = 0;
			while (x % div == 0) {
				cnt++;
				x /= div;
			}
			if (cnt % 2) 
				fact[i].push_back(div);
		}
	}
	for (int i = 0; i < n; i++) {
		if (fact[i].size() == 1) {
			fact[i].push_back(1);
			swap(fact[i][0], fact[i][1]);
		}
		if (fact[i].size() == 0) {
			fact[i].push_back(1);
			fact[i].push_back(1);
		}
	}
	vector <vector <pair <int, int>>> g(MAXN);
	for (int i = 0; i < n; i++) {
		g[pos[fact[i][0]]].push_back({ pos[fact[i][1]], i });
		g[pos[fact[i][1]]].push_back({ pos[fact[i][0]], i });
	}
	int ans = INF;
	for (int i = 0; i <= 1e3; i++) {
		queue <int> q;
		q.push(i);
		vector <bool> used(pr.size() + 1);
		vector <int> d(pr.size() + 1, INF);
		vector <bool> usede(n);
		d[i] = 0;
		used[i] = true;
		bool tf = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto u : g[v]) {
				if (usede[u.second]) continue;
				if (used[u.first]) {
					ans = min(ans, d[v] + d[u.first] + 1);
					tf = false;
					break;
				}
				d[u.first] = d[v] + 1;
				q.push(u.first);
				used[u.first] = true;
				usede[u.second] = true;
			}
			if (!tf) break;
		}
	}
	if (ans > n) cout << -1;
	else cout << ans;
	return 0;
}