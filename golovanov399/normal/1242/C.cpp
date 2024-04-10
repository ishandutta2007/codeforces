#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()
 
#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
	int k = nxt();
	vector<vector<int>> a(k);
	map<int, int> M;
	long long sum = 0;
	for (int i = 0; i < k; ++i) {
		a[i].resize(nxt());
		for (int& x : a[i]) {
			M[x = nxt()] = i;
		}
		sum += accumulate(all(a[i]), 0ll);
	}
 
	if (sum % k) {
		cout << "No\n";
		return 0;
	}
	sum /= k;
 
	map<int, int> prv;
	for (int i = 0; i < k; ++i) {
		long long cur_s = accumulate(all(a[i]), 0ll);
		for (int x : a[i]) {
		    if (abs(sum - cur_s + x) > 2e9) {
		        continue;
		    }
			int need = sum - (cur_s - x);
			if (!M.count(need)) {
				continue;
			}
			prv[x] = need;
		}
	}
 
	const int K = 1 << k;
	vector<char> can(K);
	vector<int> where_to_start(K);
	can[0] = 1;
	set<int> used;
	for (int i = 0; i < k; ++i) {
		for (int x : a[i]) {
			if (used.count(x)) {
				continue;
			}
			set<int> local;
			int y;
			for (y = x; !used.count(y) && !local.count(y) && prv.count(y); y = prv[y]) {
				local.insert(y);
			}
			if (used.count(y) || !prv.count(y)) {
				for (int y : local) {
					used.insert(y);
				}
				continue;
			}
			bool is_ok = true;
			int mask = 0;
			int z = y;
			do {
				int idx = M[z];
				if (mask & (1 << idx)) {
					is_ok = false;
					break;
				}
				mask |= 1 << idx;
				z = prv[z];
			} while (z != y);
			if (is_ok) {
				can[mask] = 1;
				where_to_start[mask] = y;
			}
			for (int y : local) {
				used.insert(y);
			}
		}
	}
 
	vector<char> super_can(K, false);
	super_can[0] = true;
	vector<int> prv_mask(K, 0);
	for (int mask = 1; mask < K; ++mask) {
		for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
			if (can[submask] && super_can[mask ^ submask]) {
				super_can[mask] = true;
				prv_mask[mask] = mask ^ submask;
			}
		}
	}
 
	if (!super_can[K - 1]) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	vector<int> p(k);
	vector<int> c(k);
	for (int mask = K - 1; mask > 0; mask = prv_mask[mask]) {
		int last_cycle = mask ^ prv_mask[mask];
		int x = where_to_start[last_cycle];
		for (int i = 0; i < __builtin_popcount(last_cycle); ++i) {
			c[M[x]] = x;
			p[M[prv[x]]] = M[x];
			x = prv[x];
		}
	}
	for (int i = 0; i < k; ++i) {
		cout << c[i] << " " << p[i] + 1 << "\n";
	}
 
	return 0;
}