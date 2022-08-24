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


int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int> (n));
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			--a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
	}

	for (int i = 0; i < n; ++i) {
		int bestjj = n;
		int bestkk = n;
		int time = -1;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			int jj = 0;
			int kk = 0;
			for (int k = 0; k < n; ++k) {
				if (b[k] == j) {
					jj = k;
				}
				if (a[i][k] == j) {
					kk = k;
				}
			}
			if (jj < bestjj) {
				bestjj = jj;
				if (kk < bestkk) {
					bestkk = kk;
					time = j + 1;
				}
			}
		}
		cout << time << ' ';
	}

	cout << '\n';

	return 0;
}