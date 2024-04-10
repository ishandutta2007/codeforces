#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 2005;
int T, n;
bool f[MAXN];

int ask(vector<int> &a, vector<int> &b) {
	printf("? %d %d\n", (int)a.size(), (int)b.size());
	for (int i : a) printf("%d ", i);
	puts("");
	for (int i : b) printf("%d ", i);
	puts("");
	fflush(stdout);
	int t; scanf("%d", &t);
	return t;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int p = 0, q = 0;
		for (int i = 1; i <= n; i++) {
			vector<int> a, b;
			a.push_back(i);
			for (int j = i + 1; j <= n; j++) b.push_back(j);
			if ((q = ask(a, b)) != 0) {
				p = i;
				break;
			}
		}
		q &= 1;
		for (int i = 1; i <= n; i++) f[i] = true;
		f[p] = false;
		for (int i = p + 1; i < n; i++) {
			vector<int> a, b;
			a.push_back(p);
			b.push_back(i);
			if (ask(a, b) != 0) f[i] = false, q ^= 1;
		}
		f[n] = q == 0;
		int l = 0, r = p;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			vector<int> a, b;
			a.push_back(p);
			for (int j = mid; j < p; j++) b.push_back(j);
			if (ask(a, b) != 0) l = mid;
			else r = mid;
		}
		if (l > 0) f[l] = false;
		vector<int> ans;
		for (int i = 1; i <= n; i++) if (f[i]) ans.push_back(i);
		printf("! %d", (int)ans.size());
		for (int i : ans) printf(" %d", i);
		puts("");
		fflush(stdout);
	}
	return 0;
}