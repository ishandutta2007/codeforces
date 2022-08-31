#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int last[2] = {-1, -1};
	for (int i = 0; i < N; i++) {
		int v; cin >> v; last[v] = i;
	}
	cout << min(last[0], last[1]) + 1 << '\n';

	return 0;
}