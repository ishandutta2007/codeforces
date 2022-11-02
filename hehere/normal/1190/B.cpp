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

const string win = "sjfnb";
const string lose = "cslnb";
const int maxN = 100000 + 5;
int n, a[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int equ = 0;
	for(int i = 2; i <= n; ++i) equ += (a[i] == a[i - 1]);
	if(equ >= 2) {
		cout << lose << endl; return 0;
	}
	a[0] = -1;
	for(int i = 2; i <= n; ++i) if(a[i] == a[i - 1] && a[i - 2] + 1 == a[i - 1]) {
		cout << lose << endl; return 0;
	}
	long long tot = 0;
	for(int i = 1; i <= n; ++i) tot += (a[i] - (i - 1));
	if(tot & 1) cout << win << endl; else cout << lose << endl;
	return 0;
}