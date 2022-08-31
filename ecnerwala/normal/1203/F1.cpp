#include<bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXR = 6.1e4;

int N;
int R;
vector<pair<int, int>> incr;
vector<pair<int, int>> decr;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		int A, B; cin >> A >> B;
		A = max(A, -B);
		if (B >= 0) {
			incr.emplace_back(A, B);
		} else {
			decr.emplace_back(A+B, -B);
		}
	}
	sort(incr.begin(), incr.end());
	sort(decr.begin(), decr.end());
	reverse(decr.begin(), decr.end());

	for (auto it : incr) {
		if (R < it.first) {
			cout << "NO" << '\n'; exit(0);
		}
		R += it.second;
	}
	for (auto it : decr) {
		if (R < it.first + it.second) {
			cout << "NO" << '\n'; exit(0);
		}
		R -= it.second;
	}
	cout << "YES" << '\n';
	return 0;
}