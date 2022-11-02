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

int A[4][4] = {
{0, 1, 2, 3}, {7, 4, 5, 6}, {10, 11, 8, 9}, {13, 14, 15, 12}
};
int G[1024][1024];

int main() {
#ifndef LOCAL 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int n;
	cin >> n;
	int b = 0;
	for(int i = 0; i < n; i += 4) {
		for(int j = 0; j < n; j += 4) {
			for(int x = 0; x < 4; ++x) for(int y = 0; y < 4; ++y)
				G[i + x][j + y] = A[x][y] + b;
			b += 16;
		}
	}
	for(int i = 0; i < n; ++i) {
		int sum = 0, mus = 0;
		for(int j = 0; j < n; ++j) {
			sum ^= G[i][j];
			mus ^= G[j][i];
		}
		assert(sum == 0); assert(mus == 0);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	return 0;
}