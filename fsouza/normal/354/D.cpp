#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

#define INF 1000000000
#define MAXN 100000

using namespace std;

int _dp[2][2][MAXN+1]; inline int &dp(int x, int used, int cut) {return _dp[x&1][used][cut];}

int main(int argc, char ** argv)
{
	int n, k;
	vector <pair <int, int> > cells;

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		y--, x--;
		cells.push_back(make_pair(x, n-1-y));
	}
	sort(cells.rbegin(), cells.rend());

	int ncell = cells.size(), nextcell = 0, maxcut = min((int)sqrt(6*k), n);

	dp(n, 0, 0) = 0;
	for (int x = n-1; x >= 0; x--) {
		int manyup = 0;
		while (nextcell < ncell && cells[nextcell].first > x) nextcell ++;

		dp(x, 1, min(maxcut, n-x)+1) = INF;
		for (int cut = min(maxcut, n-x); cut >= 0; cut--) {
			while (nextcell < ncell && cells[nextcell].first == x && cells[nextcell].second >= cut) manyup++, nextcell++;
			dp(x, 1, cut) = min(dp(x+1, 0, max(0, cut-1)) + 3*manyup, dp(x, 1, cut+1) + (cut+1));
			dp(x, 0, cut) = min(dp(x+1, 0, max(0, cut-1)) + 3*manyup, dp(x, 1, cut) + 2 + cut*(cut+1)/2);
		}
	}
	printf("%d\n", dp(0, 0, 0));

	return 0;
}