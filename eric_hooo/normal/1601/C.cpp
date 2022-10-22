#include <bits/stdc++.h>
using namespace std;

int a[1000010], b[1000010];
int n, m;
vector <int> all;
int T[1000010];
priority_queue <int> L;
priority_queue <int, vector <int>, greater <int> > R;

void modify(int x, int v) {
	while (x <= 1000005) T[x] += v, x += x & -x;
}

int query(int x) {
	int sum = 0;
	while (x) sum += T[x], x -= x & -x;
	return sum;
}

long long Calc() {
	all.clear();
	for (int i = 0; i < n; i++) {
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 1; i <= all.size(); i++) {
		T[i] = 0;
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
		ans += i - query(x);
		modify(x, 1);
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &b[i]);
		}
		sort(b, b + m);
		while (L.size()) L.pop();
		for (int i = 0; i < n + 5; i++) {
			L.push(0), R.push(m);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int l = lower_bound(b, b + m, a[i]) - b, r = upper_bound(b, b + m, a[i]) - b;
			if (L.top() <= r) L.push(l);
			else {
				L.push(l);
				int x = L.top();
				ans += x - r;
				L.pop(), L.push(r);
			}
		}
		ans += Calc();
		printf("%lld\n", ans);
	}
	return 0;
}