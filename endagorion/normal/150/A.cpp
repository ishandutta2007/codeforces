#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	long long n;
	fin >> n;

	long long ans = n;
	long long a = n, b = n;

	for (long long q = 2; q * q <= n; ++q) {
		if (n % q == 0) {
			if (q < a) {
				b = a;
				a = q;
			} else {
				if (q < b) {
					b = q;
				}
			}
			if (q * q == n) {
				continue;
			}
			if (n / q < a) {
				b = a;
				a = n / q;
			} else {
				if (n / q < b) {
					b = n / q;
				}
			}
		}
	}

	if (b % a == 0) {
		ans = b;
	} else {
		if (a * b < n) {
			ans = a * b;
		}
	}

	if (a == n) {
		ans = 0;
	}

	if (ans < n) {
		fout << 1 << '\n' << ans << '\n';
	} else {
		fout << 2 << '\n';
	}

	return 0;
}