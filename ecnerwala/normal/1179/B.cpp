#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int> res;
	for (int l = 0, r = N*M-1; l <= r; ) {
		if (res.size() % 2 == 0) {
			res.push_back(l);
			l++;
		} else {
			res.push_back(r);
			r--;
		}
	}
	for (int i : res) {
		cout << i / M + 1 << ' ' << i % M + 1 << '\n';
	}

	return 0;
}