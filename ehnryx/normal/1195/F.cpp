#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}
// END MAGIC IO

struct Point {
	int x, y;
	bool operator < (const Point& o) const {
		if (x != o.x) return x < o.x;
		else return y < o.y;
	}
	Point operator - (const Point& o) const {
		return { x-o.x, y-o.y };
	}
	Point reduce() const {
		int g = abs(__gcd(x,y));
		return { x/g, y/g };
	}
};

const int M = 3e5+1;
const int N = 1e5+1;
const int S = 600;

int ans[N], pre[N], val[N];
int cnt[M];
vector<int> v[N];

struct Query {
	int i, l, r;
	bool operator < (const Query& o) const {
		if (val[l]/S != val[o.l]/S) return val[l]/S < val[o.l]/S;
		else return (val[l]/S % 2 == 0 ? val[r] < val[o.r] : val[r] > val[o.r]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	//cin >> n;
	read(n);

	map<Point,int> remap;
	int id = 0;
	FOR(i,1,n) {
		int m;
		//cin >> m;
		read(m);
		pre[i] = pre[i-1] + m;
		val[i] = (pre[i]+pre[i-1])/2;
		vector<Point> p;
		For(j,m) {
			int x, y;
			//cin >> x >> y;
			read(x); read(y);
			p.push_back({x,y});
		}
		For(j,m) {
			int jj = (j+1==m ? 0 : j+1);
			Point cur = (p[jj]-p[j]).reduce();
			if (!remap.count(cur)) {
				remap[cur] = ++id;
			}
			v[i].push_back(remap[cur]);
		}
	}

	int q;
	//cin >> q;
	read(q);

	vector<Query> queries;
	For(i,q) {
		int l, r;
		//cin >> l >> r;
		read(l); read(r);
		queries.push_back({i,l,r});
	}
	sort(queries.begin(), queries.end());

	int left = 1;
	int right = 1;
	int res = 0;
	for (const Query& it : queries) {
		while (left > it.l) {
			--left;
			for (const int p : v[left]) {
				res += (cnt[p]++ == 0);
			}
		}
		while (right < it.r+1) {
			for (const int p : v[right]) {
				res += (cnt[p]++ == 0);
			}
			right++;
		}
		while (left < it.l) {
			for (const int p : v[left]) {
				res -= (--cnt[p] == 0);
			}
			left++;
		}
		while (right > it.r+1) {
			--right;
			for (const int p : v[right]) {
				res -= (--cnt[p] == 0);
			}
		}
		ans[it.i] = res;
	}

	For(i,q) {
		cout << ans[i] << nl;
	}

	return 0;
}