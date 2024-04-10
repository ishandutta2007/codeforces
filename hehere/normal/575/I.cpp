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

const int maxN = 100000 + 5;
const int maxM = 5000 + 5;
int n, m, ans[maxN];
struct Asker {
	int dir, x, y, len;
} qs[maxN];

template<int maxN>
struct Solve {
	bitset<maxN> x[maxM], y[maxM], z[maxM * 2], f;
	void solve(int dir) {
//		printf("solve dir = %d\n", dir);
		for(int i = 1, c = 0; i <= n; ++i) if(qs[i].dir == dir) {
			x[qs[i].x][c] = true;
			y[qs[i].y][c] = true;
			z[qs[i].x + qs[i].y + qs[i].len][c] = true;
//			printf("push %d %d %d as %d\n", qs[i].x, qs[i].y, qs[i].x + qs[i].y + qs[i].len * 2, c);
			++c;
		}
		for(int i = 1; i < maxM; ++i) x[i] |= x[i - 1], y[i] |= y[i - 1];
		for(int i = maxM * 2 - 2; i >= 0; --i) z[i] |= z[i + 1];
		for(int i = 1, c = 0; i <= n; ++i) {
			if(qs[i].dir == dir) {
				f[c] = true;
//				printf("push %d\n", c);
				++c;
			} else if(qs[i].dir == 0) {
//				printf("(i = %d)query %d %d\n", i, qs[i].x, qs[i].y);
//				cout << x[qs[i].x] << " " << y[qs[i].y] << " " << z[qs[i].x + qs[i].y] << " " << f << endl;
//				display((x[qs[i].x] & y[qs[i].y] & z[qs[i].x + qs[i].y] & f).count());
				ans[i] += (x[qs[i].x] & y[qs[i].y] & z[qs[i].x + qs[i].y] & f).count();
			}
		}
	}
};

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> m >> n;
	for(int i = 1; i <= n; ++i) {
		int op; cin >> op;
		if(op == 1) {
			cin >> qs[i].dir >> qs[i].x >> qs[i].y >> qs[i].len;
		} else if(op == 2) {
			cin >> qs[i].x >> qs[i].y;
			qs[i].dir = 0;
		} else {
			assert(false);
		}
	}
	memset(ans, 0, sizeof(ans));
	for(int dir = 1; dir <= 4; ++dir) {
		if(dir == 2 || dir == 4)
			for(int i = 1; i <= n; ++i) qs[i].y = m + 1 - qs[i].y;
		if(dir == 3 || dir == 4)
			for(int i = 1; i <= n; ++i) qs[i].x = m + 1 - qs[i].x;
		
		int cnt = 0;
		for(int i = 1; i <= n; ++i) cnt += (qs[i].dir == dir);
		if(cnt <= 10) (new Solve<10>)->solve(dir);
		else if(cnt <= 10000) (new Solve<10000>)->solve(dir);
		else if(cnt <= 30000) (new Solve<30000>)->solve(dir);
		else if(cnt <= 60000) (new Solve<60000>)->solve(dir);
		else (new Solve<100000>)->solve(dir);
		
		if(dir == 2 || dir == 4)
			for(int i = 1; i <= n; ++i) qs[i].y = m + 1 - qs[i].y;
		if(dir == 3 || dir == 4)
			for(int i = 1; i <= n; ++i) qs[i].x = m + 1 - qs[i].x;
	}
	for(int i = 1; i <= n; ++i) if(qs[i].dir == 0) cout << ans[i] << '\n';
	return 0;
}