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

#define INF (INT_MAX/2)
#define MAXN 1000

typedef long long lint;

using namespace std;

int m[MAXN][MAXN];

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			scanf("%d", &m[y][x]);

	int ret = 0;

	for (int i = 0; i < n; i++)
		ret = (ret + m[i][i]) % 2;

	int nq;

	scanf("%d", &nq);

	for (int q = 0; q < nq; q++) {
		int op;
		scanf("%d", &op);
		if (op == 3) printf("%d", ret);
		else {
			int i;
			scanf("%d", &i);
			
			ret = (ret - m[i][i] + 2) % 2;
			m[i][i] ^= 1;
			ret = (ret + m[i][i] + 2) % 2;
		}
	}
	printf("\n");

	return 0;
}