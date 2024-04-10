#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, X, Y; cin >> N >> X >> Y;
		pair<int, vector<int>> ans(int(1e9), {});
		for (int d = 1; d <= (Y-X); d++) {
			if ((Y-X) % d != 0) {
				continue;
			}
			vector<int> cnd(N);
			for (int i = 0; i < N; i++) {
				cnd[i] = d * i + (X-1)%d + 1;
			}

			if (cnd.back() < Y) {
				int extra = Y - cnd.back();
				for (int i = 0; i < N; i++) {
					cnd[i] += extra;
				}
			}

			if (cnd[0] > X) continue;

			ans = min(ans, {*max_element(cnd.begin(), cnd.end()), cnd});
		}

		for (int i = 0; i < N; i++) {
			cout << ans.second[i] << " \n"[i+1==N];
		}
	}

	return 0;
}