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

const int maxM = 100000 + 5;
LL n, k;
LL a[maxM];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	long long er = k - 1;
	int cnt = 0;
	for(int l = 1; l <= n; ++l) {
//		int seg = (a[l] + er + 1) / k;
		int r = l;
		while(r <= n && (a[l] + er) / k == (a[r] + er) / k) ++r;
		r--;
		er -= (r - l + 1);
		while(er < 0) er += k;
		++cnt;
		l = r;
	}
	cout << cnt << endl;
	return 0;
}