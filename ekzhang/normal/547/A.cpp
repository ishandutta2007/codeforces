#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (a != 0) {
		int mod = b % a;
		b = a;
		a = mod;
	}
	return b;
}

long long extended_gcd(long long a, long long b, 
					   long long& s, long long& t) {
	// s and t are lvalues, which are the coefficients of bezout's
	s = 1;
	long long s1 = 0;
	t = 0;
	long long t1 = 1;
	while (b != 0) {
		long long d = a / b;
		long long c = a - b * d;
		long long s2 = s - s1 * d;
		long long t2 = t - t1 * d;
		a = b; b = c;
		s = s1; s1 = s2;
		t = t1; t1 = t2;
	}
	return a;
}

long long solve_lincong(long long a, long long b, 
						long long m1, long long m2) {
	// solves the system of linear congruences:
	// n = a (mod m1)
	// n = b (mod m2)
	// where gcd(m1, m2) = 1
	// returns the number x s.t. n = x (mod m1*m2)
	// and 0 <= x < m1 * m2
	long long inv_m1, inv_m2;
	if (extended_gcd(m1, m2, inv_m1, inv_m2) != 1) {
		throw domain_error("gcd of m1 and m2 is not 1");
	}
	long long ret = a * m2 * inv_m2 + b * m1 * inv_m1;
	ret = ((ret % (m1 * m2)) + m1 * m2) % (m1 * m2);
	return ret;
}

map<int, int> factors(int g) {
	map<int, int> ret;
	while (g % 2 == 0) {
		ret[2]++;
		g /= 2;
	}
	for (int i = 3; g != 1; i += 2) {
		while (g % i == 0) {
			ret[i]++;
			g /= i;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("547A.in", "r", stdin);

	int M, H1, A1, X1, Y1, H2, A2, X2, Y2;
	cin >> M >> H1 >> A1 >> X1 >> Y1 >> H2 >> A2 >> X2 >> Y2;

	int dead = 4;
	vector<int> pos1, pos2;
	for (int t = 1; t <= 2 * M; t++) {
		H1 = (int) ((((long long) X1) * ((long long) H1) + Y1) % M);
		H2 = (int) ((((long long) X2) * ((long long) H2) + Y2) % M);
		if (H1 == A1 && pos1.size() < 2) {
			pos1.push_back(t);
			dead--;
		}
		if (H2 == A2 && pos2.size() < 2) {
			pos2.push_back(t);
			dead--;
		}
	}
	if (pos1.size() > 0 && pos2.size() > 0) {
		// check for non-repeating finds
		if (pos1[0] == pos2[0]) {
			cout << pos1[0] << endl;
			return 0;
		}
		if (pos1.size() == 1 && pos2.size() == 2) {
			int m = pos2[1] - pos2[0];
			if (pos1[0] >= pos2[0] 
					&& (pos1[0] % m == pos2[0] % m)) {
				cout << pos1[0] << endl;
				return 0;
			}
		}
		if (pos1.size() == 2 && pos2.size() == 1) {
			int m = pos1[1] - pos1[0];
			if (pos2[0] >= pos1[0] 
					&& (pos2[0] % m == pos1[0] % m)) {
				cout << pos2[0] << endl;
				return 0;
			}
		}
	}
	if (dead > 0) {
		cout << -1 << endl;
		return 0;
	}

	//cout << pos1[0] << ' ' << pos1[1] << ' ' << pos2[0] << ' ' << pos2[1] << endl;

	long long ans = -1;
	int mod[] = {pos1[1] - pos1[0], pos2[1] - pos2[0]};
	int g = gcd(mod[0], mod[1]);
	int orig_pos1 = pos1[0], orig_pos2 = pos2[0];
	if (g != 1) {
		if (pos1[0] % g != pos2[0] % g) {
			cout << -1 << endl;
			return 0;
		}
		for (pair<int, int> p : factors(g)) {
			int power = 1;
			for (int i = 0; i < p.second; i++) {
				power *= p.first;
			}
			mod[0] /= power;
			if (mod[0] % p.first != 0) {
				// good!
				pos1[0] %= mod[0];
			}
			else {
				// bad!
				mod[0] *= power;
				mod[1] /= power;
				pos2[0] %= mod[1];
			}
		}
	}
	// CRT
	// x = pos1[0] (mod mod[0])
	// x = pos2[0] (mod mod[1])
	ans = solve_lincong(pos1[0], pos2[0], mod[0], mod[1]);
	while (ans < orig_pos1 || ans < orig_pos2) {
		ans += mod[0] * mod[1];
	}
	cout << ans << '\n';

	cout.flush();
	return 0;
}