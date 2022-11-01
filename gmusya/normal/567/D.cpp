#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, k, a;
	cin >> n >> k >> a;
	a++;
	set <pair <int, int>> s;
	s.insert({ 1, n });
	int cur_k = (n + 1) / a;
	int m;
	cin >> m;
	vector <int> arr(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	for (int it = 1; it <= m; it++) {
		int pos = arr[it - 1];
		auto now = *(--s.upper_bound({ pos, n + 1 }));
		int l = now.first;
		int r = now.second;
		cur_k -= (r - l + 2) / a;
		s.erase(now);
		int l1 = l, r1 = pos - 1, l2 = pos + 1, r2 = r;
		if (l1 <= r1) {
			s.insert({ l1, r1 });
			cur_k += (r1 - l1 + 2) / a;
		}
		if (l2 <= r2) {
			s.insert({ l2, r2 });
			cur_k += (r2 - l2 + 2) / a;
		}
		if (cur_k < k) {
			cout << it;
			return 0;
		}
	}
	cout << -1;
	return 0;
}