#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 310;

int n, m;
int cnt[N][2];
string s[N][N];
vector<pair<pair<int, int>, pair<int, int> > > modi;

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int nol_cl = clock();
#endif

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> s[i][j];
			reverse(s[i][j].begin(), s[i][j].end());
		}
	for (char c : s[0][0]) {
		++cnt[!(c - '0')][c - '0'];
		modi.emplace_back(make_pair(0, 0), make_pair(!(c - '0'), c - '0'));
	}
	for (char c : s[1][1]) {
		++cnt[!(c - '0')][c - '0'];
		modi.emplace_back(make_pair(1, 1), make_pair(!(c - '0'), c - '0'));
	}
	for (char c : s[0][1]) {
		modi.emplace_back(make_pair(0, 1), make_pair(c - '0', c - '0'));
	}
	for (char c : s[1][0]) {
		modi.emplace_back(make_pair(1, 0), make_pair(c - '0', c - '0'));
	}
	for (int i = 0; i < 2; ++i)
		for (int j = 2; j < m; ++j) {
			for (char c : s[i][j]) {
				++cnt[i][c - '0'];
				modi.emplace_back(make_pair(i, j), make_pair(i, c - '0'));
			}
		}
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
			for (char c : s[i][j]) {
				if (c - '0' == j) {
					modi.emplace_back(make_pair(i, j), make_pair(j, j));
				} else {
					++cnt[i][c - '0'];
					modi.emplace_back(make_pair(i, j), make_pair(i, !j));
				}
			}
		while (cnt[i][0]--)
			modi.emplace_back(make_pair(i, 0), make_pair(0, 0));
		while (cnt[i][1]--)
			modi.emplace_back(make_pair(i, 1), make_pair(1, 1));
		for (int j = 2; j < m; ++j) {
			for (char c : s[i][j]) {
				modi.emplace_back(make_pair(i, j), make_pair(i, c - '0'));
				modi.emplace_back(make_pair(i, c - '0'), make_pair(c - '0', c - '0'));
			}
		}
	}
	while (cnt[0][1]--)
		modi.emplace_back(make_pair(0, 1), make_pair(1, 1));
	while (cnt[1][0]--)
		modi.emplace_back(make_pair(1, 0), make_pair(0, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> s[i][j]; 
			reverse(s[i][j].begin(), s[i][j].end());
		}
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < m; ++j)
			for (char c : s[i][j]) {
				modi.emplace_back(make_pair(c - '0', c - '0'), make_pair(i, c - '0'));
				modi.emplace_back(make_pair(i, c - '0'), make_pair(i, j));
			}
	for (int i = 0; i < 2; ++i)
		for (int j = 2; j < m; ++j)
			for (char c : s[i][j])
				if (i == (c - '0'))
					modi.emplace_back(make_pair(i, i), make_pair(i, j));
				else {
					modi.emplace_back(make_pair(!i, !i), make_pair(i, !i));
					modi.emplace_back(make_pair(i, !i), make_pair(i, j));
				}
	for (int i = 2; i < n; ++i)
		for (int j = 0; j < 2; ++j)
			for (char c : s[i][j])
				if (j == (c - '0'))
					modi.emplace_back(make_pair(j, j), make_pair(i, j));
				else {
					modi.emplace_back(make_pair(!j, !j), make_pair(!j, j));
					modi.emplace_back(make_pair(!j, j), make_pair(i, j));
				}
	for (char c : s[0][0]) {
		modi.emplace_back(make_pair(c - '0', c - '0'), make_pair(0, 1));
		modi.emplace_back(make_pair(0, 1), make_pair(0, 0));
	}
	for (char c : s[1][1]) {
		modi.emplace_back(make_pair(c - '0', c - '0'), make_pair(0, 1));
		modi.emplace_back(make_pair(0, 1), make_pair(1, 1));
	}
	for (char c : s[0][1]) {
		modi.emplace_back(make_pair(c - '0', c - '0'), make_pair(0, 1));
	}
	for (char c : s[1][0]) {
		modi.emplace_back(make_pair(c - '0', c - '0'), make_pair(1, 0));
	}
	
	printf("%lu\n", modi.size());
	for (const auto pr : modi)
		printf("%d %d %d %d\n", pr.first.first + 1, pr.first.second + 1, pr.second.first + 1, pr.second.second + 1);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}