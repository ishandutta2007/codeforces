#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, K; cin >> N >> M >> K;
	cout << (min(M, K) >= N ? "Yes" : "No") << '\n';

	return 0;
}