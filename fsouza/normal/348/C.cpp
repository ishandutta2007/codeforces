#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

#define MAXN 100000
#define MAXM 100000
#define MAXB 350
#define MAXBSIZE 350

typedef long long lint;

using namespace std;

const int slim = 316;

lint A[MAXN];
char bigcontain[MAXB][MAXN];
int size[MAXM], bigid[MAXM];

lint orig[MAXM];

vector <int> contain[MAXM];
vector <int> belong[MAXN];
vector <int> bigs;

lint smalldelta[MAXN], biglazy[MAXB], received[MAXB];
int ncross[MAXB][MAXM];

int main(int argc, char ** argv)
{
	int n, m, nq;

	cin >> n >> m >> nq;

	for (int i = 0; i < n; i++)
		cin >> A[i];
	
	memset(smalldelta, 0, sizeof(smalldelta));
	memset(bigcontain, 0, sizeof(bigcontain));
	memset(biglazy, 0, sizeof(biglazy));
	memset(orig, 0, sizeof(orig));
	memset(received, 0, sizeof(received));

	int nbig = 0;
	
	for (int i = 0; i < m; i++) {
		cin >> size[i];
		
		if (size[i] > slim) {
			bigid[i] = nbig++;
			bigs.push_back(i);
		} else
			bigid[i] = -1;

		for (int j = 0; j < size[i]; j++) {
			int idx;
			cin >> idx; idx--;
			
			if (bigid[i] != -1) {
				bigcontain[bigid[i]][idx] = 1;
			}

			contain[i].push_back(idx);
			belong[idx].push_back(i);

			orig[i] += A[idx];
		}
	}

	for (int i = 0; i < nbig; i++) {
		for (int j = 0; j < m; j++) {
			ncross[i][j] = 0;

			for (int k = 0; k < (int)contain[j].size(); k++)
				if (bigcontain[i][contain[j][k]])
					ncross[i][j] ++;
		}
	}

	for (int q = 0; q < nq; q++) {
		char op;
		int sid;

		scanf(" %c %d", &op, &sid); sid--;

		if (op == '?') {
			lint ret = orig[sid];

			if (bigid[sid] == -1) {
				for (int i = 0; i < (int)contain[sid].size(); i++) {
					int id = contain[sid][i];
					ret += smalldelta[id];
				}

				for (int bid = 0; bid < nbig; bid++) {
					const int i = bigs[bid];
					ret += biglazy[bid] * (lint)ncross[bid][sid];
				}
			} else {
				ret += received[bigid[sid]];
			}

			cout << ret << endl;
		} else if (op == '+') {
			lint delta;
			
			cin >> delta;

			if (bigid[sid] == -1) {
				for (int i = 0; i < (int)contain[sid].size(); i++) {
					int id = contain[sid][i];
					smalldelta[id] += delta;
				}

				for (int bid = 0; bid < nbig; bid++) {
					received[bid] += delta * (lint)ncross[bid][sid];
				}
			} else {
				int bid = bigid[sid];

				biglazy[bid] += delta;

				for (int bid2 = 0; bid2 < nbig; bid2++) {
					const int j = bigs[bid2];

					received[bid2] += delta * (lint)ncross[bid][j];
				}
			}
		}
	}

	return 0;
}