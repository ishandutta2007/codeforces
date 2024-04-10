#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i,0,n)
		cin >> s[i];
	vector<vector<bool>> done(n, vector<bool>(m));
	rep(i,0,n) {
	rep(j,0,m) {
		if (done[i][j])
			continue;
		if (s[i][j] == '0')
			continue;
		queue<pair<int, int>> q;
		set<pair<int, int>> visited;
		q.push(make_pair(i, j));
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		int minX = i, minY = j, maxX = i, maxY = j;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (visited.count(cur))
				continue;
			visited.insert(cur);
			int x = cur.first;
			int y = cur.second;
			done[x][y] = true;
			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, x);
			maxY = max(maxY, y);
			rep(i,0,4) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && s[nx][ny] == '1')
					q.push(make_pair(nx, ny));
			}
		}
		if (visited.size() != (maxX-minX+1)*(maxY-minY+1)) {
			puts("NO");
			return;
		}
	}
	}
	/*rep(i,0,n) {
	rep(j,0,m) {
		if (done[i][j])
			continue;
		if (s[i][j] == '0')
			continue;
		if (i && s[i-1][j] == '1') {
			puts("NO");
			return;
		}
		if (i && s[i][j-1] == '1') {
			puts("NO");
			return;
		}
		int first_w = -1;
		rep(k,j,m) {
			int w = i;
			while (w < n && s[w][k] == '1') {
				done[w][k] = true;
				++w;
			}
			if (i && s[i-1][k] == '1') {
				puts("NO");
				return;
			}
			if (w == i)
				break;
			if (first_w == -1)
				first_w = w;
			if (w != first_w) {
				puts("NO");
				return;
			}
		}
	}
	}*/
	puts("YES");
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}