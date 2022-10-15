#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int Q;
int N, K;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> N >> K;
		vector<int> odd;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (A[i] % 2)
				odd.push_back(i);
		}
		if (odd.size() >= K && (odd.size() - K) % 2 == 0) {
			cout << "YES\n";
			for (int i = 0; i < K - 1; i++)
				cout << odd[i] << ' ';
			cout << N << '\n';
		}
		else cout << "NO\n";
	}

	cout.flush();
	return 0;
}