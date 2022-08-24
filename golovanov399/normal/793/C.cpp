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

struct Ratio {
	long long x, y;

	bool operator <(const Ratio& ot) const {
		return x * ot.y < ot.x * y;
	}
};

int main(){
	int n = nxt();
	int x1 = nxt(), y1 = nxt(), x2 = nxt(), y2 = nxt();
	vector<vector<int>> a(n, vector<int>(4, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = nxt();
		}
	}

	Ratio tmin = {0, 1};
	Ratio tmax = {10000000000ll, 1};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (a[i][2] < 0) {
				a[i][2] *= -1;
				a[i][0] = x1 + x2 - a[i][0];
			}
			if (a[i][2] == 0) {
				if (a[i][0] <= x1 || a[i][0] >= x2) {
					puts("-1");
					return 0;
				}
			} else {
				if (a[i][0] >= x2) {
					puts("-1");
					return 0;
				} else {
					if (a[i][0] < x1) {
						Ratio nw = {x1 - a[i][0], a[i][2]};
						if (tmin < nw) {
							tmin = nw;
						}
					}

					Ratio nw = {x2 - a[i][0], a[i][2]};
					if (nw < tmax) {
						tmax = nw;
					}
				}
			}

			swap(a[i][0], a[i][1]);
			swap(a[i][2], a[i][3]);
			swap(x1, y1);
			swap(x2, y2);
		}
	}

	if (!(tmin < tmax)) {
		puts("-1");
		return 0;
	}

	cout << setprecision(10) << fixed;
	cout << 1.0 * tmin.x / tmin.y << "\n";

	return 0;
}