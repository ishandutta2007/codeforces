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

#define MAXN 2000

typedef long long lint;

using namespace std;

int A[MAXN];
int tree[4*MAXN];

void build_tree(int n, int l, int r) {
	tree[n] = r-l+1;
	if (l != r) {
		build_tree(2*n+1, l, (l+r)/2);
		build_tree(2*n+2, (l+r)/2+1, r);
	}
}

void tree_update(int pos, int val, int n, int l, int r)
{
	tree[n] += val;

	if (l != r) {
		int m = (l+r)/2;
		if (pos <= m) tree_update(pos, val, 2*n+1, l, m);
		else tree_update(pos, val, 2*n+2, m+1, r);
	}
}

int tree_query(int a, int b, int n, int l, int r)
{
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[n];
	int m = (l+r)/2;
	return tree_query(a, b, 2*n+1, l, m) + tree_query(a, b, 2*n+2, m+1, r);
}

int dp[2][MAXN+1];

int solve(vector <pair <int, int> > many)
{
	const int n = many.size();
	int now = 0, prev = 1;

	for (int j = 1; j <= n; j++)
		dp[prev][j] = INF;
	dp[prev][0] = 0;

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j <= n; j++) dp[now][j] = INF;

		for (int j = 0; j < n-i; j++) {
			dp[now][j] = min(dp[now][j], dp[prev][j] + many[i].second + j);
			dp[now][j+1] = min(dp[now][j+1], dp[prev][j] + many[i].first);
		}

		swap(now, prev);
	}

	int result = INF;

	for (int j = 0; j <= n; j++)
		result = min(result, dp[prev][j]);

	return result;
}

int main(int argc, char ** argv)
{
	int n;
	vector <pair <int, int> > vals;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		A[i] = abs(A[i]);
		vals.push_back(make_pair(A[i], i));
	}

	sort(vals.begin(), vals.end());

	build_tree(0, 0, n-1);

	int result = 0;

	for (int i = n-1, j = i; i >= 0; i = j-1) {
		while (j-1 >= 0 && vals[j-1].first == vals[i].first) j--;

		vector <pair <int, int> > many;

		for (int k = j; k <= i; k++)
			tree_update(vals[k].second, -1, 0, 0, n-1);

		for (int k = j; k <= i; k++)
			many.push_back(make_pair(tree_query(0, vals[k].second, 0, 0, n-1),
						 tree_query(vals[k].second, n-1, 0, 0, n-1)));

//		printf("Val = %d, ret = %d\n", vals[j

		result += solve(many);
	}

	printf("%d\n", result);

	return 0;
}