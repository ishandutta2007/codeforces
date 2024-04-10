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

const int maxN = 200000 + 233;
int n, a[maxN], t[maxN];
vector<pii> offs;

void update(int p, int T) {
	auto i = upper_bound(offs.begin(), offs.end(), pii(t[p], 0));
	if(i != offs.end()) chmax(a[p], i->second);
	t[p] = T;
}

int main() {
	ios::sync_with_stdio(false);
	offs.assign(1, pii(-1, -1));
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	memset(t, 0, sizeof(t));
	int q; cin >> q;
	for(int i = 1; i <= q; ++i) {
		int op; cin >> op;
		if(op == 1) {
			int p, x; cin >> p >> x;
			a[p] = x;
			t[p] = i;
		} else if(op == 2) {
			int x; cin >> x;
			while(offs.size() && offs.back().second <= x) offs.pop_back();
			offs.emplace_back(i, x);
		} else {
			assert(false);
		}
	}
	for(int i = 1; i <= n; ++i) update(i, q + 1);
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	printf("\n");
	return 0;
}