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

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int deg(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; ++i) {
		res *= x;
	}
	return res;
}

void frac(vector<string> &field, const vector<string> &init, int x, int y, int depth, bool fill) {
	if (depth == 0) {
		for (size_t i = 0; i < init.size(); ++i) {
			for (size_t j = 0; j < init.size(); ++j) {
				field[x + i][y + j] = fill ? '*' : init[i][j];
			}
		}
		return;
	}
	int step = deg(init.size(), depth);
	for (size_t i = 0; i < init.size(); ++i) {
		for (size_t j = 0; j < init.size(); ++j) {
			frac(field, init, x + i * step, y + j * step, depth - 1, fill || (init[i][j] == '*'));
		}
	}
}

int main() {
	fout.precision(10);
	fout << fixed;

	int N, K;
	fin >> N >> K;
	vector<string> init(N);
	for (int i = 0; i < N; ++i) {
		fin >> init[i];
	}

	vector<string> field(deg(N, K), string(deg(N, K), '.'));
	frac(field, init, 0, 0, K - 1, false);

	for (int i = 0; i < deg(N, K); ++i) {
		fout << field[i] << '\n';
	}

	return 0;
}