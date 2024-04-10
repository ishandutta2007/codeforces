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

const int N = 200010, X = 2000010, P = 1000000007;

int n, pc, ind;
bool vis[X], chose[N];
int a[N], l[X], pr[N], fc[X];
int tag[X];

void apply(int x) {
	int lst = 0, cnt = 0;
	while (x != 1) {
		int pp = fc[x];
		x /= pp;
		if (pp == lst) {
			++cnt;
		} else {
			if (cnt >= l[lst]) {
				l[lst] = cnt;
				tag[lst] = ind;
			}
			cnt = 1;
			lst = pp;
		}
	}
	if (cnt >= l[lst]) {
		l[lst] = cnt;
		tag[lst] = ind;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	for (int x = 2; x < X; ++x) {
		if (!vis[x]) {
			fc[x] = x;
			pr[++pc] = x;
		}
		for (int i = 1; x * pr[i] < X; ++i) {
			vis[x * pr[i]] = true;
			fc[x * pr[i]] = pr[i];
			if (x % pr[i] == 0)
				break;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i) {
		ind = i;
		if (!l[a[i]])
			apply(a[i]);
		else
			apply(a[i] - 1);
	}
	int ans = 1;
	for (int i = 1; i <= pc; ++i)
		while (l[pr[i]]--)
			ans = ans * (ll)pr[i] % P;
	for (int x = 1; x < X; ++x)
		chose[tag[x]] = true;
	ans = (ans + (count(chose + 1, chose + n + 1, true) != n)) % P;
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}