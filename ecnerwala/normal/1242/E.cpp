#include<bits/stdc++.h>
using namespace std;

const int MAXF = 1.1e5;
int F;
pair<int, int> A[MAXF];
vector<int> ans[MAXF];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> F;
	for (int i = 0; i < F; i++) {
		int a; cin >> a; A[i] = {a, i};
	}
	sort(A, A + F);
	int N = 2;
	deque<int> dq({1, 2});
	for (int i = F-1; i >= 0; i--) {
		int v, f; tie(v,f) = A[i];
		int s = int(dq.size());
		int numMerge = min((s + v - (i ? A[i-1].first : 3)) / 2, min(s, v) - 1);
		for (int z = 0; z < numMerge-1; z++) {
			ans[f].push_back(dq.back());
			dq.pop_back();
		}
		ans[f].push_back(dq.back());
		for (int z = numMerge; z < v-1; z++) {
			++N;
			ans[f].push_back(N);
			dq.push_back(N);
		}
		ans[f].push_back(dq.front());
		dq.push_back(dq.front());
		dq.pop_front();
	}

	cout << N << '\n';
	for (int i = 0; i < F; i++) {
		for (int v : ans[i]) { cout << v << ' '; } cout << '\n';
	}

	return 0;
}