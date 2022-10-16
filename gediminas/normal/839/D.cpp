/*input
4
2 3 4 6
*/
#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007ll

long long pow(const long long &x, const unsigned long long &l, const unsigned long long &m = mod) {
	if (l == 0) return 1;
	else if (l == 1) return x % m;
	else if (l == 2) return (x * x) % m;

	return ((pow(pow(x, l >> 1, m), 2, m) % m) * (l & 1ll ? x % m : 1ll)) % m;
}
long long stipr[1000001] = {};

long long din[1000001] = {};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n;
	cin >> n;

	for (long long i = 0; i < n; i++) {
		long long a;
		cin >> a;
		stipr[a]++;
	}

	long long ats = 0;

	for (long long i = 2; i <= 1000000; i++)
		din[i] = i;

	for (long long i = 2; i <= 1000000; i++) {
		for (long long j = 2 * i; j <= 1000000; j += i)
			din[j] -= din[i];
	}

	for (long long i = 2; i <= 1000000; i++) {
		long long te = 0;

		for (long long j = i; j <= 1000000; j += i)
			te += stipr[j];

		if (te > 0) {
			ats += ((pow(2, te - 1, mod) * te) % mod * din[i]) % mod;
			ats %= mod;
		}
	}

	cout << ats;


	return 0;
}