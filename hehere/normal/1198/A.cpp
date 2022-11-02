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

const int maxN = 400000 + 5;
int n;
LL w;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> w;
	w = w * 8;
	map<int, int> f;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int l = 0;
	int ans = n;
	auto cost = [&](int x) {
		int b = 0;
		while((1 << b) < x) ++b;
		return (LL)b * n;
	};
//	display(cost(2));
//	display(cost(3));
	for(int i = 0; i < n; ++i) {
		f[a[i]]++;
		while(cost(f.size()) > w) {
			f[a[l]]--;
			if(f[a[l]] == 0) f.erase(f.find(a[l]));
			++l;
		}
//		printf("%d %d\n", l, i);
//		for(auto p : f) printf("%d %d\n", p.first, p.second);
//		cout << endl;
		chmin(ans, n - i + l - 1);
	}
	cout << ans << endl;
	return 0;
}