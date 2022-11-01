#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 998244353;
const int M = 2;
const int offset = (1 << 19);

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll)a * b % mod;
}

struct Mat {
	int mat[M][M];
	Mat() {REP(i, M) REP(j, M) mat[i][j] = 0;}
	Mat operator *(Mat &druga) {
		Mat ret;
		REP(i, M) {
			REP(j, M) {
				int res = 0;
				REP(k, M) res = add(res, mult(mat[i][k], druga.mat[k][j]));
				ret.mat[i][j] = res;
			}
		}
		return ret;
	}
};

struct tournament {
	Mat prod[2 * offset];
	tournament() {
		Mat jed;
		jed.mat[0][0] = jed.mat[1][1] = 1;
		REP(i, 2 * offset) prod[i] = jed;
	}
	void update(Mat m, int pos) {
		pos += offset;
		prod[pos] = m;
		pos /= 2;
		while(pos) {
			prod[pos] = prod[pos * 2 + 1] * prod[pos * 2];
			pos /= 2;
		}
		return;
	}
} T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b;
	cin >> n;
	vector <vector <pair <int, bool> > > ev(offset);
	Mat imam, nemam;
	imam.mat[0][0] = 1;
	imam.mat[0][1] = 1;
	imam.mat[1][0] = 2;
	imam.mat[1][1] = 2;
	nemam.mat[0][0] = 3;
	nemam.mat[0][1] = 1;
	nemam.mat[1][0] = 0;
	nemam.mat[1][1] = 2;
	for(int i = 1; i < n; i++) T.update(nemam, i);
	REP(i, n) {
		cin >> a >> b;
		ev[a].push_back(make_pair(i, 1));
		ev[b + 1].push_back(make_pair(i, 0));
	}
	int rj = 0;
	a = 1; b = 0;
	REP(i, offset) {
		for(pair <int, bool> p : ev[i]) {
			if(p.first == 0) {
				swap(a, b);
				continue;
			}
			if(p.second) T.update(imam, p.first);
			else T.update(nemam, p.first);
		}
		rj = add(rj, add(mult(a, T.prod[1].mat[1][0]), mult(b, T.prod[1].mat[1][1])));
	}
	cout << rj << "\n";
	return 0;
}