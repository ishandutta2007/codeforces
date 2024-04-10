#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

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

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6+1;

vector<int> adj[N];
int parent[N];
int depth[N];
int start[N];
int length[N];
int freq[N];

void update(int x, int cnt) {
	for ( ; x<N; x += x&-x)
		freq[x] += cnt;
}
void update(int lx, int rx, int cnt) {
	update(lx, cnt);
	update(rx, -cnt);
}
int query(int x) {
	int res = 0;
	for ( ; x>0; x -= x&-x)
		res += freq[x];
	return res;
}

int id = 1;
void euler_tour(int cur, int par=0) {
	parent[cur] = par;
	depth[cur] = depth[par]+1;
	start[cur] = id++;
	length[cur] = 1;
	update(start[cur], start[cur]+1, depth[cur]);
	for (int x : adj[cur]) {
		if (x != par) {
			euler_tour(x, cur);
			length[cur] += length[x];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	//cin >> n >> k;
	read(n); read(k);

	for (int i=1; i<n; i++) {
		int a, b;
		//cin >> a >> b;
		read(a); read(b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	depth[0] = -1;
	euler_tour(n);

	vector<bool> keep(n+1);
	keep[n] = true;
	int rem = n-k-1;
	for (int i=n-1; i>0; i--) {
		int len = query(start[i]);
		if (len <= rem) {
			rem -= len;
			for (int j=i; (len=query(start[j])) > 0; j = parent[j]) {
				keep[j] = true;
				update(start[j], start[j]+length[j], -1);
			}
		}
	}

	for (int i=1; i<=n; i++) {
		if (!keep[i]) cout << i << " ";
	}
	cout << nl;

	return 0;
}