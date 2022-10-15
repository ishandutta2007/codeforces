#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 500013
int N;
LL L[MAXN];
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> L[i];
	cin >> S;

	// can he gain stamina from 0.5 meter? assume yes??

	LL tland = 0, twater = 0;
	LL lac = 5;
	LL grassflew = 0;
	LL stamina = 0;
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'G') {
			LL flew = min(2 * L[i], L[i] + stamina);
			grassflew += flew;
			stamina += L[i] - flew;
			ans += 5 * L[i] - 2 * flew;
		}
		else if (S[i] == 'W') {
			lac = 3;
			stamina += L[i];
			ans += 3 * L[i];
		}
		else {
			// lava
			if (stamina < L[i]) {
				LL r = min(grassflew, L[i] - stamina);
				stamina += r;
				ans += 2 * r;
				grassflew -= r;
			}
			if (stamina < L[i]) {
				ans += (L[i] - stamina) * lac;
				stamina = L[i];
			}
			stamina -= L[i];
			ans += L[i];
		}
		// cout << ans << endl;
	}

	cout << ans - stamina << endl;
	return 0;
}