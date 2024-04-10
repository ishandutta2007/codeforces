#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int A[MAXN];
int maxInd[MAXN];
int minInd[MAXN];

int lis[MAXN];

int lisVal[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i]; A[i] --;
		}

		for (int v = 0; v < N; v++) {
			maxInd[v] = -1;
			minInd[v] = N;
		}
		for (int i = 0; i < N; i++) {
			if (minInd[A[i]] == N) minInd[A[i]] = i;
			maxInd[A[i]] = i;
		}
		vector<pair<int, int>> locs;
		for (int v = 0; v < N; v++) {
			if (maxInd[v] == -1) continue;
			locs.emplace_back(minInd[v], maxInd[v]);
		}

		int ans = 1;
		int cur = 1;
		for (int z = 1; z < int(locs.size()); z++) {
			if (locs[z].first > locs[z-1].second) {
				cur++;
			} else {
				cur = 1;
			}
			ans = max(ans, cur);
		}

		cout << int(locs.size())-ans << '\n';
	}

	return 0;
}