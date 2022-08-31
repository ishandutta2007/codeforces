#include<bits/stdc++.h>
using namespace std;

void go() {
	int V[2][3];
	for (int z = 0; z < 2; z++) {
		for (int t = 2; t >= 0; t--) {
			cin >> V[z][t];
		}
	}
	int D[8];
	for (int z = 7; z > 0; z--) cin >> D[z];
	D[0] = 0;

	int T[3];
	T[0] = D[1] + D[3] + D[5] + D[7];
	T[1] = D[2] + D[3] + D[6] + D[7];
	T[2] = D[4] + D[5] + D[6] + D[7];

	for (int t = 0; t < 3; t++) {
		if (V[0][t] + V[1][t] < T[t]) {
			cout << -1 << '\n';
			return;
		}
		V[1][t] = T[t] - V[1][t];

		V[1][t] -= D[1 << t];
		V[1][t] = max(0, V[1][t]);
	}
	auto& lo = V[1];
	auto& hi = V[0];
	//for (int z = 1; z <= 7; z++) { cerr << "D[" << z << "] = " << D[z] << '\n'; }
	//for (int t = 0; t < 3; t++) { cerr << "lo[" << t << "] = " << lo[t] << ' '; cerr << "hi[" << t << "] = " << hi[t] << '\n'; }

	// D[3], D[5], D[6] need to distribute across
	for (int i = 0; i <= D[3] + D[5] + D[6] + D[7]; i++) {
		if (i < lo[0] || i < lo[1] || i < lo[2]) {
			continue;
		}
		int n6 = max(0, i - hi[0]);
		int n5 = max(0, i - hi[1]);
		int n3 = max(0, i - hi[2]);
		if (n3 > D[3] || n5 > D[5] || n6 > D[6]) continue;
		if (n3 + n5 + n6 > i) continue;
		int n7 = i - n6 - n5 - n3;
		if (n7 > D[7]) {
			int diff;
			diff = min(n7 - D[7], min(D[3] - n3, min(hi[2],i) - lo[2]));
			n3 += diff, n7 -= diff;
			assert(n3 <= D[3]);
			diff = min(n7 - D[7], min(D[5] - n5, min(hi[1],i) - lo[1]));
			n5 += diff, n7 -= diff;
			assert(n5 <= D[5]);
			diff = min(n7 - D[7], min(D[6] - n6, min(hi[0],i) - lo[0]));
			n6 += diff, n7 -= diff;
			assert(n6 <= D[6]);
		}
		if (n7 > D[7]) continue;
		assert(n3 + n5 + n6 + n7 == i);
		// it's done!
		int F[8];
		F[3] = n3;
		F[5] = n5;
		F[6] = n6;
		F[7] = n7;
		F[1] = min(D[1], hi[0] - n3 - n5 - n7);
		F[2] = min(D[2], hi[1] - n3 - n6 - n7);
		F[4] = min(D[4], hi[2] - n5 - n6 - n7);
		//for (int z = 1; z <= 7; z++) { cerr << "F[" << z << "] = " << F[z] << '\n'; }
		for (int z = 7; z > 0; z--) {
			cout << F[z] << " \n"[z==1];
		}
		return;
	}
	cout << -1 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}