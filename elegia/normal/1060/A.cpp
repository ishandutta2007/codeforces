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

int n;

char s[110];

int main() {
	scanf("%d%s", &n, s + 1);
	int cnt = count(s + 1, s + n + 1, '8');
	int ans = min(cnt, n / 11);
	printf("%d\n", ans);
	return 0;
}