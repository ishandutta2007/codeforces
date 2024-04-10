#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_e"

const double pi = acos(-1.0);
const double eps = 1e-8;
const int size = 400;
const double inf = 1e9;

int n, k;
int h[size][size];
double ans[size];
double cross[size][size];
bool oh[size][size];

inline double getvalue(int nm, int p, double x) {
	return h[nm][p] + (h[nm][p + 1] - h[nm][p]) * x;
}

double cv[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++)
			scanf("%d", &h[i][j]);
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++)
			for (int p = 0; p < n; p++)
				oh[j][p] = false;
		for (int j = 0; j < n; j++)
			for (int p = j + 1; p < n; p++) {
				if (h[p][i + 1] - h[p][i] == h[j][i + 1] - h[j][i]) {
					if (h[p][i] >= h[j][i]) {
						oh[j][p] = true;
						oh[p][j] = false;
					} else {
						oh[j][p] = false;
						oh[p][j] = true;
					}
				} else {
					double a = h[j][i];
					double b = h[j][i + 1] - h[j][i];
					double c = h[p][i];
					double d = h[p][i + 1] - h[p][i];
					cross[j][p] = (a - c) / (d - b);
					cross[p][j] = cross[j][p];
				}
			}

		vector <pair <int, int> > vec;
		for (int j = 0; j < n; j++)
			vec.pb(mp(h[j][i + 1] - h[j][i], j));
		sort(vec.begin(), vec.end());

		ans[0] += (h[0][i] + h[0][i + 1]) / 2.0;
		cv[0] = (h[0][i] + h[0][i + 1]) / 2.0;
		for (int j = 1; j < n; j++) {
			vector <int> st;
			vector <double> mom;

			for (int p = 0; p < n; p++) {
				if (vec[p].sc <= j) {
					while (!st.empty()) {
						if (oh[st.back()][vec[p].sc] || (!oh[vec[p].sc][st.back()] && cross[st.back()][vec[p].sc] < mom.back() + eps)) {
							st.pop_back();
							mom.pop_back();
						} else {
							break;
						}
					}
					if (st.empty()) {
						st.pb(vec[p].sc);
						mom.pb(0.0);
					} else {
						if (!oh[vec[p].sc][st.back()]) {
							mom.pb(cross[st.back()][vec[p].sc]);
							st.pb(vec[p].sc);
							
						}
					}
				}
			}

			while (mom.back() > 1.0 - eps) {
				mom.pop_back();
				st.pop_back();
			}

			mom.pb(1.0);
			cv[j] = 0.0;
			for (int p = 0; p < (int) st.size(); p++)
				cv[j] += (mom[p + 1] - mom[p]) * (getvalue(st[p], i, mom[p]) + getvalue(st[p], i, mom[p + 1])) / 2.0;
			ans[j] += cv[j] - cv[j - 1];

			/*
			for (int p = 0; p < (int) st.size(); p++) {
				if (!oh[j][st[p]]) {
					if (cross[j][st[p]] > mom[p] - eps && cross[j][st[p]] < mom[p + 1] + eps) {
						if (h[
					} else {
						double lv = getvalue(j, i, mom[p]);
						double rv = getvalue(j, i, mom[p + 1]);
						double cv = getvalue(st[p], i, mom[p]);
						if (cv < lv) {
							ans[j] += (cv - lv + getvalue(st[p], i, mom[p + 1]) - rv) / 2.0;
						}
					}
				}
			}
			*/
		}
	}

	cout.precision(20);
	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}