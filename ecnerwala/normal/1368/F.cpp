#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	int bestK = 1;
	int bestCnd = 0;
	for (int k = 1; k <= N; k++) {
		int cnd = N - (N+k-1) / k + 1 - k;
		if (cnd >= bestCnd) {
			bestCnd = cnd;
			bestK = k;
		}
	}

	const int K = bestK;
	set<int> to_add;
	for (int i = 0; i < N; i++) {
		if (i % K) to_add.insert(i);
	}

	while (int(to_add.size()) >= K) {
		cout << K;
		for (int z = 0; z < K; z++) {
			auto it = to_add.begin();
			cout << ' ' << *it+1;
			to_add.erase(it);
		}
		cout << '\n' << flush;
		int resp; cin >> resp;
		if (resp == -1) exit(0);
		resp--;
		for (int i = 0; i < K; i++) {
			int j = (resp+i)%N;
			if (j % K) to_add.insert(j);
		}
	}
	cout << 0 << '\n' << flush;
	return 0;
}