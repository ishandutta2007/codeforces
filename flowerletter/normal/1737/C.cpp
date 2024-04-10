#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int x, y, n;
		cin >> n;
		vector<int> r(3), c(3), w(3), id(3);
		id[0] = 0, id[1] = 1, id[2] = 2;
		for(int i = 0; i < 3; i ++) cin >> r[i] >> c[i], w[i] = min(r[i] - 1, n - r[i]) + min(c[i] - 1, n - c[i]);
		cin >> x >> y;
		int sx = (r[0] & 1) ^ (r[1] & 1) ^ (r[2] & 1), sy = (c[0] & 1) ^ (c[1] & 1) ^ (c[2] & 1);
		sort(id.begin(), id.end(), [&] (int x, int y) {return w[x] < w[y];});
		if(r[id[0]] != r[id[1]]) swap(id[1], id[2]);
		if(r[id[0]] == r[id[1]] && c[id[0]] == c[id[2]] && w[id[0]] == 0 && w[id[1]] == 1 && w[id[2]]) {
			if(x != r[id[0]] && y != c[id[0]]) cout << "NO\n";
			else cout << "YES\n";
			continue; 
		}
		if(x % 2 == sx && y % 2 == sy) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}