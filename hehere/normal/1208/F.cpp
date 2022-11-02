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

const int maxN = 1000000 + 5;
const int maxA = (1 << 21) + 5;
int n, a[maxN];

pii p[maxA];
void update(int w, int q) {
	if(q > p[w].first) p[w].second = p[w].first, p[w].first = q;
	else chmax(p[w].second, q);
}

int main() {
#ifndef LOCAL 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int S = 0; S < (1 << 21); ++S) p[S] = pii(0, 0);
	for(int i = 1; i <= n; ++i) update(a[i], i);
	for(int i = 0; i < 21; ++i)
		for(int S = 0; S < (1 << 21); ++S)
			if(S >> i & 1) {
				update(S ^ (1 << i), p[S].first);
				update(S ^ (1 << i), p[S].second);
			}
	int ans = 0;
	for(int i = 1; i + 2 <= n; ++i) {
		int more = 0;
		for(int j = 21 - 1; j >= 0; --j) if((a[i] >> j & 1) == 0) {
			if(p[more | (1 << j)].second > i)
				more |= (1 << j);
		}
		chmax(ans, a[i] | more);
	}
	cout << ans << endl;
	return 0;
}