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

const int N = 1000010;

int n;
char s[N];
map<int, int> mp;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	ll ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s + 1);
		int v = 0;
		for (char* p = s + 1; *p; ++p)
			v ^= 1 << (*p - 'a');
		ans += mp[v];
		for (int i = 0; i < 26; ++i)
			ans += mp[v ^ (1 << i)];
		++mp[v];
	}
	printf("%lld\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}