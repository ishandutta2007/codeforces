#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;

const int MAXQ = 3.1e5;
int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;

	deque<int> dq;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		dq.push_back(a);
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < 2 * N; i++) {
		int a = dq.front(); dq.pop_front();
		int b = dq.front(); dq.pop_front();
		ans.emplace_back(a, b);
		dq.push_front(max(a, b));
		dq.push_back(min(a, b));
	}

	for (int i = 0; i < Q; i++) {
		long long m; cin >> m;
		m--;
		long long v = m % (N-1);
		while (v+(N-1) <= m && v+(N-1) < int(ans.size())) v += N-1;
		cout << ans[v].first << ' ' << ans[v].second << '\n';
	}

	return 0;
}