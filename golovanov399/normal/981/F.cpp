#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

ostream& operator <<(ostream& ostr, const vector<auto>& a) {
	ostr << "(";
	for (int i = 0; i < (int)a.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << a[i];
	}
	ostr << "}";
	return ostr;
}

int main() {
	int n = nxt();
	long long L = nxt();
	vector<long long> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		b[i] = nxt();
	}
	sort(all(a));
	sort(all(b));
	for (int i = 0; i < 3 * n; ++i) {
		long long x = a[i] + L;
		a.push_back(x);
	}
	for (int i = 0; i < 3 * n; ++i) {
		long long x = b[i] + L;
		b.push_back(x);
	}

	auto checkIfHallSucked = [&](long long d) {
		vector<int> l(n * 4), r(n * 4);

		{
			int j = 0;
			for (int i = 0; i < n * 4; ++i) {
				while (j < n * 4 && a[j] < b[i] - d) {
					++j;
				}
				l[i] = j;
			}
		}
		{
			int j = 0;
			for (int i = 0; i < n * 4; ++i) {
				while (j < n * 4 && a[j] <= b[i] + d) {
					++j;
				}
				r[i] = j;
			}
		}

		// cerr << d << ":\n";
		// cerr << a << " " << b << "\n" << l << " " << r << "\n";

		long long max_shit = LLONG_MIN;
		for (int i = n; i < 3 * n; ++i) {
			max_shit = max(max_shit, (long long)l[i] - i);
			if (r[i] - i <= max_shit) {
				return true;
			}
		}
		return false;
	};

	long long l = -1, r = L;
	while (r > l + 1) {
		long long m = (l + r) / 2;
		if (checkIfHallSucked(m)) {
			l = m;
		} else {
			r = m;
		}
	}

	printf("%lld\n", r);

	return 0;
}