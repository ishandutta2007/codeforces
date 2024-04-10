// October 28, 2018
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N;
	int s = 0, m = -1;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		s += t;
		m = max(m, t);
	}
	int k = max(2 * s / N + 1, m);
	cout << k << '\n';


	return 0;
}