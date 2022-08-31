#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	int lo = 0;
	int hi = N;
	while (hi - lo > 1) {
		int md = (lo + hi) / 2;
		cout << '?' << ' ' << md << '\n' << flush;
		int a0; cin >> a0;
		cout << '?' << ' ' << md+1 << '\n' << flush;
		int a1; cin >> a1;
		if (a0 < a1) {
			hi = md;
		} else {
			lo = md;
		}
	}
	cout << '!' << ' ' << hi << '\n';

	return 0;
}