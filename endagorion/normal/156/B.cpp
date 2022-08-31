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

int main() {
	fout << fixed;

	int N, M;
	fin >> N >> M;

	vector< vector<int> > yes(N), no(N);
	int noKill = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		fin >> x;
		if (x > 0) {
			yes[x - 1].push_back(i);
		} else {
			x = -x;
			++noKill;
			no[x - 1].push_back(i);
		}
	}

	int susp = 0;
	for (int i = 0; i < N; ++i) {
		int right = noKill + yes[i].size() - no[i].size();
		if (right == M) {
			++susp;
		}
	}
	vector<int> truth(N);

	if (susp == 1) {
		for (int i = 0; i < N; ++i) {
			int right = noKill + yes[i].size() - no[i].size();
			if (right == M) {
				for (size_t j = 0; j < yes[i].size(); ++j) {
					truth[yes[i][j]] = 1;
				}
				for (size_t j = 0; j < no[i].size(); ++j) {
					truth[no[i][j]] = -1;
				}
			} else {
				for (size_t j = 0; j < yes[i].size(); ++j) {
					truth[yes[i][j]] = -1;
				}
				for (size_t j = 0; j < no[i].size(); ++j) {
					truth[no[i][j]] = 1;
				}
			}
		}
	} else {
		for (int i = 0; i < N; ++i) {
			int right = noKill + yes[i].size() - no[i].size();
			if (right == M) {
				for (size_t j = 0; j < yes[i].size(); ++j) {
					truth[yes[i][j]] = 0;
				}
				for (size_t j = 0; j < no[i].size(); ++j) {
					truth[no[i][j]] = 0;
				}
			} else {
				for (size_t j = 0; j < yes[i].size(); ++j) {
					truth[yes[i][j]] = -1;
				}
				for (size_t j = 0; j < no[i].size(); ++j) {
					truth[no[i][j]] = 1;
				}
			}
		}
	}
	
	for (int i = 0; i < N; ++i) {
		switch (truth[i]) {
		case -1: {
			fout << "Lie\n";
			break;
		}
		case 0: {
			fout << "Not defined\n";
			break;
				}
		case 1: {
			fout << "Truth\n";
			break;
				}
		}
	}

	return 0;
}