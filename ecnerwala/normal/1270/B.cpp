#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1e18;
const int MAXN = 2.1e5;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		pair<ll, int> maxPlus(-INF, -1);
		pair<ll, int> maxMinus(-INF, -1);
		for (int i = 0; i < N; i++) {
			if (-i + maxMinus.first + A[i] > 0) {
				cout << "YES" << '\n';
				cout << maxMinus.second+1 << ' ' << i+1 << '\n';
				goto found;
			}
			if (-i + maxPlus.first - A[i] > 0) {
				cout << "YES" << '\n';
				cout << maxPlus.second+1 << ' ' << i+1 << '\n';
				goto found;
			}
			maxMinus = max(maxMinus, pair<ll, int>(i - A[i], i));
			maxPlus = max(maxPlus, pair<ll, int>(i + A[i], i));
		}
		cout << "NO" << '\n';
found:;
	}

	return 0;
}