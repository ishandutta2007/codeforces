#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;
int A[MAXN];
int stopTime[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (*min_element(A, A + N) * 2 >= *max_element(A, A + N)) {
		for (int i = 0; i < N; i++) {
			cout << -1 << " \n"[i+1==N];
		}
		exit(0);
	}

	for (int i = 0; i < N; i++) {
		A[i+N] = A[i];
	}

	for (int i = 0; i < N; i++) {
		stopTime[i] = 2 * N;
	}

	vector<pair<int, int>> biggests;
	for (int i = 0; i < 2*N; i++) {
		int mi = -1, ma = int(biggests.size());
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			if (biggests[md].first > 2 * A[i]) {
				mi = md;
			} else {
				ma = md;
			}
		}
		if (mi == -1) {
			// nothing big enough
		} else {
			stopTime[biggests[mi].second%N] = min(stopTime[biggests[mi].second%N], i - biggests[mi].second);
		}

		while (!biggests.empty() && biggests.back().first < A[i]) {
			biggests.pop_back();
		}
		biggests.emplace_back(A[i], i);
	}

	for (int z = 0; z < 2; z++) {
		for (int i = N-1; i >= 0; i--) {
			stopTime[i] = min(stopTime[i], stopTime[(i+1)%N]+1);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << stopTime[i] << " \n"[i+1==N];
	}

	return 0;
}