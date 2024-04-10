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

const long long P = 1000000000 + 7;

int main() {
	fout.precision(10);
	fout << fixed;

	string s, t;
	int K;
	fin >> s >> t >> K;
	int N = s.length();
	vector< vector<long long> > ways(2, vector<long long>(K + 1));
	ways[0][0] = 1;
	ways[1][0] = 0;
	for (int i = 0; i < K; ++i) {
		ways[0][i + 1] = (N - 1) * ways[1][i] % P;
		ways[1][i + 1] = (ways[0][i] + (N - 2) * ways[1][i]) % P;
	}

	int D = -1, W = -1;
	string ss = s;
	for (int i = 0; i < N; ++i) {
		reverse(s.begin(), s.end());
		reverse(s.begin(), s.end() - 1);
		if (s == ss) {
			D = i + 1;
			break;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (t == s) {
			W = i;
			break;
		}
		reverse(t.begin(), t.end());
		reverse(t.begin(), t.end() - 1);
	}
	long long ans = 0;
	if (W != -1) {
		for (int i = 0; i < N; ++i) {
			if (i % D == W) {
				long long cur;
				if (i == 0) {
					cur = ways[0][K];
				} else {
					cur = ways[1][K];
				}
				ans = (ans + cur) % P;
			}
		}
	}

	fout << ans << '\n';

	return 0;
}