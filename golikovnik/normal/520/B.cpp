#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'

const int MAXN = 1e7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<int> q;
	vector<int> d(MAXN);
	vector<char> used(MAXN);
	d[n] = 0;
	q.push(n);
	used[n] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == m) break;
		if (!used[v + v] && v < m) {
			d[v + v] = d[v] + 1;
			q.push(v + v);
			used[v + v] = 1;
		}
		if (!used[v-1] && v - 1 > 0) {
			d[v-1] = d[v] + 1;
			q.push(v - 1);
			used[v - 1] = 1;
		}
	}
	cout << d[m] << endl;
	return 0;
}