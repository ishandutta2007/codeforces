#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int INF = 1e9 + 10;

vector<int> a[3][3];

int main(){
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			a[i][j] = {INF};
		}
	}

	int n = nxt();
	vector<int> p(n), ar(n), br(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		ar[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		br[i] = nxt() - 1;
	}

	for (int i = 0; i < n; ++i) {
		a[ar[i]][br[i]].push_back(p[i]);
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			sort(all(a[i][j]));
			reverse(all(a[i][j]));
		}
	}

	int m = nxt();
	while (m--) {
		int c = nxt() - 1;
		int res = INF;
		for (int i = 0; i < 3; ++i) {
			res = min(res, a[i][c].back());
			res = min(res, a[c][i].back());
		}
		if (res == INF) {
			res = -1;
		} else {
			for (int i = 0; i < 3; ++i) {
				if (a[i][c].back() == res) {
					a[i][c].pop_back();
				}
				if (a[c][i].back() == res) {
					a[c][i].pop_back();
				}
			}
		}
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}