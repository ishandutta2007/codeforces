#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << (x) << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << ((a)[qwq]);\
		else cerr << ", " << ((a)[qwq]);\
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
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

const int maxN = 1000 + 5;
int n, m;
char b[maxN][maxN];
int cc[maxN], cr[maxN];
int pc[maxN], pr[maxN];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
void dfs(int x, int y) {
	b[x][y] = '.';
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(b[nx][ny] == '#') dfs(nx, ny);
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	memset(b, '.', sizeof(b));
	for(int i = 1; i <= n; ++i) cin >> (b[i] + 1);
	for(int i = 1; i <= n; ++i) b[i][m + 1] = '.';
	bool fail = false;
	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		for(int j = 1; j <= m; ++j) cnt += (b[i][j] == '#' && b[i][j - 1] == '.');
		fail |= (cnt > 1);
		cr[i] = cnt;
	}
	for(int j = 1; j <= m; ++j) {
		int cnt = 0;
		for(int i = 1; i <= n; ++i) cnt += (b[i][j] == '#' && b[i - 1][j] == '.');
		fail |= (cnt > 1);
		cc[j] = cnt;
	}
	if(fail) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			if(b[i][j] == '#') pr[i]++, pc[j]++;
			else if(cr[i] == 0 && cc[j] == 0) pr[i]++, pc[j]++;
		}
	for(int i = 1; i <= n; ++i) if(pr[i] == 0) {
		cout << -1 << endl;
		return 0;
	}
	for(int j = 1; j <= m; ++j) if(pc[j] == 0) {
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(b[i][j] == '#')
				ans++, dfs(i, j);
	cout << ans << endl;
	return 0;
}