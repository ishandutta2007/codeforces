#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 100005;
int T, n, a[MAXN], lft[MAXN], rgt[MAXN];
set<int> ss;

void del(int x) {
	lft[rgt[x]] = lft[x];
	rgt[lft[x]] = rgt[x];
}

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) {
			lft[i] = i - 1, rgt[i] = i + 1;
			if (i < n && __gcd(a[i], a[i + 1]) == 1) ss.insert(i);
		}
		rgt[0] = 1, lft[n + 1] = n;
		int l = 1;
		vector<int> ans;
		while ((!ss.empty() || __gcd(a[rgt[0]], a[lft[n + 1]]) == 1) && rgt[0] != lft[n + 1]) {
//			printf("%d\n", (int)ss.size());
			auto it = ss.lower_bound(l);
			if (it == ss.end()) {
				if (l <= lft[n + 1] && __gcd(a[rgt[0]], a[lft[n + 1]]) == 1) {
					ans.push_back(rgt[0]);
					if (ss.find(rgt[0]) != ss.end()) ss.erase(rgt[0]);
					del(rgt[0]);
					l = 1;
					continue;
				} else {
					l = 1;
					it = ss.lower_bound(l);
				}
			}
			if (ss.empty()) continue;
			int x = *it, y = rgt[x];
			ans.push_back(y);
			if (ss.find(y) != ss.end()) ss.erase(y);
			del(y);
			ss.erase(it);
			if (rgt[x] <= n && __gcd(a[x], a[rgt[x]]) == 1) ss.insert(x);
			l = rgt[x];
		}
		if (rgt[0] == lft[n + 1] && a[rgt[0]] == 1) ans.push_back(rgt[0]);
		printf("%d ", (int)ans.size());
		for (int i : ans) printf("%d ", i);
		puts("");
	}
	return 0;
}