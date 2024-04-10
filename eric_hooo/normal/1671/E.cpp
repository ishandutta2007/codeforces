#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n, N, ans;
char s[1 << 18 | 10];

string Solve(int now) {
	if (now >= N) return "";
	string ls = Solve(now << 1), rs = Solve(now << 1 | 1);
	if (ls != rs) ans = ans * 2 % mod;
	if (ls > rs) swap(ls, rs);
	return string(1, s[now]) + ls + rs;
}

int main() {
	scanf("%d", &n), N = 1 << n;
	scanf("%s", s + 1);
	ans = 1, Solve(1);
	printf("%d\n", ans);
	return 0;
}