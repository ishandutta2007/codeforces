#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 100228;
long long n, m, sum1;
int ans[MAXN], cnt[MAXN], List[MAXN];
queue<pair<pair<long long, long long>, long long> > st[MAXN];
vector<long long> a, pr, b[MAXN], pos, d[MAXN], vec[MAXN];


long long evklid(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	if (a < b) {
 		return evklid(b, a, y, x);
	}
	long long xx = 0, yy = 0;
	long long ans = evklid(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;
	return ans;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		b[i].resize(k);
		for (int j = 0; j < k; j++) {
			scanf("%lld", &b[i][j]);
			b[i][j]--;
			cnt[b[i][j]]++;
		}
	}
	for (int i = 0; i < m; i++) {
		int ss = 1;
		while (ss < cnt[i]) {
			ss *= 2;
		}
		d[i].assign(2 * ss, 1);
		vec[i].assign(2 * ss, 0);
		pos.push_back(ss);
	}
	for (int i = 0; i < n; i++) {
		long long k = sz(b[i]);
		a = b[i];
		for (int j = 0; j < k; j++) {
			while (!st[a[j]].empty()) {
				long long kk = d[a[j]][1];
				long long pp = vec[a[j]][1];
				if (List[a[j]] == i - 1 && pp % __gcd(kk, k) == j % __gcd(kk, k)) {
					break;
				} 		
				int u = st[a[j]].front().second;
				st[a[j]].pop();
				d[a[j]][u] = 1;
				vec[a[j]][u] = 0;
				while (u / 2 > 0) {
					u /= 2;
					long long aa = d[a[j]][2 * u], bb = d[a[j]][2 * u + 1];
					long long x = 0, y = 0;
					long long kk = evklid(aa, bb, x, y);
					d[a[j]][u] = (aa / kk) * bb;
					x *= ((vec[a[j]][2 * u + 1] - vec[a[j]][2 * u]) / kk);
					x %= (d[a[j]][u] / d[a[j]][2 * u]);
					vec[a[j]][u] = ((x * aa + vec[a[j]][2 * u]) % d[a[j]][u] + d[a[j]][u]) % d[a[j]][u];
				}
			}
			List[a[j]] = i;
			st[a[j]].push(make_pair(make_pair(k, j), pos[a[j]]));
			d[a[j]][pos[a[j]]] = k;
			vec[a[j]][pos[a[j]]] = j;
			int u = pos[a[j]];
			while (u / 2 > 0) {
				u /= 2;
				long long aa = d[a[j]][2 * u], bb = d[a[j]][2 * u + 1];
				long long x = 0, y = 0;
				long long kk = evklid(aa, bb, x, y);
				d[a[j]][u] = (aa / kk) * bb;
				x *= ((vec[a[j]][2 * u + 1] - vec[a[j]][2 * u]) / kk);
				x %= (d[a[j]][u] / d[a[j]][2 * u]);
				vec[a[j]][u] = ((x * aa + vec[a[j]][2 * u]) % d[a[j]][u] + d[a[j]][u]) % d[a[j]][u];
			}
			pos[a[j]]++;
			ans[a[j]] = max(ans[a[j]], sz(st[a[j]]));
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}