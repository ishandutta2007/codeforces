#include <iostream>
#include <map>
#define int int64_t

using namespace std;

int getSizes(int n, int k) {
	if (k == 0) {
		return 0;
	}
	if (k == 1) {
		return n-1;
	}
	n--;
	map<int, int> el;
	el[n] = 1;
	for (;;) {
		int num, knt; tie(num, knt) = *el.rbegin();
		if (k-1 <= knt) {
			return num / 2;
		} else {
			k -= knt;
		}
		el.erase(num);
		el[num / 2] += knt;
		el[(num+1) / 2] += knt;
	}
}

template<typename OkFunc>
inline int lowerBound(int l, int r, const OkFunc &ok) {
	while (l < r) {
		int m = (l + r) / 2;
		if (ok(m)) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return l;
}

template<typename OkFunc>
inline int upperBound(int l, int r, const OkFunc &ok) {
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (ok(m)) {
			l = m;
		} else {
			r = m-1;
		}
	}
	return l;
}

int minVal(int n, int szs) {
	return lowerBound(1, n-1, [&](int val) -> bool {
		return getSizes(n, val) <= szs;
	});
}

int maxVal(int n, int szs) {
	return upperBound(1, n-1, [&](int val) -> bool {
		return getSizes(n, val) >= szs;
	});
}

int get(int n, int k) {
	if (k == 0) {
		return 0;
	}
	if (k == 1) {
		return n-1;
	}
	int szs = getSizes(n, k);
	int divA = (n+1) / 2;
	int divB = (n+2) / 2;
	int lowSuch = minVal(n, szs);
	int kntIn = k - lowSuch;
	int minDivA = minVal(divA, szs);
	int maxDivA = maxVal(divA, szs);
	int minDivB = minVal(divB, szs);
	int szDivA = maxDivA - minDivA + 1;
	if (getSizes(divA, minDivA) != szs) {
		szDivA = 0;
	}
	if (kntIn < szDivA) {
		return get(divA, minDivA + kntIn);
	} else {
		return divA - 1 + get(divB, minDivB + kntIn - szDivA);
	}
}

signed main() {
	int n, k; cin >> n >> k; k--;
	cout << get(n, k) + 1 << endl;
	return 0;
}