#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	
	map<int, map<int, int> > markers, caps;
	map<int, int> totalMarkers, totalCaps;

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		++markers[y][x];
		++totalMarkers[y];
	}

	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		++caps[y][x];
		++totalCaps[y];
	}

	int totalPairs = 0, beautifulPairs = 0;
	for (auto it = markers.begin(); it != markers.end(); ++it) {
		int diameter = it -> first;
		totalPairs += min(totalMarkers[diameter], totalCaps[diameter]);

		for (auto jt = markers[diameter].begin(); jt != markers[diameter].end(); ++jt) {
			int color = jt -> first;
			beautifulPairs += min(markers[diameter][color], caps[diameter][color]);
		}
	}

	cout << totalPairs << " " << beautifulPairs << "\n";
}