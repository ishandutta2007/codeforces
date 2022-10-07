#include<cstdio>
#include<vector>
const long long int mod = 998244353;
int n;
std::vector<int> el[200100];
struct st {
	long long int a, b, c;
	st operator+(st&r) {
		st res;
		res.a = (a*r.a) % mod;
		res.b = (c*r.b + b * r.a) % mod;
		res.c = (c*r.c) % mod;
		return res;
	}
};
st dp[200100];
int chk[200100];
void dfs(int x) {
	chk[x] = 1;
	st l, r;
	l.a = 1;
	l.b = 0;
	l.c = 1;
	r.a = 1;
	r.b = 0;
	r.c = 1;
	int c = 0;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] == 1) {
			c = 1;
			continue;
		}
		dfs(y);
		if (c == 0)l = l + dp[y];
		else r = r + dp[y];
	}
	if (c == 0)dp[x] = l;
	else {
		dp[x].a = (l.c*r.b + l.b*r.a + l.c*r.c) % mod;
		dp[x].b = (l.c*r.b + l.c*r.c) % mod;
		dp[x].c = (l.c*r.a + l.b*r.a) % mod;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		el[x].push_back(y);
		el[y].push_back(x);
	}
	dfs(1);
	printf("%lld", (dp[1].b + dp[1].c) % mod);
	return 0;
}