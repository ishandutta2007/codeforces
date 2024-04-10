/*input
1000 123456 654321
*/
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
long long power(long long x, long long y);

#define MOD(x) (((x)%mod+mod)%mod)

long long dalink(long long a, long long b) { // a/b
	return MOD(MOD(a) * power(b, mod - 2));
}
long long power(long long x, long long y) {
	if (y == 0)
		return 1;

	long long p = power(x, y / 2) % mod;
	p = (p * p) % mod;

	return (y % 2 == 0) ? p : (x * p) % mod;
}
long long k, a, b;
long long atrum, btrum;
long long adalb;
long long ats = 0;

long long din[1005][1005] = {};
long long prid[1005][1005] = {};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> k >> a >> b;
	atrum = dalink(a, a + b);
	btrum = dalink(b, a + b);
	adalb = dalink(a, b);
	//rek(1, 0, 0, 0);
	din[0][0]++;

	for (int i = 0; i < k; i++) { // pris
		for (int j = 0; j < k; j++) {
			din[j][i] += prid[j][i];
			din[j][i] %= mod;
			prid[j + 1][i + 1] += MOD(prid[j][i] * atrum);
			prid[j + 1][i + 1] %= mod;
			//cout << din[j][i] << "(" << prid[j][i] << ") ";
			long long aa = j,  pris = i;
			ats += MOD(din[j][i] * MOD(aa + adalb));
			ats %= mod;

			if (aa > 0) {
					din[aa][pris + aa] += MOD(din[j][i] * btrum);
					din[aa][pris + aa] %= mod;
			}

			prid[aa + 1][pris + aa + 1] += MOD(MOD(din[j][i] * btrum) * atrum);
			prid[aa + 1][pris + aa + 1] %= mod;
		}

		//cout << endl;
	}

	cout << dalink(ats, atrum);


	return 0;
}