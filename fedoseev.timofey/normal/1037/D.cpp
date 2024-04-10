#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

set <int> g[N];

int main() {
	ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
	#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i + 1 < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	if (a[0] != 0) {
		cout << "No\n";
		return 0;
	}
	vector <int> d(n, -1);
	d[a[0]] = 0;
	queue <int> q;
	q.push(0);
	int uk = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		while (uk < n && g[u].count(a[uk])) {
			d[a[uk]] = d[u] + 1;
			q.push(a[uk]);
			g[u].erase(a[uk]);
			g[a[uk]].erase(u);
			++uk;
		}
		if (!g[u].empty()) {
			cout << "No\n";
			return 0;
		}
	}
	if (uk == n) cout << "Yes\n";
	else cout << "No\n";
}