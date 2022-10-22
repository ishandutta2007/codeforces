#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 92;
i64 f[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	f[0] = f[1] = 1;
	for(int i = 2; i < N; i ++) f[i] = f[i - 1] + f[i - 2];
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<int> c(n);
		for(int i = 0; i < n; i ++) cin >> c[i];
		i64 sum = accumulate(c.begin(), c.end(), 0ll);
		int p = upper_bound(f + 2, f + N, sum) - f;
		if(f[p] != sum + 1) {
			cout << "No\n";
			continue;
		}
		p -= 2;
		int lst = -1;
		for(; p >= 0; p --) {
			int mx = -1;
			for(int i = 0; i < n; i ++) if(i != lst && (mx == - 1 || c[i] > c[mx])) mx = i;
			if(mx != -1 && c[mx] >= f[p]) c[mx] -= f[p], lst = mx;
			else break;
		}
		cout << (p == -1 ? "Yes\n" : "No\n");
	}
	return 0;
}