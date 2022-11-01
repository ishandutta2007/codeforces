#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int, pair<int, int>> map_move = {{'L', {0, -1}}, {'R', {0, 1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string moves;
		cin >> moves;
		int x = 0, y = 0;
		int min_x = 0, max_x = 0, min_y = 0, max_y = 0;
		function<bool(int, int, int, int)> Check = [&](int mi_x, int ma_x, int mi_y, int ma_y) {
			return ma_x - mi_x <= n - 1 && ma_y - mi_y <= m - 1;
		};
		for (char ch : moves) {
			pair<int, int> this_move = map_move[ch];
			int new_x = x + this_move.first;
			int new_y = y + this_move.second;
			int new_min_x = min(min_x, new_x);
			int new_max_x = max(max_x, new_x);
			int new_min_y = min(min_y, new_y);
			int new_max_y = max(max_y, new_y);
			if (!Check(new_min_x, new_max_x, new_min_y, new_max_y)) {
				break;
			}
			x = new_x;
			y = new_y;
			min_x = new_min_x;
			max_x = new_max_x;
			min_y = new_min_y;
			max_y = new_max_y;
		}
		cout << n - max_x << ' ' << m - max_y << '\n';
	}
	return 0;
}

//