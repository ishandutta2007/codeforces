#include <bits/stdc++.h>

#define lli long long int
#define ii pair<int, int>
#define ll pair<lli, lli>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

lli memo[25][25];

lli combine(lli n, lli r) {
	lli ret;
	if (r > n)
		return 0;
	if ((r == 0) || (n == r))
		return 1;
	if (memo[n][r] != -1)
		return memo[n][r];
	ret = combine(n - 1, r) + combine(n - 1, r - 1);
	memo[n][r] = ret;
	return ret;
}

int main() {
	lli tc, n, cnt, batas, len, temp, ans1, ans2;
	vector<lli> v;
	scanf("%lld", &tc);
	memset(memo, -1, sizeof memo);
	while (tc--) {
		scanf("%lld", &n);
		cnt = 2;
		v.clear();
		while (n) {
			v.pb(n % cnt);
			n /= cnt;
			cnt++;
		}
		cnt--;
		sort(v.rbegin(), v.rend());
		ans1 = ans2 = 1;
		for (lli i = 0; i < (cnt - 1); i++) {
			batas = i;
			while (batas + 1 < cnt - 1) {
				if (v[batas] != v[batas + 1])
					break;
				batas++;
			}
			len = batas - i + 1;
			temp = cnt - max(1LL, v[i]) - i;
			ans1 *= combine(temp, len);
			i = batas;
		}
		if (v.back() != 0)
			ans2 = 0;
		else {
			v.pop_back();
			cnt--;
			//printf("size = %lld cnt = %lld\n", (lli) v.size(), cnt);
			for (lli i = 0; i < (cnt - 1); i++) {
				batas = i;
				while (batas + 1 < cnt - 1) {
					if (v[batas] != v[batas + 1])
						break;
					batas++;
				}
				len = batas - i + 1;
				temp = cnt - max(1LL, v[i]) - i;
				//printf("temp = %lld len = %lld\n", temp, len);
				ans2 *= combine(temp, len);
				i = batas;
			}
		}
		//printf("%lld %lld\n", ans1, ans2);
		printf("%lld\n", ans1 - ans2 - 1);
	}
	return 0;
}