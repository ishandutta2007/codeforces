// October 7, 2018
// http://codeforces.com/problemset/problem/1059/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	int N;
	cin >> N;
	int cur = N;
	int cur_gcd = 1;
	vector<int> res;
	while (cur > 1) {
		if (cur == 3) {
			res.push_back(cur_gcd);
			res.push_back(cur_gcd);
			cur_gcd *= 3;
			break;
		}
		for (int i = 0; i < (cur + 1) / 2; i++) {
			res.push_back(cur_gcd);
		}
		cur /= 2;
		cur_gcd *= 2;
	}
	res.push_back(cur_gcd);
	for (int i = 0; i < N; i++) {
		cout << res[i] << (i == N - 1 ? '\n' : ' ');
	}


	return 0;
}