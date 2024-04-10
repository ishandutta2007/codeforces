#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

const int N = 1e6;

int small[N+1];
vector<int> primes;
void init() {
	bitset<N+1> np;
	np[0] = np[1] = true;
	for (int i = 2; i <= sqrt(N); i++) {
		if (np[i] == false) {
			for (int j = i*i; j <= N; j += i) {
				np[j] = true;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!np[i]) {
			primes.push_back(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	init();

	int n;
	cin >> n;

	int first = INF;
	for (int p : primes) {
		if (p >= n) break;
		if (n % p == 0) {
			first = n - p + 1;
		}
	}

	int ans = INF;
	for (int i = first; i <= n; i++) {
		int t = i;
		for (int p : primes) {
			if (p > sqrt(t)) break;
			if (t % p == 0) {
				ans = min(ans, i-p+1);
				while (t % p == 0) {
					t /= p;
				}
			}
		}
		if (t != 1 && t != i) {
			ans = min(ans, i-t+1);
		}
	}
	cout << ans << nl;

	return 0;
}