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

struct TPos {
	int x;
	int age;

	TPos(int _x = 0, int _age = 0)
		: x(_x)
		, age(_age)
	{
	}

	bool operator<(const TPos &a) const {
		if (age != a.age) {
			return age < a.age;
		}
		return x < a.x;
	}
};

int main() {
	fout << fixed;

	int N;
	fin >> N;
	vector<TPos> poss(N);

	for (int i = 0; i < N; ++i) {
		fin >> poss[i].age;
		poss[i].x = i;
	}

	sort(poss.begin(), poss.end());

	int maxx = -1;
	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		maxx = max(maxx, poss[i].x);
		ans[poss[i].x] = maxx - poss[i].x - 1;
	}

	for (int i = 0; i < N; ++i) {
		fout << ans[i] << ' ';
	}

	fout << '\n';

	return 0;
}