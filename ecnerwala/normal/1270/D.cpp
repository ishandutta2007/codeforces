#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K; cin >> N >> K;
	map<int, int> cnts;
	for (int i = 0; i < K+1; i++) {
		cout << "?";
		for (int j = 0; j < K+1; j++) {
			if (j == i) continue;
			cout << ' ' << j+1;
		}
		cout << '\n' << flush;
		int pos, a; cin >> pos >> a;
		cnts[a]++;
	}
	vector<int> c;
	for (auto it : cnts) c.push_back(it.second);
	assert(c.size() == 2);
	cout << '!' << ' ' << c[1] << '\n' << flush;

	return 0;
}