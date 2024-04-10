#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<int> b(n), deg(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (b[i] == -1) continue;
		++deg[--b[i]];
	}
	queue<int> q;			
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 0) q.push(i);		
	}
	long long ans = 0;
	vector<int> ord1;
	stack<int> ord2;
	while (!q.empty()) {
		int nd = q.front();
		q.pop();
		if (a[nd] > 0 && b[nd] != -1) {
			a[b[nd]] += a[nd];
			ord1.push_back(nd);
		} else ord2.push(nd);
		ans += a[nd];
		if (b[nd] != -1 && --deg[b[nd]] == 0) {
			q.push(b[nd]);
		}
	}
	cout << ans << '\n';
	for (auto el : ord1) cout << el + 1 << ' ';
	while (!ord2.empty()) {
		cout << ord2.top() + 1 << ' ';
		ord2.pop();
	}
}