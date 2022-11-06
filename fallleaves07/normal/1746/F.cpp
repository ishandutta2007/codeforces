#include<bits/stdc++.h>
using namespace std;
using LL = long long;

random_device rds;
const int seed = rds();
mt19937 rd(seed);

template<int L>
struct VBIT {
	int n;
	vector<array<int, L>> f;
	VBIT(int _n) : n(_n), f(n + 1, array<int, L>{}) {}
	void insert(int loc, const array<int, L> &v) {
		for (int i = loc; i <= n; i += i & -i) {
			for (int j = 0; j < L; j++) {
				f[i][j] += v[j];
			}
		}
	}
	void change(int loc, const array<int, L> &vnow, const array<int, L> &vlst) {
		for (int i = loc; i <= n; i += i & -i) {
			for (int j = 0; j < L; j++) {
				f[i][j] += vnow[j] - vlst[j];
			}
		}
	}
	bool query(int l, int r, int k) {
		vector<int> sum(L);
		for (int i = r; i; i -= i & -i) {
			for (int j = 0; j < L; j++) {
				sum[j] += f[i][j];
			}
		}
		for (int i = l - 1; i; i -= i & -i) {
			for (int j = 0; j < L; j++) {
				sum[j] -= f[i][j];
			}
		}
		for (int j = 0; j < L; j++) {
			if (sum[j] % k) {
				return false;
			}
		}
		return true;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	const int L = 50;
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	using vec = array<int, L>;
	map<int, vec> vmp;
	auto getvec = [&](int val) -> vec& {
		if (vmp.find(val) != vmp.end()) {
			return vmp[val];
		}
		vec &ret = vmp[val];
		for (int i = 0; i < L; i++) {
			ret[i] = rd() % 2;
		}
		return ret;
	};

	VBIT<L> bits(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		auto &v = getvec(a[i]);
		bits.insert(i, v);
	}
	for (int i = 1; i <= q; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int id, x;
			cin >> id >> x;
			swap(a[id], x);
			vec &vnow = getvec(a[id]), &vlst = getvec(x);
			bits.change(id, vnow, vlst);
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			bool ans = bits.query(l, r, k);
			puts(ans ? "YES" : "NO");
		}
	}
    return 0;
}