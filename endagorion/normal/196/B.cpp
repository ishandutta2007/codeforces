#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

	int N, M;
	fin >> N >> M;
	vector<string> f(N);
	int sx = -1, sy = -1;
	for (int i = 0; i < N; ++i) {
		fin >> f[i];
		for (int j = 0; j < M; ++j) {
			if (f[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}

	pair<int, int> nv = make_pair(-1, -1);
	vector< vector< int > > visx(N, vector<int>(M, -1e9)), visy(N, vector<int>(M, -1e9));
	bool ok = false;
	vector< pair<int, int> > q;
	q.push_back(make_pair(sx, sy));
	visx[sx][sy] = sx;
	visy[sx][sy] = sy;
	size_t cur = 0;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	while (!ok && cur < q.size()) {
		int x = q[cur].first;
		int y = q[cur].second;
		for (int d = 0; d < 4; ++d) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			int rx = (xx % N + N) % N;
			int ry = (yy % M + M) % M;
			if (f[rx][ry] == '#') {
				continue;
			}
			if (visx[rx][ry] == xx && visy[rx][ry] == yy) {
				continue;
			}
			if (visx[rx][ry] == -1e9) {
				visx[rx][ry] = xx;
				visy[rx][ry] = yy;
				q.push_back(make_pair(xx, yy));
			} else {
				ok = true;
				break;
			}
		}
		++cur;
	}

	fout << (ok ? "Yes\n" : "No\n") << '\n';

	return 0;
}