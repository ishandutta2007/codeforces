// October 7, 2018
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


const double EPS = 1e-6;
const int MOD = 998244353;
const int MAXN = 500;

int N;
long long a[MAXN];
map<long long, int> factors[MAXN];
bool factored[MAXN];

long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N; i++) {
		for (int j = 4; j >= 2; j--) {
			long long b = (long long) (pow(a[i], 1.0 / j) + EPS);
			long long p = 1;
			for (int k = 0; k < j; k++) {
				p *= b;
			}
			if (p == a[i]) {
				factors[i][b] = j;
				factored[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i] == a[j] || (factored[i] && factored[j])) continue;
			long long g = gcd(a[i], a[j]);
			if (g == 1) continue;
			if (!factored[i] && a[i] != g) {
				factors[i][g]++;
				factors[i][a[i] / g]++;
				factored[i] = true;
			}
			if (!factored[j] && a[j] != g) {
				factors[j][g]++;
				factors[j][a[j] / g]++;
				factored[j] = true;
			}
		}
	}
	long long ans = 1;
	map<long long, int> m;
	for (int i = 0; i < N; i++) {
		if (factored[i]) {
			for (auto p : factors[i]) {
				m[p.first] += p.second;
			}
		}
		else {
			int k = i;
			while (a[k + 1] == a[i]) k++;
			ans *= (k - i + 2) * (k - i + 2); ans %= MOD;
			i = k;
		}
	}
	for (auto p : m) {
		ans *= p.second + 1; ans %= MOD;
	}
	cout << ans << '\n';


	return 0;
}