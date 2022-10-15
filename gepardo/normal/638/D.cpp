#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Koord {
	int x, y, z;
};

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	int n, m, d; cin >> n >> m >> d;
	vector< vector<string> > a(n, vector<string>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	static int lord[111][111][111] = {};
	int lszs[1000] = {};
	vector<Koord> layers[1000] = {};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < d; k++) {
				if (a[i][j][k] == '0') {
					continue;
				}
				lord[i][j][k] = lszs[i + j + k]++;
				layers[i + j + k].push_back({i, j, k});
			}
		}
	}
	
	auto have = [&](int i, int j, int k) {
		return 0 <= i && i < n && 0 <= j && j < m && 0 <= k && k < d && a[i][j][k] == '1';
	};
	
	int dx[3] = {1, 0, 0};
	int dy[3] = {0, 1, 0};
	int dz[3] = {0, 0, 1};
	
	int ans = 0;
	
	for (int i = 0; i < n+m+d; i++) {
		if (lszs[i] == 0 || lszs[i+1] == 0 || lszs[i+2] == 0) {
			continue;
		}
		vector< map<int, int> > pass(lszs[i]);
		vector<char> brkng(lszs[i+1], false);
		for (int j = 0; j < lszs[i]; j++) {
			Koord kur = layers[i][j];
			for (int k = 0; k < 3; k++) {
				Koord kur2 {kur.x + dx[k], kur.y + dy[k], kur.z + dz[k]};
				if (!have(kur2.x, kur2.y, kur2.z)) {
					continue;
				}
				for (int l = 0; l < 3; l++) {
					Koord kur3 {kur2.x + dx[l], kur2.y + dy[l], kur2.z + dz[l]};
					if (!have(kur3.x, kur3.y, kur3.z)) {
						continue;
					}
					int key = lord[kur3.x][kur3.y][kur3.z];
					int value = lord[kur2.x][kur2.y][kur2.z];
					if (pass[j].count(key)) {
						pass[j][key] = -1;
					} else {
						pass[j][key] = value;
					}
				}
			}
			for (auto it: pass[j]) {
				if (it.second >= 0) {
					brkng[it.second] = true;
				}
			}
		}
		for (auto it: brkng) {
			ans += it;
		}
	}
	
	cout << ans << endl;
	return 0;
}