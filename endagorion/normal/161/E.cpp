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

vector<int> genPrimes(int N) {
	vector<bool> isPrime(N + 1, true);
	vector<int> res;
	for (int i = 2; i <= N; ++i) {
		if (isPrime[i]) {
			res.push_back(i);
			for (int j = 2 * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
	return res;
}

string intToStr(int n, int k) {
	string res = "";
	for (int i = 0; i < k; ++i) {
		res += (char)(n % 10 + '0');
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	fout.precision(10);
	fout << fixed;

	vector< int > q1(10000);
	vector< vector<int> > q2(1000, vector<int>(1000));
	vector< vector< vector<int> > > q3(100, vector< vector<int> >(100, vector<int>(100)));
	vector< vector< vector< vector<int> > > > q4(10, vector< vector< vector<int> > >(10, vector< vector<int> >(10, vector<int> (10))));

	vector<int> primes = genPrimes(99999);
	vector<int> b1(11), b2(101), b3(1001), b4(10001);
	for (size_t i = 0; i < primes.size(); ++i) {
		b1[primes[i] / 10000 + 1] = i + 1;
		b2[primes[i] / 1000 + 1] = i + 1;
		b3[primes[i] / 100 + 1] = i + 1;
		b4[primes[i] / 10 + 1] = i + 1;
	}

	for (size_t i = 0; i < primes.size(); ++i) {
		int p = primes[i];
		++q1[p / 10];
	}

	for (int a1 = 0; a1 < 1000; ++a1) {
		for (size_t i = 0; i < primes.size(); ++i) {
			int p = primes[i];
			q2[p / 100][a1] += q1[10 * a1 + p % 10];
		}
	}

	for (int a1 = 0; a1 < 100; ++a1) {
		for (int a2 = 0; a2 < 100; ++a2) {
			for (size_t i = 0; i < primes.size(); ++i) {
				int p = primes[i];
				q3[p / 1000][a1][a2] += q2[10 * a1 + p / 10 % 10][10 * a2 + p % 10];
			}
		}
	}

	for (int a1 = 0; a1 < 10; ++a1) {
		for (int a2 = 0; a2 < 10; ++a2) {
			for (int a3 = 0; a3 < 10; ++a3) {
				for (size_t i = 0; i < primes.size(); ++i) {
					int p = primes[i];
					q4[p / 10000][a1][a2][a3] += q3[10 * a1 + p / 100 % 10][10 * a2 + p / 10 % 10][10 * a3 + p % 10];
				}
			}
		}
	}

	
	int T;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		int x;
		fin >> x;
		if (x < 100) {
			fout << q1[x % 10];
		} else {
			if (x < 1000) {
				fout << q2[x / 10 % 10][x % 10];
			} else {
				if (x < 10000) {
					fout << q3[x / 100 % 10][x / 10 % 10][x % 10];
				} else {
					fout << q4[x / 1000 % 10][x / 100 % 10][x / 10 % 10][x % 10];
				}
			}
		}
		fout << '\n';
	}

	return 0;
}