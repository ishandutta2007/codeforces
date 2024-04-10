#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 200 * 1000 + 10, NUM_STEPS = 40;
const long long INF = (long long)1e17;
int n;
long long a[nax];
long long ans;

long long best_ans_with_known_gcd(long long d) {
	long long w = 0;
	for(int i = 1; i <= n; ++i) {
		long long r = a[i] % d;
		long long best = (a[i] < d ? d - a[i] : min(r, d-r));
		w += best;
		if(w > (long long)n) {
			return n;
		}
	}
	return w;
}

void find_divisors(long long x) {
	for(long long d = 2; d * d <= x; ++d) {
		if(x % d == 0) {
			//d jest dzielnikiem pierwszym x
			ans = min(ans, best_ans_with_known_gcd(d));
		}
		while(x % d == 0) {
			x /= d;
		}
	}
	if(x > 1) {
		ans = min(ans, best_ans_with_known_gcd(x));
	}
}
			

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	shuffle(a+1, a+n+1, rng);
	ans = n;
	for(int step = 1; step <= min(NUM_STEPS, n); ++step) {
		long long cur_val = a[step];
		for(long long possible = max(1LL,cur_val - 1); possible <= cur_val + 1; ++possible) {
			find_divisors(possible);
		}
	}
	cout << ans;	
}