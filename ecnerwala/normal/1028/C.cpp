#include<bits/stdc++.h>
using namespace std;

const int INF = 1.1e9;

const int MAXN = 2e5;
int N;
int mi[2][MAXN][2];
int ma[2][MAXN][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		mi[0][i+1][0] = a;
		mi[0][i+1][1] = b;
		ma[0][i+1][0] = c;
		ma[0][i+1][1] = d;

		mi[1][i][0] = a;
		mi[1][i][1] = b;
		ma[1][i][0] = c;
		ma[1][i][1] = d;
	}
	mi[0][0][0] = -INF;
	mi[0][0][1] = -INF;
	mi[1][N][0] = -INF;
	mi[1][N][1] = -INF;

	ma[0][0][0] = +INF;
	ma[0][0][1] = +INF;
	ma[1][N][0] = +INF;
	ma[1][N][1] = +INF;

	for (int i = 0; i < N; i++) {
		for (int z = 0; z < 2; z++) {
			mi[0][i+1][z] = max(mi[0][i+1][z], mi[0][i][z]);
			ma[0][i+1][z] = min(ma[0][i+1][z], ma[0][i][z]);
		}
	}
	for (int i = N; i > 0; i--) {
		for (int z = 0; z < 2; z++) {
			mi[1][i-1][z] = max(mi[1][i-1][z], mi[1][i][z]);
			ma[1][i-1][z] = min(ma[1][i-1][z], ma[1][i][z]);
		}
	}

	for (int i = 0; i < N; i++) {
		int mi0 = max(mi[0][i][0], mi[1][i+1][0]);
		int ma0 = min(ma[0][i][0], ma[1][i+1][0]);

		int mi1 = max(mi[0][i][1], mi[1][i+1][1]);
		int ma1 = min(ma[0][i][1], ma[1][i+1][1]);

		if (mi0 <= ma0 && mi1 <= ma1) {
			cout << mi0 << ' ' << mi1 << '\n';
			return 0;
		}
	}
	assert(false);

	return 0;
}