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

const LL P = 1000000007;
LL qpow(LL a, LL b) {
	LL r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P; b >>= 1;
	}
	return r;
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int maxN = 8000;
int R, a[4];
map<pii, int> f;
int of[maxN];
vector<LL> G[maxN];
LL s[maxN], b[maxN];

int lb[maxN], rb[maxN];

int main() {
	cin >> R;
	for(int i = 0; i < 4; ++i) cin >> a[i];
	LL sum = accumulate(a, a + 4, 0);
	for(int i = 0; i < 4; ++i) a[i] = a[i] * qpow(sum, P - 2) % P;
	for(int x = -R - 10; x <= R + 10; ++x)
		for(int y = -R - 10; y <= R + 10; ++y)
			if(x * x + y * y <= R * R)
				f.emplace(pii(x, y), f.size());
	int n = f.size();
	memset(G, 0, sizeof(G));
	for(auto p : f) {
		int x = p.first.first, y = p.first.second;
		int id = p.second;
		lb[id] = rb[id] = id;
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx * nx + ny * ny > R * R) continue;
			chmin(lb[id], f[pii(nx, ny)]);
			chmax(rb[id], f[pii(nx, ny)]);
		}
	}
	for(int i = 1; i < n; ++i) chmax(rb[i], rb[i - 1]);
	for(int i = n - 2; i >= 0; --i) chmin(lb[i], lb[i + 1]);
	for(auto p : f) {
		int x = p.first.first, y = p.first.second;
		int id = p.second;
		of[id] = lb[id];
		G[id].assign(rb[id] - lb[id] + 1, 0);
//		printf("%d %d for id = %d\n", lef, rig, id);
		G[id][id - of[id]] = 1;
		for(int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx * nx + ny * ny <= R * R) {
				(G[id][f[pii(nx, ny)] - of[id]] -= a[i]) %= P;
			}
		}
        b[id] = 1;
	}
	for(int i = 0; i < n; ++i) {
		assert(G[i][i - of[i]] != 0);
		for(int j = i + 1; j < n; ++j) if(of[j] <= i) {
			LL coef = qpow(G[i][i - of[i]], P - 2) * G[j][i - of[j]] % P;
			if(coef == 0) continue;
			for(int k = i; k < of[i] + (int)G[i].size(); ++k)
			    (G[j][k - of[j]] -= G[i][k - of[i]] * coef) %= P;
			(b[j] -= b[i] * coef) %= P;
		}
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = i + 1; j < of[i] + (int)G[i].size(); ++j)
			(b[i] -= s[j] * G[i][j - of[i]]) %= P;
		s[i] = b[i] * qpow(G[i][i - of[i]], P - 2) % P;
	}
	LL ans = s[f[pii(0, 0)]];
	ans = (ans % P + P) % P;
	cout << ans << endl;
	return 0;
}