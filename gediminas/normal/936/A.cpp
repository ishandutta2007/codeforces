/*input
3 2 6
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long k, d, t;
	cin >> k >> d >> t;
	long long kas = k / d + (k % d > 0);

	long long greit = 2 * k + (kas * d - k);

	long double piln = t * 2 / greit * 1.0l * d * kas;

	long long lik = t * 2 % greit;

	if (lik <= 2 * k) {
		piln += lik / 2.0l;
	}
	else {
		piln += k;
		lik -= 2 * k;
		piln += lik;
	}

	cout << fixed << setprecision(9) << piln << endl;


	return 0;
}