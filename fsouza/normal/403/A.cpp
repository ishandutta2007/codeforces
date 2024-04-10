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

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int t = 0; t < ntest; t++) {
		int n, p;

		scanf("%d %d", &n, &p);

		int remain = 2*n+p;

		for (int i = 0; i < n; i++)
			for (int d = 1; d <= 2; d++) {
				const int j = (i+d)%n;

				printf("%d %d\n", i+1, j+1);
				remain--;
			}

		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++) {
				int diff = min(j-i, n-(j-i));
				if (diff > 2 && remain > 0) {
					printf("%d %d\n", i+1, j+1);
					remain--;
				}
			}
	}

	return 0;
}