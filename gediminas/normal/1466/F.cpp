#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif

const long long mod = 1000000007;
#define MOD(x) ((x)%mod)
struct UnionFind {
	vector<int> par;
	vector<int> siz;
	vector<int> val;
	UnionFind(int N) {
		par.resize(N);
		siz.resize(N);
		val.resize(N);

		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;

			val[i] = 0;
		}
	}
	int& operator[](const int &x) {
		return val[getParent(x)];
	}
	int getParent(int x) {
		int t = x;

		while (par[x] != x) {
			x = par[x];
		}

		par[t] = x;
		return x;
	}
	int getSize(const int &x) {
		return siz[getParent(x)];
	}
	bool merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);

		if (x == y) {
			return false;
		}

		if (val[x] and val[y]) {
			return false;
		}

		if (siz[x] > siz[y]) {
			swap(x, y);    // siz[x] is smaller
		}

		par[x] = y;
		siz[y] += siz[x];
		val[y] = val[x] or val[y];
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};
long long power(long long x, long long n) {
	int i = 0;
	long long d = x;
	long long ats = 1;

	while (n > 0) {
		if (n & (1ll << i)) {
			n ^= (1ll << i);
			ats *= d;
			ats %= mod;
		}

		i++;
		d = (d * d) % mod;
	}

	return ats;
}
/*input
3 2
1 1
1 2
2 2 1
*/
/*input
2 3
2 1 3
2 1 2
*/
/*input
3 5
2 1 2
1 3
1 4
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;

	UnionFind par(m);

	set<int> imt;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;

		if (k == 1) {
			int a;
			cin >> a;
			a--;

			if (!par[a]) {
				par[a] = true;
				imt.insert(i);
			}
		}
		else if (k == 2) {
			int a, b;
			cin >> a >> b;
			a--, b--;

			if (par.merge(a, b)) {
				imt.insert(i);
			}
		}
	}

	long long vis = 0;

	for (int i = 0; i < m; ++i) {
		if (par.getParent(i) == i) {
			if (par.val[i]) {
				vis += par.siz[i];
			}
			else {
				vis += par.siz[i] - 1;
			}
		}
	}

	cout << power(2, vis) << " " << imt.size() << "\n";

	for (auto &&i : imt) {
		cout << i + 1 << " ";
	}
}