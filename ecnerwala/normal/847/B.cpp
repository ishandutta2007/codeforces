#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		int mi = -1, ma = int(res.size());
		while (ma - mi > 1) {
			int md = (ma + mi) / 2;
			if (res[md].back() > a) {
				mi = md;
			} else {
				ma = md;
			}
		}
		if (ma == int(res.size())) {
			res.emplace_back();
		}
		res[ma].push_back(a);
	}

	for (vector<int> &it : res) {
		assert(!it.empty());
		int e = it.back(); it.pop_back();
		for (int i : it) {
			cout << i << ' ';
		}
		cout << e << '\n';
	}

	return 0;
}