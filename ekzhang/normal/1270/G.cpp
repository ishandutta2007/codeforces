#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
int T, N;
int A[MAXN];
bool vis[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = N - 1; i >= 0; i--) {
			cin >> A[i];
			A[i] += i;
			vis[i] = false;
		}

		int s;
		for (s = 0; !vis[s]; s = A[s])
			vis[s] = true;

		vector<int> ans = {s};
		for (int x = A[s]; x != s; x = A[x])
			ans.push_back(x);

		cout << ans.size() << '\n';
		for (int x : ans)
			cout << N - x << ' ';
		cout << '\n';
	}

	cout.flush();
	return 0;
}