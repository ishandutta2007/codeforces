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

int main() {
	ios::sync_with_stdio(false);
	vector< pair< pii, int > > vp;
	vector< pair< pii, int > > vq;
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		if(x < y) vp.emplace_back(pii(x, y), i);
		else if(x > y) vq.emplace_back(pii(x, y), i);
	}
	sort(vp.begin(), vp.end());
	sort(vq.begin(), vq.end());
	if(vp.size() > vq.size()) {
		printf("%d\n", (int)vp.size());
		while(vp.size()) {
			printf("%d ", (int)vp.back().second);
			vp.pop_back();
		}
	} else {
		printf("%d\n", (int)vq.size());
		reverse(vq.begin(), vq.end());
		while(vq.size()) {
			printf("%d ", (int)vq.back().second);
			vq.pop_back();
		}
	}
	return 0;
}