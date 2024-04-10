

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

template <uint32_t base>
struct Montgomery {
	using i32 = int32_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	static constexpr u32 mod() {
		return base;
	}

	static constexpr u32 np = []() {
		u32 x = base;
		for (int i = 0; i < 4; ++i) {
			x *= 2u - base * x;
		}
		return -x;
	}();
	static constexpr u32 r2 = -(u64)(base) % base;

	static_assert(base < (1u << 30));
	static_assert(base * np + 1 == 0);

	static u32 reduce(u64 x) {
		return (x + (u64)((u32)x * np) * base) >> 32;
	}

	u32 x;
	Montgomery(): x(0) {}
	constexpr Montgomery(long long y): x(y ? reduce((u64)(y % base + base) * r2) : 0) {}

	Montgomery& operator +=(const Montgomery& ot) {
		if ((i32)(x += ot.x - 2 * base) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator -=(const Montgomery& ot) {
		if ((i32)(x -= ot.x) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator *=(const Montgomery& ot) {
		x = reduce((u64)x * ot.x);
		return *this;
	}

	Montgomery& operator /=(const Montgomery& ot) {
		return *this *= ot.inverse();
	}

	friend Montgomery operator +(Montgomery a, const Montgomery& b) {
		a += b;
		return a;
	}

	friend Montgomery operator -(Montgomery a, const Montgomery& b) {
		a -= b;
		return a;
	}

	friend Montgomery operator *(Montgomery a, const Montgomery& b) {
		a *= b;
		return a;
	}

	friend Montgomery operator /(Montgomery a, const Montgomery& b) {
		a /= b;
		return a;
	}

	Montgomery operator -() const {
		return Montgomery() - *this;
	}

	u32 get() const {
		u32 res = reduce(x);
		return res < base ? res : res - base;
	}

	u32 operator ()() const {
		return get();
	}

	Montgomery inverse() const {
		return pow(base - 2);
	}

	Montgomery pow(int64_t p) const {
		if (p < 0) {
			return pow(-p).inverse();
		}
		Montgomery res = 1;
		Montgomery a = *this;
		while (p) {
			if (p & 1) {
				res *= a;
			}
			p >>= 1;
			a *= a;
		}
		return res;
	}

	friend istream& operator >>(istream& istr, Montgomery& m) {
		long long x;
		istr >> x;
		m = Montgomery(x);
		return istr;
	}

	friend ostream& operator <<(ostream& ostr, const Montgomery& m) {
		return ostr << m.get();
	}

	bool operator ==(const Montgomery& ot) const {
		return (x >= base ? x - base : x) == (ot.x >= base ? ot.x - base : ot.x);
	}

	bool operator !=(const Montgomery& ot) const {
		return (x >= base ? x - base : x) != (ot.x >= base ? ot.x - base : ot.x);
	}

	explicit operator int64_t() const {
		return x;
	}

	explicit operator bool() const {
		return x;
	}
};


template <typename T>
struct IndexedValue {
	int index;
	T value;

	bool operator <(const IndexedValue<T>& ot) const {
		return std::tie(value, index) < std::tie(ot.value, ot.index);
	}
};

template <typename T>
std::ostream& operator <<(std::ostream& ostr, const IndexedValue<T>& x) {
	return ostr << "(index=" << x.index << ", value=" << x.value << ")";
}

template <typename T>
std::vector<IndexedValue<T>> with_index(const std::vector<T>& vec) {
	std::vector<IndexedValue<T>> result(vec.size());
	for (int i = 0; i < (int)vec.size(); ++i) {
		result[i] = {i, vec[i]};
	}
	return result;
}
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<Mint> res(n + 1);
	res[0] = 1;
	vector<Mint> p(n + 2);
	p[1] = 1;
	vector<IndexedValue<int>> st = {{0, 0}};
	Mint cur = 0;
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (st.back().value > x) {
			auto [pos, val] = st.back();
			st.pop_back();
			cur += (p[pos] - p[st.back().index]) * val;
		}
		cur -= (p[i + 1] - p[st.back().index]) * x;
		st.push_back({i + 1, x});
		res[i + 1] = cur;
		p[i + 2] = p[i + 1] + cur;
	}
	cout << (res[n] * (n % 2 ? -1 : 1)) << "\n";

	return 0;
}