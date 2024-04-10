#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	int res = (N - 1) + (N - K);
	for(int k = 0; k < K; k++) {
		int m; cin >> m;
		for(int i = 0; i < m; i++) {
			int v; cin >> v;
			if(i && v == i + 1) res-=2;
		}
	}
	cout << res << '\n';
	return 0;
}