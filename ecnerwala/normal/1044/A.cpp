#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
const int MAXM = 2e5;
int NV, NH;
int V[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> NV >> NH;
	for (int i = 0; i < NV; i++) {
		cin >> V[i];
	}
	priority_queue<int, vector<int>, greater<int>> H;
	for (int i = 0; i < NH; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			H.push(x2);
		} else {
			continue;
		}
	}
	int res = NV + NH;
	sort(V, V + NV);
	V[NV] = int(1e9);
	for (int i = 0; i <= NV; i++) {
		while (!H.empty() && H.top() < V[i]) {
			H.pop();
		}
		res = min(res, i + int(H.size()));
	}
	cout << res << '\n';

	return 0;
}