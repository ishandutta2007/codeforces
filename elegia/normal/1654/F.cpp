/*
   
   
   
   
 */
#include <cmath>
#include <cstring>

#include <algorithm>
#include <limits>
#include <functional>
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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

using namespace std;

const int _ = (1 << 18) + 55;

struct Node {
	int id, x, y;
} v[_];

char s[_];
int cnt[_];
int rk[_], p[_], q[_];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n >> s;
	int N = 1 << n;
	for (int i = 0; i != N; ++i) cnt[s[i] - 'a'] = 1;
	for (int i = 1; i != 26; ++i) cnt[i] += cnt[i - 1];
	for (int i = 0; i != N; ++i) rk[i] = cnt[s[i] - 'a'] - 1;
	// for (int i = 0; i != N; ++i) cerr << rk[i] << " \n"[i == N - 1];
	for (int t = 1; t != N; t <<= 1) {
		for (int i = 0; i != N; ++i) {
			v[i].id = i;
			v[i].x = rk[i];
			v[i].y = rk[i ^ t];
		}
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i != N; ++i) ++cnt[v[i].y];
		for (int i = 1; i != N; ++i) cnt[i] += cnt[i - 1];
		for (int i = N - 1; i >= 0; --i)
			p[--cnt[v[i].y]] = i;
		// for (int i = 0; i != N; ++i) cerr << p[i] << " \n"[i == N - 1];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i != N; ++i) ++cnt[v[i].x];
		for (int i = 1; i != N; ++i) cnt[i] += cnt[i - 1];
		for (int i = N - 1; i >= 0; --i)
			q[--cnt[v[p[i]].x]] = p[i];
		// for (int i = 0; i != N; ++i) cerr << q[i] << " \n"[i == N - 1];
		rk[q[0]] = 0;
		int tmp = 0;
		// for (int i = 0; i != N; ++i) cerr << v[q[i]].x << "," << v[q[i]].y << " \n"[i == N - 1];
		for (int i = 1; i != N; ++i) {
			if (v[q[i]].x != v[q[i - 1]].x || v[q[i]].y != v[q[i - 1]].y)
				++tmp;
			rk[q[i]] = tmp;
		}
	}
	int j = find(rk, rk + N, 0) - rk;
	for (int i = 0; i != N; ++i) cout << s[j ^ i];

	return 0;
}