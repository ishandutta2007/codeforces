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
int n;
vector<pii> vp;
vector<int> t;

int len = 0;
int px[maxN], py[maxN], pz[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int x; cin >> x;
		vp.emplace_back(x, i);
	}
	t.resize(n);
	for(int i = 0; i < n; ++i) cin >> t[i];
	sort(vp.begin(), vp.end());
	sort(t.begin(), t.end());
	LL sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += vp[i].first - t[i];
		if(sum > 0) {
			printf("NO\n"); return 0;
		}
	}
	if(sum != 0) {
		printf("NO\n"); return 0;
	}
	
	printf("YES\n");
	if(n == 1) {
		printf("0\n"); return 0;
	}
	int j = 0;
	for(int i = 0; i < n; ++i) {
		chmax(j, i + 1);
		while(vp[i].first < t[i]) {
			while(j + 1 < n && vp[j].first <= t[j]) ++j;
			int dl = t[i] - vp[i].first;
			int dr = vp[j].first - t[j];
			int d = min(dl, dr);
//			printf("%d %d %d\n", vp[i].second, vp[j].second, d);
			px[len] = vp[i].second; py[len] = vp[j].second;
			pz[len] = d;
			vp[i].first += d; vp[j].first -= d;
			++len;
		}
	}
	printf("%d\n", len);
	for(int i = 0; i < len; ++i) {
		printf("%d %d %d\n", px[i], py[i], pz[i]);
	}
	return 0;
}