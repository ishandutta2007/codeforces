#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxN = 20 + 2;
int n, m, sx, sy;
char b[maxN][maxN];
int f[maxN][maxN][1 << 8];
int val[8];
int cnt = 0;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int encode(int x, int y, int S) {
	return x << 20 | y << 10 | S;
}
void decode(int code, int &x, int &y, int &S) {
	x = code >> 20;
	code ^= (x << 20);
	y = code >> 10;
	code ^= (y << 10);
	S = code;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> (b[i] + 1);
	for(int i = 0; i <= n + 1; ++i) b[i][0] = b[i][m + 1] = '#';
	for(int j = 0; j <= m + 1; ++j) b[0][j] = b[n + 1][j] = '#';
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			if(isdigit(b[i][j])) {
				chmax(cnt, b[i][j] - '0');
				b[i][j]--;
			}
		}
	for(int i = 0; i < cnt; ++i) cin >> val[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			if(b[i][j] == 'S') sx = i, sy = j, b[i][j] = '.';
			else if(b[i][j] == 'B') {
				b[i][j] = '0' + cnt;
				val[cnt++] = -200 * 8;
			}
		}
	memset(f, 0x3f, sizeof(f));
	f[sx][sy][0] = 0;
	queue<int> q;
	q.push(encode(sx, sy, 0));
	while(q.size()) {
		int code = q.front(); q.pop();
		int x, y, S;
		decode(code, x, y, S);
//		eprintf("%d %d %d\n", x, y, S);
		
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if(b[nx][ny] != '.') continue;
			int tog = 0;
			if(i == 1)
				for(int t = 1; t < x; ++t) if(isdigit(b[t][y]))
					tog ^= (1 << (b[t][y] - '0'));
			if(i == 3)
				for(int t = 1; t < x; ++t) if(isdigit(b[t][y - 1]))
					tog ^= (1 << (b[t][y - 1] - '0'));
			if(chmin(f[nx][ny][S ^ tog], f[x][y][S] + 1))
				q.push(encode(nx, ny, S ^ tog));
		}
	}
	int ans = 0;
	for(int S = 0; S < (1 << cnt); ++S) {
		int tot = -f[sx][sy][S];
		for(int i = 0; i < cnt; ++i) if(S >> i & 1) tot += val[i];
		chmax(ans, tot);
	}
	cout << ans << endl;
	return 0;
}