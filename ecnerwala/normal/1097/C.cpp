#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	map<int, int> cntr;

	int res = 0;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string S; cin >> S;
		int tot = 0;
		for (char c : S) {
			tot += (c == '(' ? +1 : -1);
		}
		bool good = true;
		int pref = 0;
		for (char c : S) {
			pref += (c == '(' ? +1 : -1);
			if (pref < min(tot, 0)) {
				good = false;
				break;
			}
		}
		if (!good) continue;
		if (cntr[-pref] > 0) {
			cntr[-pref] --;
			res++;
		} else {
			cntr[pref]++;
		}
	}
	cout << res << '\n';

	return 0;
}