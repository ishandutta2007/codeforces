#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

const int N = 2e5 + 20;
set<int> graph[N];

void no() {
	cout << "No\n";
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		graph[x].insert(y);
		graph[y].insert(x);
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i]; --a[i];
	}
	if (a[0] != 0) no();
	queue<int> q;
	q.push(0);
	int cur = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int did = 0;
		for (; cur + did < n && graph[u].count(a[cur + did]); did++);
		if (did != szof(graph[u]) - (u != 0)) no();
		for (int i = 0; i < did; ++i) q.push(a[cur + i]);
		cur += did;
	}
	cout << "Yes\n";
	return 0;
}