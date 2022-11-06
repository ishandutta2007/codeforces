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
#define MAXN 300100

typedef long long lint;

using namespace std;

const int maxv = 1000010;

int a[MAXN];
int manyof[maxv+3];
int sum[maxv+3];

int query(int a, int b)
{
	b = min(b, maxv);
	
	if (a > b) return 0;

	int ret = sum[b];
	if (a-1 >= 0) ret -= sum[a-1];
	return ret;
}

int main(int argc, char ** argv)
{
	int n, k;

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i <= maxv; i++) manyof[i] = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		manyof[a[i]] ++;
	}

	sum[0] = manyof[0];
	for (int i = 1; i <= maxv; i++)
		sum[i] = sum[i-1] + manyof[i];

	for (int gcd = maxv; gcd > 0; gcd--) {
		int manyok = 0;
		
		for (int q = 1; q*gcd <= maxv; q++) {
			int maxr = min(gcd-1, k);
			manyok += query(q*gcd, q*gcd+maxr);
		}

		if (manyok == n) {
			printf("%d\n", gcd);
			break;
		}
	}

	return 0;
}