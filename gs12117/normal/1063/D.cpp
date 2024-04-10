#include<cstdio>
long long int n, m;
long long int d;
int main() {
	long long int pl, pr;
	scanf("%lld%lld%lld%lld", &n, &pl, &pr, &m);
	d = pr - pl;
	if (d < 0)d += n;
	d++;
	long long int ans = -1;
	if (m <= 2 * d&&m >= d) {
		ans = n - (2 * d - m);
		if (ans < n)ans++;
	}
	for (int rot = 1; rot < 1000000; rot++) {
		long long int tans = (m - d) / rot - n;
		if (tans >= n)tans = n;
		int cnt = 0;
		while (tans >= 0) {
			cnt++;
			if (cnt > 10)break;
			long long int sans = m - d - (n + tans)*rot;
			if (sans > tans || sans > d)break;
			if (d - sans > n - tans + 1) {
				long long int r = (d - sans) - (n - tans + 1);
				r /= (rot + 1);
				if (r > 3)tans -= r - 3;
				tans--;
				continue;
			}
			if (tans > ans)ans = tans;
			tans--;
		}
	}
	if (n < 1000000) {
		for (long long int tans = n; tans >= 0; tans--) {
			long long int rot = (m - d) / (n + tans);
			int flg = 0;
			int cnt = 0;
			while (rot >= 1) {
				cnt++;
				if (cnt > 10)break;
				long long int sans = m - d - (n + tans)*rot;
				if (sans > tans || sans > d)break;
				if (d - sans > n - tans + 1) {
					rot--;
					continue;
				}
				flg = 1;
				break;
			}
			if (flg == 0)continue;
			if (tans > ans)ans = tans;
			break;
		}
	}
	printf("%lld", ans);
	return 0;
}