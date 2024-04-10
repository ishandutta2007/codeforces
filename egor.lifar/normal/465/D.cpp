#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <math.h>


using namespace std;


#define eps 0.000001
#define INF 1000000000


vector<double> v;
long long k[8][3], k1[8][3];


double rast(long long i, long long j) {
	return sqrt((k1[i][0] - k1[j][0]) * (k1[i][0] - k1[j][0]) + (k1[i][1] - k1[j][1]) * (k1[i][1] - k1[j][1]) + (k1[i][2] - k1[j][2]) * (k1[i][2] - k1[j][2]));
}


long long t = 0;


void get(long long i) {
	//cout << i << endl;
	if (i == 8) {
		//cout << "o" << endl;
		t++;
		double l = INF;
		for (long long i1 = 0; i1 < 8; i1++) {
			for (long long j = 0; j < 8; j++) {
				if (i1 != j) {
					l = min(l, rast(i1, j));
				}
			}
		}
		bool b = true;
		for (long long i1 = 0; i1 < 8; i1++) {
			vector<long long> t;
			for (long long j = 0; j < 8; j++) {
				double l1 = rast(i1, j);
				if (abs(l1 - l) <= eps) {
					t.push_back(j);
				}
			}
			if ((long long)t.size() != 3) {
				b = false;
				break;
			}
			for (long long j = 0; j < 3; j++) {
				if (!b) {
					break;
				}
				for (long long j1 = j + 1; j1 < 3; j1++) {
					long long g[3], g1[3];
					g[0] = k1[t[j]][0] - k1[i1][0];
					g[1] = k1[t[j]][1] - k1[i1][1];
					g[2] = k1[t[j]][2] - k1[i1][2];
					g1[0] = k1[t[j1]][0] - k1[i1][0];
					g1[1] = k1[t[j1]][1] - k1[i1][1];
					g1[2] = k1[t[j1]][2] - k1[i1][2];
					if (g[0] * g1[0] + g[1] * g1[1] + g[2] * g1[2] != 0) {
						b = false;
						break;
					} 
				}
			}
			if (!b) {
				break;
			}
		}
		//cout << endl;
		if (b) {
			cout << "YES" << endl;
			for (long long i1 = 0; i1 < 8; i1++) {
				for (long long j = 0; j < 3; j++) {
					cout << k1[i1][j] << ' ';
				}
				cout << endl;
			}
			exit(0);
		}
		return;
	}
	long long a[3] = {1, 2, 3};
	do {
		k1[i][0] = k[i][a[0] - 1];
		k1[i][1] = k[i][a[1] - 1];
		k1[i][2] = k[i][a[2] - 1];
		get(i + 1);
	}while (next_permutation(a, a + 3));
}


int main() {
	for (long long i = 0; i < 8; i++) {
		for (long long j = 0; j < 3; j++) {
			cin >> k[i][j];
		}
	}
	k1[0][0] = k[0][0];
	k1[0][1] = k[0][1];
	k1[0][2] = k[0][2];
	get(1);
	cout << "NO" << endl;
    return 0;
}