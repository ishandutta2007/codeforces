#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int MAXN = 100005;
multiset<int> s;
int a[MAXN], f[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int m = 0;
	for (int i = 1; i <= n; i++) if (a[i] != a[i - 1]) a[++m] = a[i];
	n = m;
	for (int i = 1; i <= n; i++) s.insert(f[i] = 1e9);
	s.insert(0);
	for (int i = 1; i <= n; i++) {
		int t = *s.begin();
		if (t == f[a[i]]) {
			s.erase(s.find(f[a[i - 1]]));
			s.insert(t - 1);
			f[a[i - 1]] = t - 1;
		} else if (f[a[i - 1]] > t) {
			s.erase(s.find(f[a[i - 1]]));
			s.insert(f[a[i - 1]] = t);
		}
	}
	printf("%d\n", *s.begin() + n);
	return 0;
}