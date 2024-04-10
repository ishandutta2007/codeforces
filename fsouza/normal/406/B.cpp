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

const int s = 1000000;

bool first;

char used[s+1];
int remain;

void use(int v) {
	used[v] = 1;
	remain--;

	if (!first) printf(" ");
	printf("%d", v);
	first = false;
}

int main(int argc, char ** argv)
{
	memset(used, 0, sizeof(used));
	first = true;

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		used[x] = 1;
	}

	int m = n;
	printf("%d\n", m);

	remain = m;

	for (int v = 1; v <= s; v++) {
		if (used[v] && !used[s+1-v]) {
			use(s+1-v);
		}
	}

	assert(remain%2 == 0);

	for (int v = 1; v <= s; v++) {
		if (remain > 0 && !used[v]) {
			use(v);
			use(s+1-v);			
		}
	}

	printf("\n");

	return 0;
}