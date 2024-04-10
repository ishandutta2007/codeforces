#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int H, N; cin >> H >> N;
	vector<vector<int8_t>> G(N, vector<int8_t>(H));
	for (int i = 0; i < H; i++) {
		string r; cin >> r;
		for (int j = 0; j < N; j++) {
			G[j][H-1-i] = (r[j] == '#');
		}
	}
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		int h = -1;
		int a; cin >> a;
		while (a > 0) {
			h++;
			if (G[i][h]) a--;
		}
		assert(h == -1 || G[i][h]);
		A[i] = h;
	}

	int need = -1;
	int has = -1;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i > 0) {
			for (int h = 0; h < H; ) {
				if (!G[i-1][h]) { h++; continue; }
				int first = -1;
				int last = -1;
				while (h < H && G[i-1][h]) {
					if (G[i][h]) {
						if (first == -1) first = h;
						last = h;
					}
					h++;
				}
				if (first != -1) {
					for (int z = first; z <= last; z++) G[i][z] = true;
				}
			}
		}

		while (need != -1 && need < H && !G[i][need]) need++;
		if (need == H) {
			ans++;
			need = -1;
			has = H-1;
		}
		need = max(need, A[i]);
		assert(need == -1 || G[i][need]);
		while (need > 0 && G[i][need-1]) need--;

		while (has != -1 && !G[i][has]) has--;
		assert(has == -1 || G[i][has]);
		while (has != -1 && has+1 < H && G[i][has+1]) has++;

		if (need <= has) need = -1;
	}
	if (need != -1) ans++;

	cout << ans << '\n';

	return 0;
}