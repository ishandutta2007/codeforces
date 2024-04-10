#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e18;

vector <string> mat;

set <pair <ll, pair <int, int> > > najb;
vector <vector <ll> > dist;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	mat.resize(n);
	dist.resize(n, vector <ll>(m, inf));
	REP(i, n) {
		cin >> mat[i];
		REP(j, m) {
			if(mat[i][j] == '.') {
				najb.insert(make_pair(0LL, make_pair(i, j)));
				dist[i][j] = 0LL;
			}
			//else najb.insert(make_pair(inf, make_pair(i, j)));
		}
	}
	while(najb.size()) {
		pair <ll, pair <int, int> > tp = *(najb.begin());
		najb.erase(najb.begin());
		ll tr_d = tp.first;
		int x = tp.second.first, y = tp.second.second;
		if(x > 1 && mat[x - 1][y] == 'D') {
			if(dist[x - 2][y] > tr_d + q) {
				if(dist[x - 2][y] != inf) najb.erase(make_pair(dist[x - 2][y], make_pair(x - 2, y)));
				dist[x - 2][y] = tr_d + q;
				najb.insert(make_pair(dist[x - 2][y], make_pair(x - 2, y)));
			}
		}
		if(x < n - 2 && mat[x + 1][y] == 'U') {
			if(dist[x + 2][y] > tr_d + q) {
				if(dist[x + 2][y] != inf) najb.erase(make_pair(dist[x + 2][y], make_pair(x + 2, y)));
				dist[x + 2][y] = tr_d + q;
				najb.insert(make_pair(dist[x + 2][y], make_pair(x + 2, y)));
			}
		}
		if(y > 1 && mat[x][y - 1] == 'R') {
			if(dist[x][y - 2] > tr_d + q) {
				if(dist[x][y - 2] != inf) najb.erase(make_pair(dist[x][y - 2], make_pair(x, y - 2)));
				dist[x][y - 2] = tr_d + q;
				najb.insert(make_pair(dist[x][y - 2], make_pair(x, y - 2)));
			}
		}
		if(y < m - 2 && mat[x][y + 1] == 'L') {
			if(dist[x][y + 2] > tr_d + q) {
				if(dist[x][y + 2] != inf) najb.erase(make_pair(dist[x][y + 2], make_pair(x, y + 2)));
				dist[x][y + 2] = tr_d + q;
				najb.insert(make_pair(dist[x][y + 2], make_pair(x, y + 2)));
			}
		}
		//
		if(x > 0 && y > 0 && (mat[x - 1][y] == 'R' || mat[x][y - 1] == 'D')) {
			if(dist[x - 1][y - 1] > tr_d + p) {
				if(dist[x - 1][y - 1] != inf) najb.erase(make_pair(dist[x - 1][y - 1], make_pair(x - 1, y - 1)));
				dist[x - 1][y - 1] = tr_d + p;
				najb.insert(make_pair(dist[x - 1][y - 1], make_pair(x - 1, y - 1)));
			}
		}
		if(x > 0 && y < m - 1 && (mat[x - 1][y] == 'L' || mat[x][y + 1] == 'D')) {
			if(dist[x - 1][y + 1] > tr_d + p) {
				if(dist[x - 1][y + 1] != inf) najb.erase(make_pair(dist[x - 1][y + 1], make_pair(x - 1, y + 1)));
				dist[x - 1][y + 1] = tr_d + p;
				najb.insert(make_pair(dist[x - 1][y + 1], make_pair(x - 1, y + 1)));
			}
		}
		if(x < n - 1 && y > 0 && (mat[x + 1][y] == 'R' || mat[x][y - 1] == 'U')) {
			if(dist[x + 1][y - 1] > tr_d + p) {
				if(dist[x + 1][y - 1] != inf) najb.erase(make_pair(dist[x + 1][y - 1], make_pair(x + 1, y - 1)));
				dist[x + 1][y - 1] = tr_d + p;
				najb.insert(make_pair(dist[x + 1][y - 1], make_pair(x + 1, y - 1)));
			}
		}
		if(x < n - 1 && y < m - 1 && (mat[x + 1][y] == 'L' || mat[x][y + 1] == 'U')) {
			if(dist[x + 1][y + 1] > tr_d + p) {
				if(dist[x + 1][y + 1] != inf) najb.erase(make_pair(dist[x + 1][y + 1], make_pair(x + 1, y + 1)));
				dist[x + 1][y + 1] = tr_d + p;
				najb.insert(make_pair(dist[x + 1][y + 1], make_pair(x + 1, y + 1)));
			}
		}
	}
	ll rj = inf;
	REP(i, n) {
		REP(j, m) {
			//cout << dist[i][j] << " ";
			if(i < n - 1) rj = min(rj, dist[i][j] + dist[i + 1][j]);
			if(j < m - 1) rj = min(rj, dist[i][j] + dist[i][j + 1]);
		}
		//cout << endl;
	}
	if(rj < inf) cout << rj << "\n";
	else cout << -1 << "\n";
	return 0;
}