#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int N;
bool prime[MAXN];
vector<int> primes;
int X1[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;
	for (int p = 2; p < MAXN; p++) {
		if (prime[p]) {
			primes.push_back(p);
			for (int q = p * 2; q < MAXN; q += p) {
				prime[q] = false;
			}
		}
	}

	for (int p : primes) {
		if (p > N) break;
		if (N % p == 0) {
			int s = max(p, N - p + 1);
			int e = N;
			X1[s]++;
			X1[e + 1]--;
		}
	}

	int ans = N;
	for (int i = 1; i < MAXN; i++) {
		X1[i] += X1[i - 1];
		if (X1[i]) {
			// find greatest prime divisor of i
			int num = i, bp = 1;
			for (int d : primes) {
				if (d * d > num)
					break;
				while (num % d == 0) {
					num /= d;
					bp = d;
				}
			}
			if (num != i && num != 1) {
				bp = max(bp, num);
			}
			ans = min(ans, i - bp + 1);
		}
	}



	cout << ans << endl;
	return 0;
}