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
#define MAXV 110

typedef long long lint;

using namespace std;

int mos[MAXV+1];

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

	memset(mos, 0, sizeof(mos));
	mos[0] = n;

	for (int i = 0; i < n; i++) {
		int v = vals[i];

		for (int j = v; j >= 0; j--) {
			if (mos[j] > 0) {
				mos[j] --;
				mos[j+1] ++;
				break;
			}
		}
	}

	printf("%d\n", n - mos[0]);

	return 0;
}