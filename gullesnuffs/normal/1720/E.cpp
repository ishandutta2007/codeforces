#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a-1; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int>> a;
vector<int> cnt;
int different;
int x, y, m, n, k;

void bruteforce() {
	cerr << "x = " << x << endl;
	cerr << "y = " << y << endl;
	cerr << "m = " << m << endl;
	cerr << "different = " << different << endl;
	set<int> s;
	rep(i,0,n)
	rep(j,0,n) {
		if (i >= x && j >= y && i < x+m && j < y+m)
			continue;
		s.insert(a[i][j]);
	}
	if (different != sz(s)) {
		/*cerr << "x = " << x << endl;
		cerr << "y = " << y << endl;
		cerr << "m = " << m << endl;
		cerr << "different = " << different << endl;*/
		cerr << "should be " << sz(s) << endl;
		assert(false);
	}
}

void check() {
	assert(x >= 0);
	assert(y >= 0);
	assert(x+m <= n);
	assert(y+m <= n);
	if (different == k || different == k-1) {
		cout << 1 << endl;
		exit(0);
	}
	//bruteforce();
}

void increment_x() {
	check();
	rep(j,y,y+m) {
		if (!(--cnt[a[x+m][j]])) {
			--different;
		}
	}
	rep(j,y,y+m) {
		if (!(cnt[a[x][j]]++)) {
			++different;
		}
	}
	++x;
	check();
}

void decrement_x() {
	check();
	--x;
	rep(j,y,y+m) {
		if (!(--cnt[a[x][j]])) {
			--different;
		}
		if (!(cnt[a[x+m][j]]++)) {
			++different;
		}
	}
	check();
}

void increment_y() {
	check();
	rep(i,x,x+m) {
		if (!(--cnt[a[i][y+m]])) {
			--different;
		}
		if (!(cnt[a[i][y]]++)) {
			++different;
		}
	}
	++y;
	check();
}

void decrement_y() {
	check();
	--y;
	rep(i,x,x+m) {
		if (!(--cnt[a[i][y]])) {
			--different;
		}
		if (!(cnt[a[i][y+m]]++)) {
			++different;
		}
	}
	check();
}

void decrement_m() {
	check();
	--m;
	rep(i,x,x+m) {
		if (!(cnt[a[i][y+m]]++)) {
			++different;
		}
	}
	rep(j,y,y+m+1) {
		if (!(cnt[a[x+m][j]]++)) {
			++different;
		}
	}
	check();
}

void increment_m() {
	check();
	rep(i,x,x+m) {
		if (!(--cnt[a[i][y+m]])) {
			--different;
		}
	}
	rep(j,y,y+m+1) {
		if (!(--cnt[a[x+m][j]])) {
			--different;
		}
	}
	++m;
	check();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> k;
	a = vector<vector<int>>(n, vector<int>(n));
	cnt = vector<int>(n*n+1);
	rep(i,0,n)
		rep(j,0,n)  {
			cin >> a[i][j];
			if (!cnt[a[i][j]]) {
				++different;
			}
			cnt[a[i][j]]++;
		}
	if (different <= k) {
		cout << k-different << endl;
		return 0;
	}
	x = n-1;
	y = 0;
	m = 0;
	while (true) {
		while (true) {
			set<int> tested_m;
			tested_m.insert(m);
			while (true) {
				int new_m;
				if (different > k) {
					new_m = m+1;
				} else {
					new_m = m-1;
				}
				if (new_m+max(x, y) > n) {
					break;
				}
				if (tested_m.count(new_m)) {
					break;
				}
				if (new_m > m) {
					increment_m();
				} else {
					decrement_m();
				}
				tested_m.insert(m);
			}
			if ((x%2) == (n-1)%2) {
				if (y == n-1)
					break;
				if (y+m == n) {
					decrement_m();
				}
				increment_y();
			} else {
				if (y == 0) {
					break;
				}
				decrement_y();
			}
		}
		if (x == 0)
			break;
		decrement_x();
	}
	cout << 2 << endl;
}