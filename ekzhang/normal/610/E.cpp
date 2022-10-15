#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXSEG 524288
int N, M, K;
string s, p;
int st[MAXSEG][10][10];
int lazy[MAXSEG];
int bl[MAXSEG], br[MAXSEG];
int qr[10][10];
// int ord[10];

void push(int node, int lo, int hi) {
	// Usage: push(node, lo, hi);
	if (lazy[node] == -1) return;
	bl[node] = br[node] = lazy[node];
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			st[node][i][j] = 0;
		}
	}
	st[node][lazy[node]][lazy[node]] = hi - lo;
	if (lo != hi) {
		lazy[2 * node + 1] = lazy[node];
		lazy[2 * node + 2] = lazy[node];
	}
	lazy[node] = -1;
}

void merge(int node) {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			st[node][i][j] = st[2 * node + 1][i][j] + st[2 * node + 2][i][j];
		}
	}
	st[node][br[2 * node + 1]][bl[2 * node + 2]]++;
	bl[node] = bl[2 * node + 1];
	br[node] = br[2 * node + 2];
}

void init(int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	lazy[node] = -1;
	if (lo == hi) {
		int c = s[lo] - 'a';
		bl[node] = br[node] = c;
		return;
	}
	int mid = (lo + hi) / 2;
	init(lo, mid, 2 * node + 1);
	init(mid + 1, hi, 2 * node + 2);
	merge(node);
}

void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(node, lo, hi);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		lazy[node] = x;
		push(node, lo, hi);
	// error(lo, hi, st[node][0][0]);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	merge(node);
	// error(lo, hi, st[node][0][0], bl[node], br[node]);
}

void query(int s, int e, int lo=0, int hi=-1, int node=0) {
	// memset(qr, 0, sizeof qr) before calling this code
	if (hi == -1) hi = N - 1;
	push(node, lo, hi);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				qr[i][j] += st[node][i][j];
			}
		}
		return;
	}
	int mid = (lo + hi) / 2;
	query(s, e, lo, mid, 2 * node + 1);
	query(s, e, mid + 1, hi, 2 * node + 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	cin >> s;
	init();
	for (int q = 0; q < M; q++) {
		int t; cin >> t;
		if (t == 1) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			l--; r--;
			update_range(l, r, c - 'a');
		}
		else {
			cin >> p;
			memset(qr, 0, sizeof qr);
			query(0, N - 1);
			int ans = 1;
			for (int i = 0; i < K; i++) {
				for (int j = i; j < K; j++) {
					int c1 = p[i] - 'a';
					int c2 = p[j] - 'a';
					// error(c2, c1, qr[c2][c1]);
					ans += qr[c2][c1];
				}
			}
			cout << ans << '\n';
		}
	}

	cout.flush();
	return 0;
}