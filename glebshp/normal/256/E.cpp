#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int mdl = 777777777;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;

int global[3][3];
int n, m;
long long rmq[rms][3][3];
bool inside[rms];

int main() {
	//freopen("problem_e.in", "r", stdin);
	//freopen("problem_e.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &global[i][j]);
	
	for (int i = 0; i < n; i++) {
		int ps = i + hrms + 1;
		inside[ps] = true;

		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				rmq[ps][j][k] = (j == k);
	}

	for (int i = hrms; i > 0; i--) {
		inside[i] = inside[i * 2] || inside[i * 2 + 1];

		if (!inside[i])
			continue;

		if (!inside[i * 2 + 1]) {
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					rmq[i][j][k] = rmq[i * 2][j][k];

			continue;
		}

		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				rmq[i][j][k] = 0;
				for (int p1 = 0; p1 < 3; p1++)
					for (int p2 = 0; p2 < 3; p2++)
						if (global[p1][p2])
							rmq[i][j][k] += rmq[i * 2][j][p1] * rmq[i * 2 + 1][p2][k];

				rmq[i][j][k] %= mdl;
			}
	}

	for (int i = 0; i < m; i++) {
		int ps, val;
		scanf("%d%d", &ps, &val);

		ps += hrms;
		if (val == 0) {
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					rmq[ps][j][k] = (j == k);
		} else {
			val--;
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					rmq[ps][j][k] = 0;

			rmq[ps][val][val] = 1;
		}

		while (ps > 1) {
			ps /= 2;

			if (!inside[ps * 2 + 1]) {
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
						rmq[ps][j][k] = rmq[ps * 2][j][k];

				continue;
			}

			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++) {
					rmq[ps][j][k] = 0;
					for (int p1 = 0; p1 < 3; p1++)
						for (int p2 = 0; p2 < 3; p2++)
							if (global[p1][p2])
								rmq[ps][j][k] += rmq[ps * 2][j][p1] * rmq[ps * 2 + 1][p2][k];

					rmq[ps][j][k] %= mdl;
				}
		}

		long long totans = 0;
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				totans += rmq[1][j][k];

		totans %= mdl;

		cout << totans << endl;
	}

	return 0;
}