#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<int> row_maxs(N), col_maxs(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a; cin >> a; a--;
			row_maxs[i] = max(row_maxs[i], a);
			col_maxs[j] = max(col_maxs[j], a);
		}
	}
;
	vector<bool> is_max(N*M, false);
	for (int m : row_maxs) is_max[m] = true;
	for (int m : col_maxs) is_max[m] = true;
	vector<int> extras; extras.reserve(N*M);
	for (int v = N*M; v--;) if (!is_max[v]) extras.push_back(v);

	sort(row_maxs.begin(), row_maxs.end(), std::greater());
	sort(col_maxs.begin(), col_maxs.end(), std::greater());
	row_maxs.push_back(-1);
	col_maxs.push_back(-1);

	vector<int> B(N*M);
	for (int i = 0, j = 0, z = 0; i < N || j < M; ) {
		int v = max(row_maxs[i], col_maxs[j]);
		if (row_maxs[i] == col_maxs[j]) {
			B[i*M+j] = v;
			for (int a = j-1; a >= 0; a--) B[i*M+a] = extras[z++];
			for (int a = i-1; a >= 0; a--) B[a*M+j] = extras[z++];
			i++, j++;
		} else if (row_maxs[i] == v) {
			B[i*M+j-1] = v;
			for (int a = j-2; a >= 0; a--) B[i*M+a] = extras[z++];
			i++;
		} else if (col_maxs[j] == v) {
			B[(i-1)*M+j] = v;
			for (int a = i-2; a >= 0; a--) B[a*M+j] = extras[z++];
			j++;
		} else assert(false);
	}


	for (int i = 0; i < N*M; i++) {
		cout << B[i]+1 << " \n"[i%M+1==M];
	}

	return 0;
}