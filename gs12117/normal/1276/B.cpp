#include<cstdio>
#include<algorithm>
int n, m, a, b;
int el[500100][2];
struct st {
	int x, y;
	bool operator<(const st&r)const {
		return x < r.x || (x == r.x&&y < r.y);
	}
};
st sl[200100];
int uft[200100];
int uftc[200100];
int sa[200100];
int sb[200100];
long long int ans;
int uftf(int x) {
	if (x == uft[x])return x;
	return uft[x] = uftf(uft[x]);
}
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &el[i][0], &el[i][1]);
		}
		ans = 1LL * (n - 2) * (n - 2);
		for (int i = 1; i <= n; i++) {
			uft[i] = i;
		}
		for (int i = 0; i < m; i++) {
			if (el[i][0] == a || el[i][1] == a)continue;
			int x = el[i][0];
			int y = el[i][1];
			x = uftf(x);
			y = uftf(y);
			if (x != y) {
				uft[y] = x;
			}
		}
		for (int i = 1; i <= n; i++) {
			uftc[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b)uftc[uftf(i)]++;
		}
		for (int i = 1; i <= n; i++) {
			ans -= 1LL * uftc[i] * uftc[i];
			sa[i] = uftf(i);
		}
		for (int i = 1; i <= n; i++) {
			uft[i] = i;
		}
		for (int i = 0; i < m; i++) {
			if (el[i][0] == b || el[i][1] == b)continue;
			int x = el[i][0];
			int y = el[i][1];
			x = uftf(x);
			y = uftf(y);
			if (x != y) {
				uft[y] = x;
			}
		}
		for (int i = 1; i <= n; i++) {
			uftc[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b)uftc[uftf(i)]++;
		}
		for (int i = 1; i <= n; i++) {
			ans -= 1LL * uftc[i] * uftc[i];
			sb[i] = uftf(i);
		}
		int p = 0;
		for (int i = 1; i <= n; i++) {
			if (i != a && i != b) {
				sl[p].x = sa[i];
				sl[p].y = sb[i];
				p++;
			}
		}
		std::sort(sl, sl + p);
		for (int i = 0; i < p;) {
			int j = i;
			for (; j < p&&sl[j].x == sl[i].x&&sl[j].y == sl[i].y; j++);
			ans += 1LL * (j - i)*(j - i);
			i = j;
		}
		printf("%lld\n", ans/2);
	}
	return 0;
}