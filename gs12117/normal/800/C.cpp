#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int a[200100];
int dp[200100];
int back[200100];
int achk[200100];
int ers[200100];
int ephi[200100];
vector<int> vdiv[200100];
int gcd(int x, int y) {
	if (x == 0)return y;
	return gcd(y%x, x);
}
long long int mpow(int x, int y, int mod) {
	if (y == 0)return 1 % mod;
	long long int r = mpow(x, y / 2, mod);
	r *= r;
	r %= mod;
	if (y % 2 == 1)r *= x;
	r %= mod;
	return r;
}
long long int minv(int x, int mod) {
	return mpow(x, ephi[mod] - 1, mod);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		achk[a[i]] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (achk[i] == 0)vdiv[gcd(i, m)].push_back(i);
	}
	ephi[1] = 1;
	for (int i = 2; i <= m; i++) {
		if (ers[i] == 0) {
			for (int j = i; j <= m; j += i) {
				ers[j] = i;
			}
		}
		if (i / ers[i] % ers[i] == 0)ephi[i] = ephi[i / ers[i]] * ers[i];
		else ephi[i] = ephi[i / ers[i]] * (ers[i] - 1);
	}
	for (int i = 1; i <= m; i++) {
		dp[i] += vdiv[i].size();
		for (int j = i * 2; j <= m; j += i) {
			if (dp[i] > dp[j]) {
				dp[j] = dp[i];
				back[j] = i;
			}
		}
	}
	printf("%d\n", dp[m]);
	vector<int> ans;
	int p = m;
	while (vdiv[p].size() == 0)p = back[p];
	int d = vdiv[p][0];
	while (p != 0) {
		int nd;
		for (int i = 1; i < vdiv[p].size(); i++) {
			nd = vdiv[p][i];
			ans.push_back(d / p*minv(nd / p, m / p) % (m / p));
			d = nd;
		}
		if (back[p] == 0) {
			ans.push_back(d);
		}
		else {
			nd = vdiv[back[p]][0];
			ans.push_back(d / back[p] * minv(nd / back[p], m / back[p]) % (m / back[p]));
			d = nd;
		}
		p = back[p];
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	return 0;
}