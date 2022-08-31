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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		map<ll, ll> st;
		ll sum = 0;
		while (N--) {
			ll x; cin >> x;
			++st[x];
			sum += x;
		}
		map<ll, ll> ano; ano[sum] = 1;
		bool fl = true;
		while (!ano.empty()) {
			auto it = ano.end(); --it;
			ll x = it->first, cnt = it->second;
			ano.erase(it);
			cnt -= min(cnt, st[x]);
			if (cnt == 0) continue;
			// if (cnt) cerr << x << ": " << cnt << '\n';
			if (x == 1) {
				fl = false; break;
			}
			ano[x / 2] += cnt;
			ano[(x + 1) / 2] += cnt;
		}
		cout << (fl ? "YES" : "NO") << '\n';
	}

	return 0;
}