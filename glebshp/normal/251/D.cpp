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
const int powmax = 61;
const int size = 100 * 1000 + 10;

bool mat[powmax][size];
bool b[powmax];

int cnt[powmax];
int n;
long long num[size];
int bt[powmax];
int lvl[powmax];
int rans[size];
bool orig[powmax];

int main() {
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &num[i]);

		for (int j = 0; j < powmax; j++) {
			mat[j][i] = num[i] % 2;

			cnt[j] += num[i] % 2;
			num[i] /= 2;
		}
	}

	for (int i = 0; i < powmax; i++)
		if (cnt[i] % 2 == 1 || cnt[i] == 0)
			b[i] = false;
		else
			b[i] = true;

	for (int i = 0; i < powmax; i++) {
		bt[i] = -1;
		lvl[i] = -1;
	}

	for (int i = 0; i < powmax; i++)
		orig[i] = b[i];

	for (int i = powmax - 1; i >= 0; i--) {
		if (orig[i]) {
			int nm = -1;
			for (int j = 0; j < n; j++)
				if (mat[i][j]) {
					nm = j;

					break;
				}

			if (nm != -1) {
				//lst = i;
				lvl[i] = 1;
			//	break;
			} else {
				//if (b[i])
				//	break;

				continue;
			}

			bt[i] = nm;
			for (int j = powmax - 1; j >= 0; j--)
				if (bt[j] == -1 && mat[j][nm]) {
					for (int k = 0; k < n; k++)
						mat[j][k] ^= mat[i][k];
					b[j] ^= b[i];
				}
		}
	}

	for (int i = powmax - 1; i >= 0; i--) {
		if (!orig[i]) {
			/*
			for (int j = powmax - 1; j > lst; j--)
				if (bt[j] == -1 && mat[i][bt[j]] && mat[j][bt[j]])
					for (int k = 0; k < n; k++) {
						mat[i][k] ^= mat[j][k];
						b[i] ^= b[j];
					}
			*/
			//if (!b[i])
			//	continue;
			

			int nm = -1;
			for (int j = 0; j < n; j++)
				if (mat[i][j]) {
					nm = j;

					break;
				}
			
			if (nm != -1) {
				lvl[i] = 0;
				
				///break;
			} else {
				//if (b[i])
				//	break;

				continue;
			}

			bt[i] = nm;
			for (int j = powmax - 1; j >= 0; j--)
				if (bt[j] == -1 && mat[j][nm]) {
					for (int k = 0; k < n; k++)
						mat[j][k] ^= mat[i][k];
					b[j] ^= b[i];
				}
		}
	}

	for (int i = 0; i < n; i++)
		rans[i] = 2;

	for (int i = 0; i < powmax; i++) {
		if (lvl[i] == 0) {
			assert(mat[i][bt[i]]);

			if (b[i])
				rans[bt[i]] = 1;

			for (int j = 0; j < powmax; j++)
				if ((lvl[j] == 1 || (lvl[j] == 0 && j > i)) && mat[j][bt[i]]) {
					//for (int k = 0; k < n; k++)
					//	mat[j][k] ^= mat[i][k];
					b[j] ^= b[i];
				}
		}
	}

	for (int i = 0; i < powmax; i++) {
		if (lvl[i] == 1) {
			assert(mat[i][bt[i]]);
			
			if (b[i])
				rans[bt[i]] = 1;

			for (int j = 0; j < powmax; j++)
				if ((lvl[i] == 1 && j > i) && mat[j][bt[i]]) {
					//for (int k = 0; k < n; k++)
					//	mat[j][k] ^= mat[i][k];
					b[j] ^= b[i];
				}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d%c", rans[i], " \n"[i == n - 1]);


	return 0;
}