#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


void finish(vector<vector<int>> &f) {
	cout << sz(f) << '\n';
	fornr(i, sz(f)) {
		forn(j, sz(f)) {
			if (f[i][j] == 1) {
				cout << 'o';
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
	exit(0);
}

void check(int n, int h) {
	if (h * h < n) return;
	if (h * 2 - 1 > n) return;
	vector<vector<int>> f(h);
	forn(i, h) {
		f[i].assign(h, 0);
	}
	int cnt = 2 * h - 1;
	forn(i, h) f[i][0] = 1;
	forn(i, h) f[0][i] = 1;
	
	if (cnt == n) finish(f);
	for(int i = 1; i < h; i++) {
		for(int j = i; j < h; j++) {
			cnt++;
			f[i][j] = 1;
			if (i != j) {
				cnt++;
				f[j][i] = 1;
			}
			if (cnt == n) {
				finish(f);
			}
			if (cnt == n + 1) {
				if (i != j && j > i + 1) {
					f[i][j] = 0;
					f[j][i] = 0;
					f[i + 1][i + 1] = 1;
					finish(f);
				}
				if (i != j && i - 1 >= 0 && j < h - 1) {
					f[i - 1][h - 1] = 0;
					f[h - 1][i - 1] = 0;
					f[i + 1][i + 1] = 1;
					finish(f);
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	forab(h, 1, 101) {
		check(n, h);
	}
	cout << -1 << '\n';
	
	return 0;
}