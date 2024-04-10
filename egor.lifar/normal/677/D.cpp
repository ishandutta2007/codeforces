#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;


int n, m;
int p;
int a[301][301];
int dp[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> dp1[90001];
vector<pair<int, int> > v[90001];


int chislo(int i, int j) {
	return i * 1000 + j;
}


int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			v[a[i][j]].push_back(make_pair(i, j));
		}
	}
	int logn = 1;
	while ((1 << logn) < n * m) {
		logn++;
	}
	for (int i = 1; i <= p; i++) {
		dp1[i].resize((int)v[i].size());
		for (int j = 0; j < (int)dp1[i].size(); j++) {
			if (i == 1) {
				dp1[i][j] = v[i][j].first + v[i][j].second;
			} else {
				dp1[i][j] = 1000000000;
			}
		}
		if (i != 1) {
			int s = n * m * logn;
			int s1 = (int)v[i - 1].size() * (int)v[i].size();
			if (s1 < s) {
				for (int j = 0; j < (int)dp1[i].size(); j++) {
					for (int k = 0; k < (int)v[i - 1].size(); k++) {
						dp1[i][j] = min(dp1[i][j], dp1[i - 1][k] + abs(v[i - 1][k].first - v[i][j].first) + abs(v[i - 1][k].second - v[i][j].second));
					}
				}
			} else {
				set<pair<int, int> > s;
				for (int k = 0; k < (int)v[i - 1].size(); k++) {
					s.insert(make_pair(dp1[i - 1][k], chislo(v[i - 1][k].first, v[i - 1][k].second)));
					dp[v[i - 1][k].first][v[i - 1][k].second] = dp1[i - 1][k];
				}
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						if (a[ii][jj] != i - 1) {	
							dp[ii][jj] = 1000000000;
						}
					}
				}
				while (!s.empty()) {
					pair<int, int> aa = *s.begin();
					s.erase(aa);
					int jj = aa.second % 1000;
					aa.second /= 1000;
					int ii = aa.second;
					for (int k = 0; k < 4; k++) {
						int i1 = ii + dx[k];
						int j1 = jj + dy[k];
						if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
							continue;
						}
						if (dp[i1][j1] > dp[ii][jj] + 1) {
							if (dp[i1][j1] != 1000000000) {
 								s.erase(make_pair(dp[i1][j1], chislo(i1, j1)));
 							}
							dp[i1][j1] = dp[ii][jj] + 1;
							s.insert(make_pair(dp[i1][j1], chislo(i1, j1)));
						} 
					} 
				}
				for (int j = 0; j < (int)dp1[i].size(); j++) {
					dp1[i][j] = dp[v[i][j].first][v[i][j].second];
				}
			}
		}
	}
	cout << dp1[p][0] << endl;
	return 0;
}