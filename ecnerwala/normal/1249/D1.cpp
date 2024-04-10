#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N, K;
pair<int, pair<int, int>> seg[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> seg[i].first >> seg[i].second.first;
		seg[i].second.second = i;
	}
	sort(seg, seg + N);

	set<pair<int, int>> pq;
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		while (!pq.empty() && pq.begin()->first < seg[i].first) {
			pq.erase(pq.begin());
		}
		pq.insert(seg[i].second);
		if (int(pq.size()) > K) {
			auto it = pq.end();
			--it;
			ans.push_back(it->second);
			pq.erase(it);
		}
	}
	cout << int(ans.size()) << '\n';
	for (int i = 0; i < int(ans.size()); i++) {
		cout << ans[i]+1 << " \n"[i+1==int(ans.size())];
	}

	return 0;
}