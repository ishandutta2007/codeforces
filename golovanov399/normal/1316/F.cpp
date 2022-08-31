#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

template <int mod>
struct Modular {
	int val;

	Modular(long long _val = 0) {
		if (_val < 0 || _val >= mod) {
			val = _val % mod;
			if (val < 0) {
				val += mod;
			}
		} else {
			val = _val;
		}
	}

	Modular operator +(const Modular& ot) const {
		int res = val + ot.val;
		if (res >= mod) {
			res -= mod;
		}
		return {res};
	}

	Modular operator -(const Modular& ot) const {
		int res = val - ot.val;
		if (res < 0) {
			res += mod;
		}
		return {res};
	}

	Modular operator *(const Modular& ot) const {
		return {1ll * val * ot.val};
	}

	Modular& operator ++() {
		val += 1;
		if (val == mod) {
			val = 0;
		}
		return *this;
	}

	Modular operator ++(int) {
		Modular tmp(*this);
		operator ++();
		return tmp;
	}

	void operator +=(const Modular& ot) {
		val += ot.val;
		if (val >= mod) {
			val -= mod;
		}
	}

	void operator -=(const Modular& ot) {
		val -= ot.val;
		if (val < 0) {
			val += mod;
		}
	}

	void operator *=(const Modular& ot) {
		val = 1ll * val * ot.val % mod;
	}

	bool operator ==(const Modular& ot) const {
		return val == ot.val;
	}

	bool operator !=(const Modular& ot) const {
		return val != ot.val;
	}
};

template <int mod>
ostream& operator <<(ostream& ostr, const Modular<mod>& x) {
	return ostr << x.val;
}

const int mod = 1000000007;
using Mint = Modular<mod>;

Mint one = 1;
Mint half = (mod + 1) / 2;

struct Node {
	Mint prob, eup, edown;
	Mint ans;

	Node(int x = 0): prob(x ? half : 1), eup(Mint(x) * half), edown(Mint(x) * half), ans(0) {}
};

Node merge(const Node& left, const Node& right) {
	Node res;
	res.prob = left.prob * right.prob;
	res.eup = right.eup + right.prob * left.eup;
	res.edown = left.edown + left.prob * right.edown;
	res.ans = left.ans + right.ans + left.eup * right.edown;
	return res;
}

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	void set(int pos, int x) {
		pos += n;
		a[pos] = Node(x);
		pos /= 2;
		while (pos) {
			a[pos] = merge(a[pos * 2], a[pos * 2 + 1]);
			pos /= 2;
		}
	}
};

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<pair<int, int>> all_guys;
	for (int i = 0; i < n; ++i) {
		all_guys.push_back({a[i], i});
	}
	int q = nxt();
	vector<pair<int, int>> qrs(q);
	for (int i = 0; i < q; ++i) {
		qrs[i].first = nxt() - 1;
		qrs[i].second = nxt();
		all_guys.push_back({qrs[i].second, i + n});
	}
	sort(all(all_guys));
	vector<int> p(n + q);
	for (int i = 0; i < n + q; ++i) {
		p[all_guys[i].second] = i;
	}

	SegTree tree(n + q);
	vector<int> last(n);
	for (int i = 0; i < n; ++i) {
		last[i] = p[i];
	}
	for (int i = 0; i < n; ++i) {
		tree.set(p[i], a[i]);
	}
	cout << tree.a[1].ans << "\n";
	for (int i = 0; i < q; ++i) {
		int idx = qrs[i].first;
		tree.set(last[idx], 0);
		last[idx] = p[n + i];
		tree.set(last[idx], qrs[i].second);
		cout << tree.a[1].ans << "\n";
	}

	return 0;
}