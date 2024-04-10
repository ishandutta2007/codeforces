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
int f[maxN][maxN][maxN];

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	memset(f, 0, sizeof(f));
	for(int i = 0; i < maxN; ++i)
		for(int j = 0; j < maxN; ++j)
			for(int k = 0; k < maxN; ++k) {
				if(i >= 1 && j >= 2) chmax(f[i][j][k], f[i - 1][j - 2][k] + 3);
				if(j >= 1 && k >= 2) chmax(f[i][j][k], f[i][j - 1][k - 2] + 3);
			}
	int T; cin >> T;
	while(T--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << f[a][b][c] << endl;
	}
	return 0;
}