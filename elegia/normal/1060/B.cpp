#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int calc(ll x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int cnt(ll x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
	ll n;
	ll g = 1;
	scanf("%lld", &n);
	while (g * 10 - 1 <= n)
		g *= 10;
	printf("%d\n", calc(g - 1) + calc(n - g + 1));
	return 0;
}