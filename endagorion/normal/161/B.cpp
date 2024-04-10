#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

struct TGood {
	int cost, id;
	TGood(int _cost = 0, int _id = 0)
		: cost(_cost)
		, id(_id)
	{
	}

	bool operator<(const TGood &a) const {
		return cost < a.cost;
	}
};

int main() {
	fout.precision(1);
	fout << fixed;

	int N, K;
	fin >> N >> K;

	vector< TGood >	stools, pens;
	vector<int> costs(N);

	for (int i = 0; i < N; ++i) {
		int cost, type;
		fin >> cost >> type;
		costs[i] = cost;
		if (type == 1) {
			stools.push_back(TGood(cost, i));
		} else {
			pens.push_back(TGood(cost, i));
		}
	}

	sort(stools.begin(), stools.end());
	
	vector< vector< int > > buckets(K);

	int lastSt = K;
	while (lastSt > 0 && !stools.empty()) {
		--lastSt;
		buckets[lastSt].push_back(stools.back().id);
		stools.pop_back();
	}

	while (!stools.empty()) {
		buckets[0].push_back(stools.back().id);
		stools.pop_back();
	}

	int lastFill = lastSt;
	while (lastFill > 0) {
		--lastFill;
		buckets[lastFill].push_back(pens.back().id);
		pens.pop_back();
	}

	while (!pens.empty()) {
		buckets[0].push_back(pens.back().id);
		pens.pop_back();
	}

	double ans = 0.0;

	for (int i = 0; i < K; ++i) {
		int minCost = 1000000001;
		for (size_t j = 0; j < buckets[i].size(); ++j) {
			ans += 1.0 * costs[buckets[i][j]];
			minCost = min(minCost, costs[buckets[i][j]]);
		}
		if (i >= lastSt) {
			ans -= 0.5 * minCost;
		}
	}

	fout << ans << '\n';
	for (int i = 0; i < K; ++i) {
		fout << buckets[i].size();
		for (size_t j = 0; j < buckets[i].size(); ++j) {
			fout << ' ' << buckets[i][j] + 1;
		}
		fout << '\n';
	}

	return 0;
}