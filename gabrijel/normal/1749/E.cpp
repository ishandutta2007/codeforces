#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int inf = 1e9;
const int sx[] = {0, 1, 0, -1};
const int sy[] = {1, 0, -1, 0};
const int gx[] = {1, 1, -1, -1};
const int gy[] = {1, -1, -1, 1};

int n, m;
vector <string> mat;
vector <vector <int> > dist;
deque <pair <int, int> > q;
vector <vector <pair <int, int> > > odkud;

bool moze(int x, int y) {
	REP(i, 4) {
		int nx = x + sx[i], ny = y + sy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(mat[nx][ny] == '#') return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		cin >> n >> m;
		mat.clear();
		odkud.clear();
		dist.clear();
		mat.resize(n);
		odkud.resize(n, vector <pair <int, int> >(m, make_pair(-1, -1)));
		dist.resize(n, vector <int>(m, inf));
		REP(i, n) cin >> mat[i];
		REP(i, n) {
			if(mat[i][0] == '.') {
				if(moze(i, 0)) {
					q.push_back(make_pair(i, 0));
					dist[i][0] = 1;
				}
			}
			else {
				q.push_front(make_pair(i, 0));
				dist[i][0] = 0;
			}
		}
		while(!q.empty()) {
			pair <int, int> tr = q.front();
			q.pop_front();
			REP(i, 4) {
				int nx = tr.first + gx[i], ny = tr.second + gy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m || !moze(nx, ny)) continue;
				if(dist[nx][ny] == inf) {
					odkud[nx][ny] = tr;
					dist[nx][ny] = dist[tr.first][tr.second];
					if(mat[nx][ny] != '#') {
						dist[nx][ny]++;
						q.push_back(make_pair(nx, ny));
					}
					else q.push_front(make_pair(nx, ny));
				}
			}
		}
		int mini = inf, gdje = -1;
		REP(i, n) {
			if(dist[i][m - 1] < mini) {
				mini = dist[i][m - 1];
				gdje = i;
			}
		}
		if(gdje == -1) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int i = gdje, j = m - 1;
		mat[i][j] = '#';
		while(j) {
			pair <int, int> kamo = odkud[i][j];
			i = kamo.first;
			j = kamo.second;
			mat[i][j] = '#';
		}
		REP(ii, n) {
			REP(jj, m) {
				cout << mat[ii][jj];
			}
			cout << "\n";
		}
	}
	return 0;
}