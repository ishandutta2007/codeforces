#include <bits/stdc++.h>
using namespace std;

int n, k, r;
int b[40], v[40], p[40];
long long ans;

vector <int> calc1(vector <int> a) {
	vector <int> na(n);
	for (int i = 0; i < n; i++) {
		na[i] = a[i] ^ b[i];
	}
	return na;
}

vector <int> calc2(vector <int> a) {
	vector <int> na(n);
	for (int i = 0; i < n; i++) {
		na[i] = a[p[i]] + r;
	}
	return na;
}

long long get_val(vector <int> a) {
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * v[i];
	}
	return ans;
}

void dfs(int now, vector <int> a, int lst = 0) {
	if (now % 2 == 0) ans = max(ans, get_val(a));
	if (now == 0) return ;
	if (lst != 1) dfs(now - 1, calc1(a), 1);
	dfs(now - 1, calc2(a), 2);
}

int main () {
	cin >> n >> k >> r;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	ans = -0x3f3f3f3f3f3f3f3f;
	dfs(k, a);
	cout << ans << endl;
	return 0;
}