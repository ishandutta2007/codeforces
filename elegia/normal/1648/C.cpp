/*
 , .
 */
#include <cmath>
#include <cstring>

#include <algorithm>
#include <random>
#include <chrono>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using ull = unsigned long long;
using ll = long long;

using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

const int _ = 200005;

int fac[_], ifac[_];
int cnt[_], t[_], fw[_];

void ch(int k, int x) {
	for (; k < _; k += k & -k) add(fw[k], x);
}
int qry(int k) {
	int ret = 0;
	for (; k; k &= k - 1) add(ret, fw[k]);
	return ret;
}

void pre(int N) {
	fac[0] = 1; for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * (ull)i % P;
	ifac[N] = mpow(fac[N], P - 2);  for (int i = N; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M; cin >> N >> M;
	for (int rep = 1; rep <= N; ++rep) {
		int x; cin >> x; ++cnt[x];
	}
	for (int i = 1; i <= M; ++i) cin >> t[i];
	pre(N);
	int prd = 1;
	for (int i = 1; i < _; ++i) if (cnt[i]) { ch(i, cnt[i]); prd = prd * (ull)ifac[cnt[i]] % P; }
	int ans = 0;
	bool fl = true;
	for (int i = 1; i <= min(N, M); ++i) {
		fam(ans, qry(t[i] - 1), fac[N - i] * (ull)prd % P);
		if (cnt[t[i]] == 0) { fl = false; break; }
		prd = prd * (ull)(cnt[t[i]]--) % P;
		ch(t[i], P - 1);
	}
	if (fl && N < M) add(ans, 1);
	cout << ans << '\n';

	return 0;
}