#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct SegmentTree {
    int n;
    vector <int> t;
 
    void build(const vector <int> &a) {
        for (int i = 0; i < n; ++i) {
            t[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }
 
    void modify(int x, int val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = max(t[x], t[x ^ 1]);
        }
    }
 
    int get(int l, int r) {
        ++r;
        int res = -1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
 
    SegmentTree(const vector <int> &a) {
        n = a.size();
        t.resize(2 * n, -1);
        build(a);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector <int> lst(n, -1);
	vector <int> prv(n, -1);
	for (int i = 0; i < n; ++i) {
		prv[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	SegmentTree p(prv);
	SegmentTree mx(a);

	auto bad = [&] (int l, int r) {
		int x = p.get(l, r);
		if (x >= l) return true;
		return false;
	};

	auto is_perm = [&] (int l, int r) {
		if (r >= n) return false;
		if (bad(l, r)) return false;
		int x = mx.get(l, r);
		if (x >= r - l + 1) return false;
		return true;
	};

	vector <vector <int>> where(n);
	for (int i = 0; i < n; ++i) where[a[i]].push_back(i);

	auto get_nxt = [&] (int i, int x) {
		auto it = lower_bound(where[x].begin(), where[x].end(), i);
		if (it == where[x].end()) return n;
		return *it;
	};

	int ans = 0;
	for (int l = 0; l < n; ++l) {
		int r = get_nxt(l, 0);
		while (r < n) {
			if (bad(l, r)) break;
			int m = mx.get(l, r);
			r = max(r, l + m);
			if (is_perm(l, r)) ++ans;
			++r;
		}
	}
	cout << ans << '\n';
}