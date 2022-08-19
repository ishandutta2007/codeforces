#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = 1e7;
	vector<bool> is_prime(V+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int p = 2; p <= V; p++) {
		if (!is_prime[p]) continue;
		for (int j = p + p; j <= V; j += p) is_prime[j] = false;
	}

	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int num_ones = 0;
	for (int a : A) {
		if (a == 1) num_ones++;
	}
	vector<int> ans;
	if (num_ones >= 2) {
		ans = vector<int>(num_ones, 1);
		for (int a : A) {
			if (a != 1 && is_prime[a+1]) {
				ans.push_back(a);
				goto done;
			}
		}
		goto done;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (is_prime[A[i] + A[j]]) {
				ans = vector<int>({A[i], A[j]});
				goto done;
			}
		}
	}
	ans = vector<int>({A.front()});

done:
	cout << ans.size() << '\n';
	for (int v : ans) {
		cout << v << ' ';
	}
	cout << '\n';

	return 0;
}

// All pairs are odd/even or 1+1
// Can't have 2 evens
// Can't have 2 odds not both 1
// 1111111 even
// or odd even