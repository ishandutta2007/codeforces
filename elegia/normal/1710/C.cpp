#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;

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
int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 200005;

char S[_];

int dp[1 << 5], tmp[1 << 5];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> S; int len = strlen(S);
	reverse(S, S + len);
	for (int i = 0; i != len; ++i) S[i] -= '0';
	{
		int pos = 0;
		while (S[pos]) S[pos++] = 0;
		S[pos] = 1;
		if (pos == len) ++len;
	}

	int n = 0;
	for (int i = len - 1; i >= 0; --i) n = norm(n * 2 + S[i]);

	int ans = n * (ull)n % P * n % P;
	sub(ans, n);
	sub(ans, 3ULL * n % P * (n - 1ULL) % P);

	dp[0] = 1;
	for (int i = len - 1; i >= 0; --i) {
		memset(tmp, 0, sizeof(tmp));
		for (int s = 0; s != 1 << 5; ++s) {
			int thr = s & 7, tw = s >> 3;
			for (int a = 0; a != 8; ++a) {
				if (a == 1 || a == 6) continue;
				int nxt = thr, nxw = tw;
				if (S[i]) {
					nxt |= 7 - a;
				} else {
					if ((a & thr) != a) continue;
				}
				if ((a & 1) != ((a >> 1) & 1)) nxw |= 1;
				if ((a & 1) != ((a >> 2) & 1)) nxw |= 2;
				add(tmp[nxt | (nxw << 3)], dp[s]);
			}
		}
		memcpy(dp, tmp, sizeof(tmp));
	}

	int res = dp[(1 << 5) - 1];

	sub(ans, res * 3ULL % P);

	cout << ans << '\n';

	return 0;
}