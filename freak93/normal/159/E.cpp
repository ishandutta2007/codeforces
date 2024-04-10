#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long long inf = 1LL << 60;

void combine(long long &answer, pair<int, int> &bestWhite, pair<int, int> &bestBlack,
			 pair<long long, int> A, int manyA, pair<long long, int> B, int manyB) {
	if (A.first + B.first <= answer)
		return;
	
	answer = A.first + B.first;
	bestWhite = make_pair(A.second, manyA);
	bestBlack = make_pair(B.second, manyB);
}

int main() {
	int N; cin >> N;

	map<int, vector< pair<long long, int> > > M;
	int many = 0;
	for (int i = 0; i < N; ++i) {
		int color; long long size;
		cin >> color >> size;
		M[color].push_back(make_pair(size, i + 1));
		many = max(many, static_cast<int>(M[color].size()));
	}

	vector< pair<long long, int> > firstBest(many, make_pair(-inf, -1)), secondBest(many, make_pair(-inf, -1));

	for (auto it = M.begin(); it != M.end(); ++it) {
		sort(it -> second.begin(), it -> second.end());
		reverse(it -> second.begin(), it -> second.end());
		
		vector< pair<long long, int> > &sizes = (it -> second);
		for (size_t i = 0; i < sizes.size(); ++i) {
			if (i > 0)
				sizes[i].first += sizes[i - 1].first;
			auto currentPair = make_pair(sizes[i].first, it -> first);
			if (firstBest[i] < currentPair) {
				secondBest[i] = firstBest[i];
				firstBest[i] = currentPair;
			}
			else
				if (secondBest[i] < currentPair)
					secondBest[i] = currentPair;
		}
	}

	long long answer = -2 * inf;
	pair<int, int> bestWhite, bestBlack;
	for (int i = 0; i < many; ++i) {
		// Even number of cubes in the tower
		combine(answer, bestWhite, bestBlack, firstBest[i], i, secondBest[i], i);
		
		if (i == 0)
			continue;
		// Odd number of cubes in the tower
		if (firstBest[i - 1].second != firstBest[i].second) 
			combine(answer, bestWhite, bestBlack, firstBest[i - 1], i - 1, firstBest[i], i);
		 else {
			// Black & White
			combine(answer, bestWhite, bestBlack, firstBest[i - 1], i - 1, secondBest[i], i);
			// White & Black
			combine(answer, bestWhite, bestBlack, secondBest[i - 1], i - 1, firstBest[i], i);
		}
	}

	//cerr << " ---- " << firstBest[0].first << " " << firstBest[0].second << "\n";
	//cerr << " ---- " << secondBest[0].first << " " << secondBest[0].second << "\n";
	cout << answer << "\n";
	cout << bestWhite.second + bestBlack.second + 2 << "\n";
	// Black/White/Black/White/....
	for (int i = 0; i <= bestWhite.second; ++i)
		cout << M[bestBlack.first][i].second << " " << M[bestWhite.first][i].second << " ";
	if (bestBlack.second > bestWhite.second)
		cout << M[bestBlack.first][bestBlack.second].second << "\n";
	else
		cout << "\n";
}