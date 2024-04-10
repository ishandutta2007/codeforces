#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<long long> A(N + 1);
		for (int i = 1; i <= N; ++i) cin >> A[i];
		for (int i = 1; i <= N; ++i) {
			int x; cin >> x;
			A[i] -= x;
		}
		for (int i = 1; i <= N; ++i) A[i] += A[i - 1];
		vector<vector<int>> edges(N + 1);
		while (M--) {
			int l, r; cin >> l >> r; --l;
			edges[l].push_back(r);
			edges[r].push_back(l);
		}
		if (A[N] != 0) {
			cout << "NO\n";
			continue;
		}
		queue<int> Q;
		set<int> bad;
		for (int i = 0; i <= N; ++i) if (A[i] == 0) Q.push(i);
		else bad.insert(i);
		auto clear = [&](int l, int r) {
			if (l > r) swap(l, r);
			auto it = bad.lower_bound(l);
			while (it != bad.end() && *it <= r) {
				Q.push(*it); A[*it] = 0;
				bad.erase(it++);
			}
		};
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			for (int y : edges[x]) if (A[y] == 0) clear(x, y);
		}
		if (count(A.begin(), A.end(), 0) != N + 1)
			cout << "NO\n";
		else cout << "YES\n";
	}
	
	return 0;
}