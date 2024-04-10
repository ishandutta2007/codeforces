#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int SZ = 200;

int ii[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int jj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void show(const vector<vector<vector<char>>>& zlp) {
	int mi = SZ + SZ + 1, Mi = 0;
	int mj = SZ + SZ + 1, Mj = 0;
	for (int i = 0; i < (int)zlp.size(); ++i) {
		for (int j = 0; j < (int)zlp[0].size(); ++j) {
			if (accumulate(all(zlp[i][j]), 0)) {
				mi = min(mi, i);
				Mi = max(Mi, i);
				mj = min(mj, j);
				Mj = max(Mj, j);
			}
		}
	}
	for (int i = mi; i <= Mi; ++i) {
		for (int j = mj; j <= Mj; ++j) {
			if (accumulate(all(zlp[i][j]), 0)) {
				cerr << "*";
			} else {
				cerr << ".";
			}
		}
		cerr << "\n";
	}
	cerr << "\n";
}

int main(){

	vector<vector<vector<char>>> empty(SZ + SZ + 1, vector<vector<char>>(SZ + SZ + 1, vector<char>(8, 0)));
	vector<vector<char>> used(SZ + SZ + 1, vector<char>(SZ + SZ + 1, 0));

	auto fi = empty, se = empty;
	fi[SZ][SZ][1] = 1;
	used[SZ][SZ] = 1;

	int n = nxt();
	for (int _ = 0; _ < n; ++_) {
		int t = nxt();
		if (_ == 0) {
			--t;
		}
		se = empty;
		for (int i = 0; i < SZ + SZ + 1; ++i) {
			for (int j = 0; j < SZ + SZ + 1; ++j) {
				for (int d = 0; d < 8; ++d) {
					if (fi[i][j][d] == 0) {
						continue;
					}
					int x = i, y = j;
					for (int ij = 0; ij < t; ++ij) {
						x += ii[d];
						y += jj[d];
						used[x][y] = 1;
					}
					se[x][y][(d + 1) & 7] = 1;
					se[x][y][(d + 7) & 7] = 1;
				}
			}
		}
		fi.swap(se);
		// if (_ == 2) {
		// 	show(fi);
		// }
	}

	int ans = 0;
	for (int i = 0; i < SZ + SZ + 1; ++i) {
		for (int j = 0; j < SZ + SZ + 1; ++j) {
			ans += (int)(used[i][j]);
		}
	}

	printf("%d\n", ans);

	return 0;
}