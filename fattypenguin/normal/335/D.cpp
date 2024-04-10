#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(vector<PII>::iterator i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

bool rect[3333][3333];
int lx[222222], ly[222222], rx[222222], ry[222222];

short u[3333][3333];
short d[3333][3333];
short l[3333][3333];
short r[3333][3333];

int dp1[3333][3333];

bool isKey[3333][3333];

vector<PII> diag1[3333 * 4];
vector<PII> diag2[3333 * 4];

inline int sum(short a[3333][3333], int x, int l, int r) {
	int ret = a[x][r];
	if (l) ret -= a[x][l - 1];
	return ret;
}

inline int area(int x1, int y1, int x2, int y2) {

	if (!isKey[x1][y2] || !isKey[x2][y1]) return -1;

	int ret = dp1[x2][y2];
	if (x1) ret -= dp1[x1 - 1][y2];
	if (y1) ret -= dp1[x2][y1 - 1];
	if (x1 && y1) ret += dp1[x1 - 1][y1 - 1];

	if (sum(u, x1, y1, y2) != y2 - y1 + 1) return -1;
	if (sum(d, x2, y1, y2) != y2 - y1 + 1) return -1;
	if (sum(l, y1, x1, x2) != x2 - x1 + 1) return -1;
	if (sum(r, y2, x1, x2) != x2 - x1 + 1) return -1;

	return ret;
}

int main() {
	int n;
	cin >> n;
	REP(i, n) {
		scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
		--rx[i];
		--ry[i];
		dp1[rx[i]][ry[i]] = (rx[i] - lx[i] + 1) * (ry[i] - ly[i] + 1);
		diag1[lx[i] - ly[i] + 3000].PB(MP(lx[i], ly[i]));
		diag2[rx[i] - ry[i] + 3000].PB(MP(rx[i], ry[i]));

		for (int x = lx[i]; x <= rx[i]; ++x) {
			l[ly[i]][x] = 1;
			r[ry[i]][x] = 1;
		}

		for (int y = ly[i]; y <= ry[i]; ++y) {
			u[lx[i]][y] = 1;
			d[rx[i]][y] = 1;
		}

		isKey[lx[i]][ry[i]] = true;
		isKey[lx[i]][ly[i]] = true;
		isKey[rx[i]][ly[i]] = true;
		isKey[rx[i]][ry[i]] = true;
	}

	REP(i, 3005) {
		REP(j, 3005) {
			if (j) {
				l[i][j] += l[i][j - 1];
				r[i][j] += r[i][j - 1];
				u[i][j] += u[i][j - 1];
				d[i][j] += d[i][j - 1];
			}
		}
	}

	REP(i, 3005) REP(j, 3005) {
		if (i) dp1[i][j] += dp1[i - 1][j];
		if (j) dp1[i][j] += dp1[i][j - 1];
		if (i && j) dp1[i][j] -= dp1[i - 1][j - 1];
	}

	REP(diag, 7000) {
		int next = 0;
		SORT(diag2[diag]);
		SORT(diag1[diag]);
		vector<PII> &p = diag2[diag];
		TR(it, diag1[diag]) {
			while (next < p.size() && it->first > p[next].first) ++next;
			if (next == p.size()) break;

			int x1 = it->first, y1 = it->second;
			for (int k = next; k < p.size(); ++k) {
				int x2 = p[k].first, y2 = p[k].second;


				int sum = area(x1, y1, x2, y2);
				// cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = " << x2 << " y2 = " << y2 << " sum = " << sum << endl;
				if (sum == (x2 - x1 + 1) * (y2 - y1 + 1)) {
					VI rects;
					REP(t, n) {
						if (x1 <= lx[t] && x2 >= rx[t] && y1 <= ly[t] && y2 >= ry[t]) {
							rects.PB(t + 1);
						}
					}

					cout << "YES " << rects.size() << endl;
					REP(k, rects.size()) {
						if (k) cout << " ";
						cout << rects[k];
					}

					cout << endl;
					return 0;
				}
			}
		}
	}

	puts("NO");
	return 0;
}