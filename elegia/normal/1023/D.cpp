#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 200010;

int n, q;
int a[N];
vector<int> modi[N];
int l[N], r[N];
priority_queue<int> que, dq;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	bool hvq = count(a + 1, a + n + 1, q) != 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (!hvq) {
				a[i] = q;
				hvq = true;
			}else
			if (a[i - 1] != 0)
				a[i] = a[i - 1];
		}
	}
	for (int i = n; i; --i)
		if (a[i] == 0)
			a[i] = a[i + 1];

	if (!hvq) {
		puts("NO");
		return 0;
	}

	for (int i = 1; i <= n; ++i) {
		if (!l[a[i]])
			l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = 1; i <= q; ++i)
		if (l[i]) {
			modi[l[i]].push_back(i);
			modi[r[i] + 1].push_back(-i);
		}

	for (int i = 1; i <= n; ++i) {
		for (int v : modi[i]) {
			if (v > 0)
				que.push(v);
			else
				dq.push(-v);
		}
		while (!dq.empty() && dq.top() == que.top()) {
			que.pop();
			dq.pop();
		}
		if (que.top() != a[i]) {
			puts("NO");
			LOG("a[%d]: %d %d\n", i, que.top(), a[i]);
			return 0;
		}
	}

	puts("YES");
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}