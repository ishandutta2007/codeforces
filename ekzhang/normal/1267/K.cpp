#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int T;
LL K;

LL solve(vector<int> seq) {
	int n = seq.size();
	sort(seq.begin(), seq.end());
	map<int, int> m;
	for (int x : seq)
		m[x]++;

	LL ans = 1;
	int remain = n;
	for (int i = n - 1; i >= 0; i--) {
		int x = seq[i];
		int num = min(remain - x + 1, remain);
		ans *= num;
		// cout << "A " << num << endl;
		--remain;
	}

	for (auto p : m) {
		for (int i = 1; i <= p.second; i++)
			ans /= i; // divide by factorial
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> K;
		vector<int> seq;
		for (int i = 2; K; i++) {
			seq.push_back(K % i);
			K /= i;
		}
		sort(seq.begin(), seq.end());

		LL ans = solve(seq);
		if (seq[0] == 0) {
			seq.erase(seq.begin());
			ans -= solve(seq);
		}

		cout << ans - 1 << '\n';
	}

	cout.flush();
	return 0;
}