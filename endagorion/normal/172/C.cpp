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

struct TStudent {
	long long x, t;
	int id;

	bool operator<(const TStudent &rhs) const {
		return x < rhs.x;
	}
};

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector<TStudent> studs(N);
	for (int i = 0; i < N; ++i) {
		fin >> studs[i].t >> studs[i].x;
		studs[i].id = i;
	}

	vector<long long> ans(N);
	int last = 0;
	long long time = 0;
	while (last < N) {
		int first = last;
		while (last < N && last - first < M) {
			time = max(time, studs[last++].t);
		}
		sort(studs.begin() + first, studs.begin() + last);
		int curx = 0;
		int firstToExit = first;
		while (firstToExit < last) {
			time += studs[firstToExit].x - curx;
			curx = studs[firstToExit].x;
			int lastToExit = firstToExit;
			while (lastToExit < last && studs[lastToExit].x == studs[firstToExit].x) {
				ans[studs[lastToExit].id] = time;
				++lastToExit;
			}
			time += 1 + (lastToExit - firstToExit) / 2;
			firstToExit = lastToExit;
		}
		time += curx;
	}

	for (int i = 0; i < N; ++i) {
		if (i > 0) {
			fout << ' ';
		}
		fout << ans[i];
	}
	fout << '\n';

	return 0;
}