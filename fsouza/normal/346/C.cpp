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

typedef long long lint;

using namespace std;

int main(int argc, char ** argv)
{
	int n;
	vector <int> vals;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		vals.push_back(v);
	}

	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end())-vals.begin());
	n = vals.size();
	
	int a, b;

	scanf("%d %d", &a, &b);
	
	int bottom = a+1;

	for (int i = 0; i < n; i++) {
		bottom = min(bottom, ((b + vals[i]-1)/vals[i])*vals[i]);
	}

	int result = 0;

	while (a > b) {
		int best = 0;

		for (int i = 0; i < n; i++) {
			int r = a%vals[i];
			if (a-r >= b)
				best = max(best, r);
			else {
				vals[i] = vals[n-1];
				n--;
				i--;
			}
		}

		if (best > 0) {
			result ++;
			a -= best;
		} else if (a > bottom) {
			result ++;
			a --;
		} else {
			result += a-b;
			a = b;
		}
	}

	printf("%d\n", result);

	return 0;
}