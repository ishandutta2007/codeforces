#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

struct Place {
	int knt, x, y;
};

inline bool operator<(const Place &a, const Place &b) {
	return a.knt < b.knt;
}

int main() {
	int n, k; cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i].erase(3, 1);
		v[i].erase(7, 1);
	}
	int neighbour = 0;
	vector<int> qn[10] = {
		{1},
		{0, 2},
		{1},
		{4},
		{3, 5},
		{4, 6},
		{5},
		{8},
		{7, 9},
		{8}
	};
	
	vector<Place> places;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			int kur = 0;
			for (int k: qn[j]) {
				if (v[i][j] == 'S' && v[i][k] != '.') {
					neighbour++;
				} else if (v[i][j] == '.' && v[i][k] == 'S') {
					kur++;
				}
			}
			if (v[i][j] == '.') {
				places.push_back({kur, i, j});
			}
		}
	}
	
	sort(places.begin(), places.end());
	assert((int)places.size() >= k);
	
	for (int i = 0; i < k; i++) {
		v[places[i].x][places[i].y] = 'x';
		neighbour += places[i].knt;
	}
	
	cout << neighbour << endl;
	for (int i = 0; i < n; i++) {
		v[i].insert(7, 1, '-');
		v[i].insert(3, 1, '-');
		cout << v[i] << "\n";
	}
	return 0;
}