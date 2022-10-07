#include<stdio.h>
#include<set>
int m;
int a[100100];
int b[100100];
int c[200100];
int ansa, ansb;
long long int mpow(int x, int y) {
	if (y == 0)return 1;
	long long int res = mpow(x, y / 2);
	res *= res;
	res %= m;
	if (y % 2 == 1)res *= x;
	res %= m;
	return res;
}
long long int minv(int x) {
	return mpow(x, m - 2);
}
void solve(int n) {
	if (n == 0) {
		ansa = 0;
		ansb = 1;
		return;
	}
	if (n == 1) {
		ansa = a[0];
		ansb = 1;
		return;
	}
	std::set<int> s;
	for (int i = 0; i < n; i++) {
		b[i] = (a[i] + m - a[0]) % m;
		s.insert(b[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.find((b[i] + b[1]) % m) == s.end()) {
			cnt++;
		}
	}
	ansb = b[1] * minv(cnt) % m;
	std::set<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(a[i]);
	}
	ansa = -1;
	for (int i = 0; i < n; i++) {
		if (st.find((a[i] + m - ansb) % m) == st.end()) {
			if (ansa == -1)ansa = a[i];
			else {
				ansa = -1;
				return;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (n * 2 > m) {
		for (int i = 0; i < n; i++) {
			c[a[i]] = 1;
		}
		int ap = 0;
		for (int i = 0; i < m; i++) {
			if (c[i] == 0) {
				a[ap] = i;
				ap++;
			}
		}
		solve(m - n);
		if (ansa == -1) {
			printf("-1");
			return 0;
		}
		ansb = m - ansb;
		ansb %= m;
		ansa = ansa + ansb;
		ansa %= m;
		printf("%d %d", ansa, ansb);
	}
	else {
		solve(n);
		if (ansa == -1) {
			printf("-1");
			return 0;
		}
		printf("%d %d", ansa, ansb);
	}
	return 0;
}