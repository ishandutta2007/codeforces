#include <bits/stdc++.h>
using namespace std;

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<int> a(n), cnt(2);
		vector<vector<array<array<int, 2>, 2>>> f(n + 1, vector<array<array<int, 2>, 2>> (n + 1)); 
		for(int i = 0; i < n; i ++) {
			cin >> a[i];
			a[i] &= 1;
			cnt[a[i]] ++;
		}
		int win = 0;
		if(n & 1) {
			win = (cnt[1] & 1) ^ 1;
		}
		f[0][0][win][0] = 1;
		f[0][0][win][1] = 1;
		f[0][0][win ^ 1][0] = 0;
		f[0][0][win ^ 1][1] = 0;
		for(int i = 0; i <= n; i ++) {
			for(int j = !i; j <= n; j ++) {
				for(int c = 0; c < 2; c ++) {
					for(int d = 0; d < 2; d ++) {
						f[i][j][c][d] = 0;
						if(i) f[i][j][c][d] |= !f[i - 1][j][d][c];
						if(j) f[i][j][c][d] |= !f[i][j - 1][d][c ^ 1];
					}
				}
			}
		}
		cout << (f[cnt[0]][cnt[1]][0][0] ? "Alice\n" : "Bob\n");
	}
	return 0;
}