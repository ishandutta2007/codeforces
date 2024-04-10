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

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main(int argc, char ** argv)
{
	int n;
	int g = 0, maxv = 0;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		g = gcd(g, v);
		maxv = max(maxv, v);
	}

	if ((maxv/g - n)%2 == 1)
		printf("Alice\n");
	else
		printf("Bob\n");

	return 0;
}