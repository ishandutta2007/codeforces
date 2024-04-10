#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
const int MAXM = 2000;
int N, M;

int A[MAXN][MAXM];
vector<int> rows[MAXN];
vector<int> cols[MAXM];

void unique(vector<int>& v) {
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rows[i].push_back(A[i][j]);
			cols[j].push_back(A[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		unique(rows[i]);
	}
	for (int j = 0; j < M; j++) {
		unique(cols[j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int rind = lower_bound(rows[i].begin(), rows[i].end(), A[i][j]) - rows[i].begin();
			int cind = lower_bound(cols[j].begin(), cols[j].end(), A[i][j]) - cols[j].begin();
			cout << (max(rind, cind) + max(rows[i].size() - rind, cols[j].size() - cind)) << " \n"[j+1==M];
		}
	}

	return 0;
}