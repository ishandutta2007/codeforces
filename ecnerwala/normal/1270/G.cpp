#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
int N;
int A[MAXN];
bool vis[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < N; i++) {
			vis[i] = false;
		}
		vector<int> inds;
		inds.reserve(N);
		int v = 0;

		vector<int> ans;

		while (true) {
			assert(-N < v && v <= 0);
			if (vis[-v]) {
				auto it = find(inds.begin(), inds.end(), -v);
				ans = vector<int>(it, inds.end());
				break;
			}
			inds.push_back(-v);
			vis[-v] = true;
			v += A[-v];
			assert(-N < v && v <= 0);
		}
		assert(!ans.empty());
		cout << ans.size() << '\n';
		for (int i = 0; i < int(ans.size()); i++) {
			cout << ans[i]+1 << " \n"[i+1==int(ans.size())];
		}
	}

	return 0;
}