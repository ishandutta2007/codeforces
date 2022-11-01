// October 28, 2018
// http://codeforces.com/contest/1043/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXM = 10;
const int MAXN = 100000;

int N, M;
int a[MAXM][MAXN];
int pos[MAXM][MAXN + 1];

bool works(int l, int r) {
	if (l == r) return true;
	// a[l][r - 1] must have worked
	for (int i = 1; i < M; i++) {
		int nxt_pos = pos[i][a[0][r - 1]] + 1;
//		cout << l << "," << r << '\n';
//		cout << "nxt_pos: " << nxt_pos << '\n';
//		cout << a[i][nxt_pos] << '\n';
		if (nxt_pos >= N || a[i][nxt_pos] != a[0][r]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG


	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			pos[i][a[i][j]] = j;
		}
	}
	int a = 0, b = 0;
	long long ans = 0;
	while (b < N) {
		if (works(a, b)) b++;
		else {
			long long len = b - a;
//			cout << "len: " << len << '\n';
//			cout << "b: " << b << '\n';
			ans += len * (len + 1) / 2;
			a = b;
		}
	}
	long long len = b - a;
	ans += len * (len + 1) / 2;
	cout << ans << '\n';


	return 0;
}