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
#define MAXN 5000
#define MAXM 5000

typedef long long lint;

using namespace std;

int n, nbad;
int a[MAXN], pgcd[MAXN], bad[MAXM];

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int nfact(int val) {
	int ret = 0;

	while (val%2 == 0) {
		ret++;
		val /= 2;
	}

	for (int x = 3; x*x <= val; x += 2)
		while (val%x == 0) {
			ret++;
			val /= x;
		}

	if (val > 1) ret++;

	return ret;
}

int score(int val) {
	int ret = 0;

	for (int i = 0; i < nbad; i++)
		while (val % bad[i] == 0) {
			val /= bad[i];
			ret--;
		}

	ret += nfact(val);

	return ret;
}

int main(int argc, char ** argv)
{
	scanf("%d %d", &n, &nbad);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < nbad; i++) scanf("%d", &bad[i]);
	
	pgcd[0] = a[0];
	for (int i = 1; i < n; i++) pgcd[i] = gcd(pgcd[i-1], a[i]);

	int delta = 0, divby = 1;

	for (int i = n-1; i >= 0; i--) {
		int g = pgcd[i] / divby;
		
		int sc = score(g);
		if (sc < 0) {
			delta -= sc * (i+1);
			divby *= g;
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) result += score(a[i]);
	result += delta;

	printf("%d\n", result);

	return 0;
}