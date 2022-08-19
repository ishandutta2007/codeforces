#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		array<vector<int>, 3> gems;
		for (int z = 0; z < 3; z++) {
			int n; cin >> n; gems[z].resize(n);
		}
		for (int z = 0; z < 3; z++) {
			for (auto& v : gems[z]) cin >> v;
			sort(gems[z].begin(), gems[z].end());
		}

		i64 ans = 8e18;
		auto sq = [](i64 a) { return a * a; };
		auto val = [&sq](i64 a, i64 b, i64 c) {
			return sq(a-b) + sq(b-c) + sq(c-a);
		};

		for (int z = 0; z < 3; z++) {
			int x = (z+1)%3, y = (z+2)%3;

			int ix = 0, iy = 0;
			for (int iz = 0; iz < int(gems[z].size()); iz++) {
				while (ix < int(gems[x].size()) && gems[x][ix] < gems[z][iz]) ix++;
				while (iy < int(gems[y].size()) && gems[y][iy] < gems[z][iz]) iy++;

				for (int cx : {ix-1, ix}) {
					if (0 <= cx && cx < int(gems[x].size())) {
						for (int cy : {iy-1, iy}) {
							if (0 <= cy && cy < int(gems[y].size())) {
								ans = min(ans, val(gems[x][cx], gems[y][cy], gems[z][iz]));
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}