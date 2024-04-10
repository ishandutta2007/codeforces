#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		static vector <pll> a; a.clear();
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			int c = 1;
			while (x % m == 0) x /= m, c *= m;
			if (!a.size() || a.back().fi != x) a.push_back(pll(x, c));
			else a.back().se += c;
		}
		static vector <pll> b; b.clear();
		int k; scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			int x; scanf("%d", &x);
			int c = 1;
			while (x % m == 0) x /= m, c *= m;
			if (!b.size() || b.back().fi != x) b.push_back(pll(x, c));
			else b.back().se += c;
		}
		if (a == b) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}