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

set <int> used;
int next;

pair <int, int> next_coprimes() {
	while (used.find(next) != used.end() || used.find(next+1) != used.end()) next++;
	return make_pair(next, next+1);
}

int main(int argc, char ** argv)
{
	int n, k;

	scanf("%d %d", &n, &k);
	int minv = n/2;

	next = 50;

	if (k < minv || (n < 2 && k > 0))
		printf("-1\n");
	else {
		vector <int> ret;

		if (n >= 2) {
			ret.push_back(k - minv + 1);
			used.insert(k - minv + 1);
			ret.push_back((k - minv + 1) * 2);
			used.insert((k - minv + 1) * 2);
		}
		
		for (int i = 0; i < n/2-1; i++) {
			pair <int, int> ab = next_coprimes();
			ret.push_back(ab.first);
			used.insert(ab.first);
			ret.push_back(ab.second);
			used.insert(ab.second);
		}

		if (n%2) {
			pair <int, int> ab = next_coprimes();
			ret.push_back(ab.first);
			used.insert(ab.first);
		}

		for (int i = 0; i < n; i++) {
			if (i-1 >= 0) printf(" ");
			printf("%d", ret[i]);
		}
		printf("\n");
	}

	return 0;
}