#include <set>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
#include <queue> 
#include <cmath>

using namespace std;
#define pb push_back 
#define left hsfkasfhasfuckajsfkjsaf
#define right ajadslfkjasdklfj
#define distance fuck_this_shit
#define REP(i, n) for (int i = 0; i < n; ++i)
const int inf = 1000000000;
int L[8005], R[8005];
int P[8005][5];
vector < int > all;
long long c1[20005];
int get(int pos) {
	int L = 0, R = all.size();
	while (L + 1 < R) {
		int middle = (L + R) / 2;
		if (all[middle] > pos) R = middle; else L = middle;
	}
	return L;
}
int main() {
//	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	scanf("%d", &L[0]);
	P[0][0] = L[0], P[0][1] = L[0];
	all.push_back(P[0][0]);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &L[i], &R[i]);
		P[i][0] = L[i], P[i][1] = R[i];
		all.push_back(L[i]); all.push_back(R[i]);
	}

	long long INF = 1LL * inf * inf;
	sort(all.begin(), all.end());
	int m = all.size();
	for (int i = 0; i < m; ++i) {
		c1[i] = INF;
	}
	c1[get(L[0])] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			c1[j] = min(c1[j - 1] + all[j] - all[j - 1], c1[j]);
		}

		for (int j = m - 2; j >= 0; --j) {
			c1[j] = min(c1[j], c1[j + 1] + all[j + 1] - all[j]);
		}

		for (int j = 0; j < m; ++j) {
			int pos = all[j];
			int value = 0;
			if (pos < P[i][0])
				value = P[i][0] - pos;
			else if (pos > P[i][1])
				value = pos - P[i][1];
			c1[j] += value;
		}
	}
	long long ans = INF;
	for (int i = 0; i < m; ++i) {
		ans = min(ans, c1[i]);
	}
	cout << ans << endl;
	return 0;
}