#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<int> primes({2,3,5,7,11,13,17,19,23,29,31});
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> C(N);
		map<int, int> colorId;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			C[i] = 0;
			for (int p : primes) {
				if (a % p == 0) break;
				C[i]++;
			}
			if (colorId.find(C[i]) == colorId.end()) {
				colorId.emplace(C[i], colorId.size());
			}
		}
		cout << colorId.size() << '\n';
		for (int i = 0; i < N; i++) {
			cout << colorId[C[i]]+1 << " \n"[i+1==N];
		}
	}
	return 0;
}