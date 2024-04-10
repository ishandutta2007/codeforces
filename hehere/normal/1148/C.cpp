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

const int maxN = 300000 + 233;
int n, p[maxN], ip[maxN];

vector<pii> vp;
void swap(int x, int y) {
	eprintf("%d %d\n", x, y);
	vp.emplace_back(x, y);
	std::swap(p[x], p[y]);
	ip[p[x]] = x; ip[p[y]] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	for(int i = 1; i <= n; ++i) ip[p[i]] = i;
	for(int i = 1; i <= n / 2; ++i) {
		int t = ip[i];
		if(t == i) continue;
		if(t > n / 2) {
			if(t == n || i == 1) swap(t, i);
			else {
				swap(t, 1);
				swap(1, n);
				swap(n, i);
				swap(1, t);
			}
		} else {
			swap(t, n);
			swap(n, i);
		}
	}

	for(int i = n / 2 + 1; i <= n; ++i) {
		int t = ip[i];
		if(t == i) continue;
		swap(t, 1);
		swap(1, i);
		swap(1, t);
	}
	displaya(p, 1, n);
	printf("%d\n", (int)vp.size());
	for(auto p : vp) printf("%d %d\n", p.first, p.second);
	return 0;
}