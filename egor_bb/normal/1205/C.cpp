#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 50;

int a[N][N];
int poss[N][N][2];
int got[N][N][N][N][2];

string test[] = {
"1101111010101",
"0101001010101",
"1001010101110",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"1111010101101",
"0010101010100"
};

int cnt = 0;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	int res; cin >> res;
	return res;
}

int ask2(int x1, int y1, int x2, int y2) {
	cnt++;
	//cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	//int res; cin >> res;
	return test[x1][y1] == test[x2][y2];
}

bool valid(int x1, int y1, int x2, int y2) {
	return x1 <= x2 && y1 <= y2;
}

void compute(int x1, int y1, int x2, int y2) {
	if (got[x1][y1][x2][y2][0] != -1) return;
	if (x1 == x2 && y1 == y2) {
		got[x1][y1][x2][y2][0] = got[x1][y1][x2][y2][1] = 1;
		return;
	}
	if ((x2 - x1) + (y2 - y1) == 1) {
		forn(b, 2) {
			got[x1][y1][x2][y2][b] = poss[x1][y1][b] == poss[x2][y2][b];
		}
		return;
	}
	forn(b, 2) {
		got[x1][y1][x2][y2][b] = 0;
		if (poss[x1][y1][b] != poss[x2][y2][b]) got[x1][y1][x2][y2][b] = 0;
		else {
			int dx1, dy1, dx2, dy2;
			dx1 = 1, dy1 = 0, dx2 = -1, dy2 = 0;
			if (valid(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2)) {
				compute(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2);
				if (got[x1 + dx1][y1 + dy1][x2 + dx2][y2 + dy2][b]) {
					got[x1][y1][x2][y2][b] = 1;
				}
			}
			dx1 = 0, dy1 = 1, dx2 = -1, dy2 = 0;
			if (valid(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2)) {
				compute(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2);
				if (got[x1 + dx1][y1 + dy1][x2 + dx2][y2 + dy2][b]) {
					got[x1][y1][x2][y2][b] = 1;
				}
			}
			dx1 = 1, dy1 = 0, dx2 = 0, dy2 = -1;
			if (valid(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2)) {
				compute(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2);
				if (got[x1 + dx1][y1 + dy1][x2 + dx2][y2 + dy2][b]) {
					got[x1][y1][x2][y2][b] = 1;
				}
			}
			dx1 = 0, dy1 = 1, dx2 = 0, dy2 = -1;
			if (valid(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2)) {
				compute(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2);
				if (got[x1 + dx1][y1 + dy1][x2 + dx2][y2 + dy2][b]) {
					got[x1][y1][x2][y2][b] = 1;
				}
			}
		}
	}
}

void printans(int b, int n) {
	cout << "!\n";
	forn(i, n) {
		forn(j, n) {
			cout << poss[i][j][b];
		}
		cout << '\n';
	}
	cout.flush();
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	a[0][0] = 1;
	a[n - 1][n - 1] = 0;
	for(int i = 2; i < n; i += 2) {
		int x = i, y = 0;
		int res = ask(x - 2, y, x, y);
		if (res) a[x][y] = a[x - 2][y];
		else a[x][y] = 1 - a[x - 2][y];
		
		x = 0, y = i;
		res = ask(x, y - 2, x, y);
		if (res) a[x][y] = a[x][y - 2];
		else a[x][y] = 1 - a[x][y - 2];
	}
//	cout << cnt << '\n';
	for(int i = 2; i < n - 1; i += 2) {
		int x = i, y = n - 1;
		int res = ask(x - 2, y, x, y);
		if (res) a[x][y] = a[x - 2][y];
		else a[x][y] = 1 - a[x - 2][y];
		
		x = n - 1, y = i;
		res = ask(x, y - 2, x, y);
		if (res) a[x][y] = a[x][y - 2];
		else a[x][y] = 1 - a[x][y - 2];
	}
//	cout << cnt << '\n';
	for (int x = 1; x <= n - 2; x++) {
		for (int y = 1; y <= n - 2; y++) {
			if (x % 2 != y % 2) continue;
			int res = ask(x - 1, y - 1, x, y);
			if (res) a[x][y] = a[x - 1][y - 1];
			else a[x][y] = 1 - a[x - 1][y - 1];
		}
	}
//	cout << cnt << '\n';
	/*forn(i, n) {
		forn(j, n) {
			cout << a[i][j];
		}
		cout << '\n';
	}
	cout << '\n';*/
	forn(i, n) {
		forn(j, n) {
			poss[i][j][0] = poss[i][j][1] = a[i][j];
		}
	}
	poss[1][0][0] = 0;
	poss[1][0][1] = 1;
	for(int i = 3; i < n; i += 2) {
		int x = i, y = 0;
		int res = ask(x - 2, y, x, y);
		if (res) {
			poss[x][y][0] = poss[x - 2][y][0];
			poss[x][y][1] = poss[x - 2][y][1];
		} else {
			poss[x][y][0] = 1 - poss[x - 2][y][0];
			poss[x][y][1] = 1 - poss[x - 2][y][1];
		}
		
		x = 1, y = i - 1;
		res = ask(x, y - 2, x, y);
		if (res) {
			poss[x][y][0] = poss[x][y - 2][0];
			poss[x][y][1] = poss[x][y - 2][1];
		} else {
			poss[x][y][0] = 1 - poss[x][y - 2][0];
			poss[x][y][1] = 1 - poss[x][y - 2][1];
		}
	}
//	cout << cnt << '\n';
	for(int i = 3; i < n; i += 2) {
		int x = i, y = n - 3;
		int res = ask(x - 2, y, x, y);
		if (res) {
			poss[x][y][0] = poss[x - 2][y][0];
			poss[x][y][1] = poss[x - 2][y][1];
		} else {
			poss[x][y][0] = 1 - poss[x - 2][y][0];
			poss[x][y][1] = 1 - poss[x - 2][y][1];
		}
		if (i != n - 2) {
			x = n - 2, y = i - 1;
			res = ask(x, y - 2, x, y);
			if (res) {
				poss[x][y][0] = poss[x][y - 2][0];
				poss[x][y][1] = poss[x][y - 2][1];
			} else {
				poss[x][y][0] = 1 - poss[x][y - 2][0];
				poss[x][y][1] = 1 - poss[x][y - 2][1];
			}
		}
	}
	
//	cout << cnt << '\n';
	for (int x = 2; x <= n - 1; x++) {
		for (int y = 1; y <= n - 2; y++) {
			if (x % 2 == y % 2 || x == n - 2 || y == n-3) continue;
			int res = ask(x - 1, y - 1, x, y);
			if (res) {
				poss[x][y][0] = poss[x - 1][y - 1][0];
				poss[x][y][1] = poss[x - 1][y - 1][1];
			} else {
				poss[x][y][0] = 1 - poss[x - 1][y - 1][0];
				poss[x][y][1] = 1 - poss[x - 1][y - 1][1];
			}
		}
	}
//	cout << cnt << '\n';
	
	for (int y = 1; y <= n - 4; y += 2) {
		int x = 0;
		int res = ask(x, y, x + 1, y + 1);
		if (res) {
			poss[x][y][0] = poss[x + 1][y + 1][0];
			poss[x][y][1] = poss[x + 1][y + 1][1];
		} else {
			poss[x][y][0] = 1 - poss[x + 1][y + 1][0];
			poss[x][y][1] = 1 - poss[x + 1][y + 1][1];
		}
	}
	
	for (int x = 3; x <= n - 2;  x += 2) {
		int y = n - 1;
		int res = ask(x - 1, y - 1, x, y);
		if (res) {
			poss[x][y][0] = poss[x - 1][y - 1][0];
			poss[x][y][1] = poss[x - 1][y - 1][1];
		} else {
			poss[x][y][0] = 1 - poss[x - 1][y - 1][0];
			poss[x][y][1] = 1 - poss[x - 1][y - 1][1];
		}
	}
	if (n >= 3) {
		int x = 1;
		int y = n - 1;
		int res = ask(x, y - 2, x, y);
		if (res) {
			poss[x][y][0] = poss[x][y - 2][0];
			poss[x][y][1] = poss[x][y - 2][1];
		} else {
			poss[x][y][0] = 1 - poss[x][y - 2][0];
			poss[x][y][1] = 1 - poss[x][y - 2][1];
		}
		x = 0;
		y = n - 2;
		res = ask(x, y, x + 1, y + 1);
		if (res) {
			poss[x][y][0] = poss[x + 1][y + 1][0];
			poss[x][y][1] = poss[x + 1][y + 1][1];
		} else {
			poss[x][y][0] = 1 - poss[x + 1][y + 1][0];
			poss[x][y][1] = 1 - poss[x + 1][y + 1][1];
		}
		
		
	}
	
	forn(x1, N) {
		forn(y1, N) {
			forn(x2, N) {
				forn(y2, N) {
					forn(b, 2)
						got[x1][y1][x2][y2][b] = -1;
				}
			}
		}
	}
	/*forn(b, 2) {
		forn(i, n) {
			forn(j, n) {
				cout << poss[i][j][b];
			}
		cout << '\n';
		}
		cout << '\n';
	}
	cout << cnt << '\n';*/
	forn(x1, n) {
		forn(y1, n) {
			forn(x2, n) {
				forn(y2, n) {
					if (valid(x1, y1, x2, y2)) {
						compute(x1, y1, x2, y2);
						if ((x2 - x1) + (y2 - y1) >= 2 && got[x1][y1][x2][y2][0] != got[x1][y1][x2][y2][1]) {
							//cout << got[x1][y1][x2][y2][0] << " " << got[x1][y1][x2][y2][1] << '\n';
							int res = ask(x1, y1, x2, y2);
							if (res == got[x1][y1][x2][y2][0]) {
								printans(0, n);
							} else {
								printans(1, n);
							}
						}
					}
				}
			}
		}
	}
//	cout << got[0][0][1][2][0] << " " << got[0][0][1][2][1] << '\n';
	return 0;
}