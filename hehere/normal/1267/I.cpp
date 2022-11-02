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

const int maxN = 100 + 5;
int n;

bool cmp(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	char c; cin >> c;
	bool r = (c == '>');
//	store[x][y] = r; store[y][x] = !r;
	assert(c == '>' || c == '<');
	return r;
}

int p[maxN][2];

void make(int p[], int x, int y) {
	if(cmp(x, y)) p[0] = x, p[1] = y;
	else p[0] = y, p[1] = x;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) make(p[i], i, i + n);
	
	int total = 2 * n;
	while(total > n) {
		if(total > n + 1 || n % 2 == 1) {
			int sm = 1;
			for(int i = 2; i <= total / 2; ++i) {
				if(cmp(p[sm][1], p[i][1])) sm = i;
			}
			p[sm][1] = 0;
			if(total % 2 == 1) make(p[sm], p[sm][0], p[(total + 1) / 2][0]);
			else swap(p[sm][0], p[total / 2][0]), swap(p[sm][1], p[total / 2][1]);
			total--;
		} else {
			int sm = 1;
			for(int i = 2; i <= total / 2; ++i) {
				if(cmp(p[sm][1], p[i][1])) sm = i;
			}
			cmp(p[sm][1], p[(total + 1) / 2][0]);
			total--;
		}
	}
	cout << '!' << endl;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}