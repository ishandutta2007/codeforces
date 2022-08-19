#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
int N;
int invP[MAXN];
const int MAXM = 2.1e5;
int M;
int nxtOcc[MAXM];
int A[MAXM];
int nxt[MAXM][20];

int Q;

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		int p; cin >> p; invP[p] = i;
	}

	vector<pair<int, int>> ranges;
	for (int i = 1; i <= M; i++) {
		cin >> A[i];
		A[i] = invP[A[i]];

		nxt[i][0] = nxtOcc[(A[i] + N-1) % N];
		for (int z = 0; nxt[i][z]; z++) {
			nxt[i][z+1] = nxt[nxt[i][z]][z];
		}
		nxtOcc[A[i]] = i;

		int l = i;
		for (int z = 0; (1 << z) <= N-1; z++) {
			if ((N-1) & (1 << z)) {
				l = nxt[l][z];
			}
		}
		if (l != 0) {
			if (ranges.empty() || ranges.back().first < l) {
				ranges.emplace_back(l, i);
			}
		}
	}

	string ans;
	for (int q = 0; q < Q; q++) {
		int l, r;  cin >> l >> r;
		auto it = lower_bound(ranges.begin(), ranges.end(), pair<int, int>(l, -1));
		if (it != ranges.end() && it->second <= r) {
			ans += '1';
		} else {
			ans += '0';
		}
	}
	cout << ans << '\n';
}