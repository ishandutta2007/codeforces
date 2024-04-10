#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int main() {
	int n, l; cin >> n >> l;
	vector<int> v(n+1), w(n+1);
	w[0] = v[n] = 2e9;
	for (int i = 1; i < n; i++) {
		cin >> v[i];
	}
	priority_queue< pair<int, int> > pq;
	for (int i = 0; i <= l; i++) {
		pq.emplace(i, v[i]);
	}
	for (int i = 0; i < n; i++) {
		int cap = w[i];
		while (!pq.empty() && cap != 0) {
			int idx = pq.top().first; pq.pop();
			if (idx <= i) {
				continue;
			}
			if (cap < v[idx]) {
				v[idx] -= cap;
				w[idx] += cap;
				cap = 0;
				pq.emplace(idx, v[idx]);
			} else {
				cap -= v[idx];
				w[idx] += v[idx];
				v[idx] = 0;
			}
		}
		if (i + l + 1 <= n) {
			pq.emplace(i+l+1, v[i+l+1]);
		}
	}
	cout << w[n] << endl;
	return 0;
}