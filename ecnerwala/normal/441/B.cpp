#include<bits/stdc++.h>

using namespace std;

int f[3010];

int main() {
	int n, v; cin >> n >> v;
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		f[a] += b;
	}
	int res = 0;
	for(int i = 0; i < 3010; i++) {
		int cur = v;
		if(i && f[i - 1]) {
			int num = min(cur, f[i - 1]);
			f[i - 1] -= num;
			cur -= num;
			res += num;
		}
		if(cur) {
			int num = min(cur, f[i]);
			f[i] -= num;
			cur -= num;
			res += num;
		}
	}
	cout << res << '\n';
	return 0;
}