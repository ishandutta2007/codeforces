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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 805;

string s[N];
bool used[N][N];
int color[N][N], size[N * N], d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, Count[N * N];
int num = 0, n;

void dfs(int x, int y, int n, int c) {
	if (x < 0 || y < 0 || x >= n || y >= n || used[x][y] || s[x][y] == 'X')
		return;
	used[x][y] = 1;
	color[x][y] = c;
	size[c]++;
	forn(i, 4) {
		int xx = x + d[i][0], yy = y + d[i][1];
		dfs(xx, yy, n, c);
	}
}

void add_row(int x, int y, int k) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;
	forab(i, y, y + k) {
		int col = color[x][i];
		if (!col)
			continue;
		if (!Count[col])
			num += size[col];
		Count[col]++;
	}
}

void del_row(int x, int y, int k) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;
	forab(i, y, y + k) {
		int col = color[x][i];
		if (!col)
			continue;
		if (Count[col] == 1)
			num -= size[col];
		Count[col]--;
	}
}


void add_col(int x, int y, int k) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;
	forab(i, x, x + k) {
		int col = color[i][y];
		if (!col)
			continue;
		if (!Count[col])
			num += size[col];
		Count[col]++;
	}
}

void del_col(int x, int y, int k) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return;
	forab(i, x, x + k) {
		int col = color[i][y];
		if (!col)
			continue;
		if (Count[col] == 1)
			num -= size[col];
		Count[col]--;
	}
}

int Sum[N][N];

int get(int x, int y, int k) {
	if (x > n || y > n)
		return 1000000;
//	cerr << num << '\n';
//	cerr << x << " " << y << '\n';
	int sss = Sum[x][y] - Sum[x - k][y] - Sum[x][y - k] + Sum[x - k][y - k];
//	cerr << sss << '\n';
	return sss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n >> k;
	forn(i, n)
		cin >> s[i];
	forn(i, n) {
		forn(j, n) {
			Sum[i + 1][j + 1] = Sum[i][j + 1] + Sum[i + 1][j] - Sum[i][j];
			if (s[i][j] == '.')
				Sum[i + 1][j + 1]++;
		}
	}
	int cnt = 1;
	forn(i, n) {
		forn(j, n) {
			if (!color[i][j]) {
				dfs(i, j, n, cnt);
				cnt++;
			}
		}
	}
	int mx = 0;
	forn(i, k) {
		add_row(i, 0, k);
	}
	add_row(k, 0, k);
	add_col(0, k, k);
	mx = max(mx, num + k * k - get(k, k, k));
	forn(i, n - k + 1) {
		if (i & 1) {
			fornr(j, n - k) {
				add_col(i, j - 1, k);
				del_col(i, j + k + 1, k);
				del_row(i - 1, j + 1, k);
				add_row(i - 1, j, k);
				del_row(i + k, j + 1, k);
				add_row(i + k, j, k);
				mx = max(mx, num + k * k - get(i + k, j + k, k));
			}
			add_row(i + k + 1, 0, k);
			del_row(i - 1, 0, k);
			del_col(i, k, k);
			add_col(i + 1, k, k);
			mx = max(mx, num + k * k - get(i + k + 1, k, k));
			
		} else {
			forab(j, k, n) {
				add_col(i, j + 1, k);
				del_col(i, j - k - 1, k);
				del_row(i - 1, j - k, k);
				add_row(i - 1, j - k + 1, k);
				del_row(i + k, j - k, k);
				add_row(i + k, j - k + 1, k);
				mx = max(mx, num + k * k - get(i + k, j + 1, k));
			}		
			add_row(i + k + 1, n - k, k);
			del_row(i - 1, n - k, k);
			del_col(i, n - k - 1, k);
			add_col(i + 1, n - k - 1, k);
			mx = max(mx, num + k * k - get(i + k + 1, n, k));
			
		}
	}
	cout << mx << '\n';
	return 0;
}