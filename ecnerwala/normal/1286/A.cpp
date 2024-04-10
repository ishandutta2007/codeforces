#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> P(N+2);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	int ans = N;
	for (int z0 = 1; z0 <= 2; z0++) {
		for (int zN = 1; zN <= 2; zN++) {
			P[0] = z0;
			P[N+1] = zN;

			int numEven = N / 2;
			int numOdd = (N+1) / 2;
			for (int i = 1; i <= N; i++) {
				if (P[i]) {
					if (P[i] % 2 == 0) numEven--;
					else numOdd --;
				}
			}
			vector<int> evenLens;
			vector<int> oddLens;
			int cost = 0;
			for (int i = 0; i <= N;) {
				assert(P[i]);
				int j = i+1;
				while (!P[j]) j++;
				if (P[i] % 2 == P[j] % 2) {
					if (j-i-1 >= 1) {
						if (P[i] % 2 == 0) evenLens.push_back(j-i-1);
						else oddLens.push_back(j-i-1);
					}
				} else {
					cost += 1;
				}
				i = j;
			}

			sort(evenLens.begin(), evenLens.end());
			reverse(evenLens.begin(), evenLens.end());
			while (!evenLens.empty() && evenLens.back() <= numEven) {
				numEven -= evenLens.back();
				evenLens.pop_back();
			}
			cost += 2 * int(evenLens.size());
			sort(oddLens.begin(), oddLens.end());
			reverse(oddLens.begin(), oddLens.end());
			while (!oddLens.empty() && oddLens.back() <= numOdd) {
				numOdd -= oddLens.back();
				oddLens.pop_back();
			}
			cost += 2 * int(oddLens.size());
			ans = min(ans, cost);
		}
	}
	cout << ans << '\n';

	return 0;
}