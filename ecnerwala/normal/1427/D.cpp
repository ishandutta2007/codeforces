#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T = 1;
	//int T = 100000;
	//mt19937 mt(48);
	while (T--) {
		int N; cin >> N;
		vector<int> C(N); for (auto& c : C) { cin >> c; c--; }
		//int N = mt() % 6 + 1;
		//vector<int> C(N); iota(C.begin(), C.end(), 0); shuffle(C.begin(), C.end(), mt);

		vector<vector<int>> ops; ops.reserve(N);

		while (!is_sorted(C.begin(), C.end())) {
			int i = 0;
			while (C[i] == i) i++;
			assert(C[i] > i);
			int j = i;
			while (C[j] - C[i] == j-i) j++;
			int k = j;
			while (C[k] != C[i]-1) k++;
			vector<int> op; op.reserve(4);

			if (i > 0) op.push_back(i);
			op.push_back(j - i);
			op.push_back(k+1-j);
			if (k+1 < N) op.push_back(N-1-k);

			ops.emplace_back(std::move(op));

			vector<int> NC; NC.reserve(N);
			NC.insert(NC.end(), C.begin()+k+1, C.end());
			NC.insert(NC.end(), C.begin()+j, C.begin()+k+1);
			NC.insert(NC.end(), C.begin()+i, C.begin()+j);
			NC.insert(NC.end(), C.begin(), C.begin()+i);
			C = std::move(NC);
			//for (int v : C) { cerr << v << ' '; } cerr << '\n';
		}

		assert(int(ops.size()) <= N);
		cout << ops.size() << '\n';
		for (const auto& op : ops) {
			assert(2 <= int(op.size()) && int(op.size()) <= N);
			cout << op.size();
			for (int v : op) {
				assert(v > 0);
				cout << ' ' << v;
			}
			cout << '\n';
		}
	}

	return 0;
}