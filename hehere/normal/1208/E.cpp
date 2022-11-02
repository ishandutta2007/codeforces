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

const int maxN = 1000000 + 233;
int m;
LL a[maxN];

int n, b[maxN];
int q[maxN];
int d[maxN];
void play() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> b[i];
	for(int i = 1; i <= n; ++i) d[i] = d[m - i + 1] = -(int)1.1e9;
	int l = 0, r = 0;
	for(int i = 1; i <= n; ++i) {
		while(l < r && q[l] < i - (m - n)) ++l;
		while(l < r && b[q[r - 1]] < b[i]) --r;
		q[r++] = i;
		chmax(d[i], b[q[l]]);
//		display(q[l]); display(l);
//		display(d[i]);
	}
	l = 0, r = 0;
	for(int i = 1; i <= n; ++i) {
		while(l < r && q[l] < i - (m - n)) ++l;
		while(l < r && b[n - q[r - 1] + 1] < b[n - i + 1]) --r;
		q[r++] = i;
		chmax(d[m - i + 1], b[n - q[l] + 1]);
	}
	for(int i = 1; i <= n; ++i) {
		if(i + n <= m) chmax(d[i], 0), chmax(d[m - i + 1], 0);
	}
	for(int i = 1; i <= n; ++i) a[i] += d[i], a[i + 1] -= d[i];
	displaya(d, 1, m);
	for(int i = max(n + 1, m - n + 1); i <= m; ++i) a[i] += d[i], a[i + 1] -= d[i];
	int mx = max(*max_element(b + 1, b + n + 1), 0);
	if(n < m - n + 1) a[n + 1] += mx, a[m - n + 1] -= mx;
}

int main() {
#ifndef LOCAL 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	int n;
	cin >> n >> m;
	while(n--) {
		play();
	}
	for(int i = 1; i <= m; ++i) a[i] += a[i - 1];
	for(int i = 1; i <= m; ++i) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}