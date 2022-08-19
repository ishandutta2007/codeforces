#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e6;

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < N; i++) {
		int v; cin >> v; pq.push(v);
	}

	int res = 0;
	while(!pq.empty()) {
		int v = pq.top(); pq.pop();
		if(!pq.empty() && pq.top() == v) {
			pq.pop();
			pq.push(v + 1);
		} else {
			res++;
		}
	}

	cout << res << '\n';
	return 0;
}