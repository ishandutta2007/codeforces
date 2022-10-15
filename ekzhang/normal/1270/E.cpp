#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1013
int N;
pair<int, int> A[MAXN];

pair<int, int> rot(pair<int, int> p) {
	return { (p.first + p.second) / 2, (p.first - p.second) / 2 };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;

	while (true) {
		int c = 0;
		for (int i = 0; i < N; i++)
			c += (A[i].first + A[i].second) & 1; // num odd

		if (c == 0) { // all even
			for (int i = 0; i < N; i++) {
				A[i] = rot(A[i]);
			}
		}
		else if (c == N) {
			for (int i = 0; i < N; i++) {
				A[i].first++;
				A[i] = rot(A[i]);
			}
		}
		else {
			vector<int> ans;
			for (int i = 0; i < N; i++) {
				if ((A[i].first + A[i].second) & 1) {
					ans.push_back(i + 1);
				}
			}
			cout << ans.size() << '\n';
			for (int x : ans) cout << x << ' ';
			cout << endl;
			return 0;
		}
	}

	cout.flush();
	return 0;
}