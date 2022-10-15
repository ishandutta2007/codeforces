#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

inline vector<string> rotate(vector<string> v) {
	int n = v.size(), m = v[0].size();
	vector<string> q(m, string(n, ' '));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			q[j][i] = v[i][j];
		}
	}
	return q;
}

int main() {
	int n, m; cin >> n >> m;
	bool swapped = false;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	const int LEFT = 0;
	const int RIGHT = 1;
	const int UP = 2;
	const int DOWN = 3;
	char dc[4] = {'L', 'R', 'U', 'D'};
	const int dx[4] = {0, 0, -1, +1};
	const int dy[4] = {-1, +1, 0, 0};
	
	int cpX = 0, cpY = 0;
	
	auto get = [&]() {
		cin >> cpX >> cpY; cpX--; cpY--;
		if (swapped) {
			swap(cpX, cpY);
		}
	};
	
	auto go = [&](int dir) {
		cout << dc[dir] << endl;
		get();
		if (cpX < 0 || cpY < 0) {
			exit(0);
		}
		if (v[cpX][cpY] == 'F') {
			exit(0);
		}
	};
	
	auto lPossible = [&]() -> bool {
		for (int i = 0; i < m; i++) {
			if (v[0][i] == '*') {
				return false;
			}
			if (v[0][i] == 'F') {
				return true;
			}
			if (v[1][i] != '*') {
				return true;
			}
		}
		return false;
	};
	
	if (n != 1 && (m == 1 || v[0][1] == '*' || !lPossible())) {
		v = rotate(v);
		dc[0] = 'U'; dc[1] = 'D'; dc[2] = 'L'; dc[3] = 'R';
		swap(n, m);
		swapped = true;
	}
	go(RIGHT);
	int qY = cpY;
	if (qY == 0) {
		swap(dc[LEFT], dc[RIGHT]);
	} else {
		go(LEFT);
	}
	
	
	if (n != 1) {
		while (v[1][cpY] == '*') {
			go(RIGHT);
		}
		
		go(DOWN);
		int qX = cpX;
		if (qX == 0) {
			swap(dc[UP], dc[DOWN]);
		} else {
			go(UP);
		}
	}
	
	vector<int> seq;
	function<bool(int, int)> dfs = [&](int x, int y) -> bool {
		if (!(0 <= x && x < n) || !(0 <= y && y < m)) {
			return false;
		}
		if (v[x][y] == 'F') {
			return true;
		}
		if (v[x][y] == '*') {
			return false;
		}
		v[x][y] = '*';
		for (int i = 0; i < 4; i++) {
			if (dfs(x + dx[i], y + dy[i])) {
				seq.push_back(i);
				return true;
			}
		}
		return false;
	};
	if (!dfs(cpX, cpY)) {
		cerr << "Fatal" << endl;
		for (;;);
	}
	
	reverse(seq.begin(), seq.end());
	for (int i: seq) {
		go(i);
	}
	
	return 0;
}