#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << endl;
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
#define displaya(a, b, c) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, __VA_ARGS__)
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxK = 200000 + 233;
const LL P = 1926081700000000009;
int n, m, k;
vector<LL> f;
string s;
int cnt[26];

void inc(LL &x, LL y) { (x += y) >= P ? x -= P : 233; }
void dec(LL &x, LL y) { (x -= y) < 0 ? x += P : 233; }

void insert(int x) {
	for(int i = n - 1 - x; i >= 0; --i) inc(f[i + x], f[i]);
}
void erase(int x) {
	for(int i = 0; i <= n - 1 - x; ++i) dec(f[i + x], f[i]);
}

LL initialize() {
	cin >> n >> m >> k;
	cin >> s;
	memset(cnt, 0, sizeof(cnt));
	for(char c : s) { cnt[(int)c - 'A']++; }
	f.assign(n, 0); f[0] = 1;
	for(int i = 25; i >= 0; --i) if(cnt[i]) insert(cnt[i]);
	LL ans = (LL)n * m;
	for(int i = 0; i < 26; ++i) if(cnt[i]) {
		int d = cnt[i];
		erase(d);
		for(int j = n - 1; j >= n - d && j >= 0; --j) if(f[j]) {
			if(k - (j + d) >= m) return 0;
			chmin(ans, (n - j) * (LL)(m - k + j + d));
		}
		insert(d);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		cout << initialize() << '\n';
	}
	return 0;
}