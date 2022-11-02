#include <bits/stdc++.h>
const int maxN = 200000 + 233;
const int maxA = 1000000000 + 233;
typedef long long LL;
typedef std::pair<int, int> pii;
using std::vector; using std::cin;
int n, f[maxN], g[maxN], h[maxN], p[maxN];
LL a[maxN];
vector<int> kn;

template<typename A, typename B>
bool chmin(A &a, const B &b) { return a > b ? a = b, true : false; }
template<typename A, typename B>
bool chmax(A &a, const B &b) { return a < b ? a = b, true : false; }
void update(int &g, int &h, int gg, int hh) {
	if(chmin(g, gg)) h = hh;
	else if(g == gg) chmin(h, hh);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	a[0] = 1; p[0] = 0; p[0] = 0;
	for(int i = 1; i <= n; ++i)
		p[i] = (a[i - 1] == -1 ? p[i - 1] : i - 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] == -1) continue;
		else kn.push_back(i);
		if(kn.size() == 1) f[i] = maxN, g[i] = 1, h[i] = i - 1;
		if(kn.size() == 1) continue;
		f[i] = maxN; g[i] = maxN; h[i] = maxN;
		int j = p[i];
		if(kn.size() > 1 && (a[p[j]] - a[j]) % (p[j] - j) == 0) {
			LL dif = (a[p[j]] - a[j]) / (p[j] - j);
			if(dif * (j - i) == a[j] - a[i])
				chmin(f[i], f[j]);
			LL lastv = a[j] + dif * (i - j - 1);
			if(lastv > 0) update(g[i], h[i], f[j] + 1, 0);
			if(lastv > 0) goto G_TRANS;
			LL end = (a[j] - 1) / -dif + j;
			assert(j <= end && end < i - 1);
			update(g[i], h[i], f[j] + 1, i - end - 1);
		}
		G_TRANS:
		if((a[i] - a[j]) % (i - j) == 0) {
			LL dif = (a[i] - a[j]) / (i - j);
			LL firstv = a[j] - h[j] * dif;
			if(firstv > 0) chmin(f[i], g[j]);
		}
		update(g[i], h[i], g[j] + 1, 0);
	}
	if(kn.size() == 0) printf("1\n");
	else {
		int i = kn.back();
		int ans = g[i];
		if((a[i] - a[p[i]]) % (i - p[i]) == 0) {
			LL final = (a[i] - a[p[i]]) / (i - p[i]) * (n - i) + a[i];
			if(final > 0) chmin(ans, f[i]);
			else chmin(ans, f[i] + 1);
		} 
		printf("%d\n", ans);
	}
	return 0;
}