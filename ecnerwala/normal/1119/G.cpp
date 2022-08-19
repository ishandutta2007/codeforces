#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
const int MAXM = MAXN;
int N, M;
int H[MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> H[i];

	vector<int> cutoffs;
	cutoffs.push_back(0);
	cutoffs.push_back(N);
	int cur = 0;
	for (int i = 0; i+1 < M; i++) {
		cur += H[i];
		cutoffs.push_back(cur % N);
	}
	assert(int(cutoffs.size()) == M+1);
	sort(cutoffs.begin(), cutoffs.end());
	vector<int> sizes;
	for (int i = 0; i < M; i++) sizes.push_back(cutoffs[i+1] - cutoffs[i]);

	vector<int> ans;
	for (int i = 0, ind = 0; i < M; i++) {
		int v = H[i];
		while (v > 0) {
			ans.push_back(i);
			v -= sizes[ind % M];
			ind++;
		}
	}

	while (int(ans.size()) % M != 0) ans.push_back(0);
	cout << int(ans.size()) / M << '\n';
	for (int i = 0; i < M; i++) {
		cout << sizes[i] << " \n"[i+1==M];
	}
	for (int i = 0; i < int(ans.size()); i++) {
		cout << ans[i]+1 << " \n"[(i+1)%M == 0];
	}

	return 0;
}