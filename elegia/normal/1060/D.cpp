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

const int N = 100010;

int n;
ll ans;
int a[N], b[N];

int main() {
	scanf("%d", &n);
	ans = n;
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; ++i)
		ans += max(a[i], b[i]);
	printf("%lld\n", ans);
	return 0;
}