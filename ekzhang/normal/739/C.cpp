#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 300013
#define MAXSEG 1048613

int N, M;
LL A[MAXN];
LL P[MAXN];
int T[MAXN];
int st[MAXSEG];
int stl[MAXSEG];
int str[MAXSEG];

inline int ty(LL x) {
	if (x>0) return 1;
	if (x<0) return -1;
	return 0;
}

void init(int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 2;
	if (lo == hi) {
		st[node] = stl[node] = str[node] = (T[lo] != 0);
		return;
	}
	int mid = (lo + hi) / 2;
	init(lo, mid, 2 * node + 1);
	init(mid + 1, hi, 2 * node + 2);

	// copypaste this
	bool b = !(T[mid] == -1 && T[mid+1] == 1) && T[mid] && T[mid+1]; // if it can extend
	stl[node] = stl[2 * node + 1];
	if (b && stl[2 * node + 1] == mid - lo + 1) stl[node] += stl[2 * node + 2];
	str[node] = str[2 * node + 2];
	if (b && str[2 * node + 2] == hi - mid) str[node] += str[2 * node + 1];
	st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	if (b) {
		st[node] = max(st[node], str[2 * node + 1] + stl[2 * node + 2]);
	}
}

void update(int i, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 2;
	if (lo > i || hi < i) {
		return;
	}
	if (lo == hi) {
		st[node] = stl[node] = str[node] = (T[lo] != 0);
		return;
	}
	int mid = (lo + hi) / 2;
	update(i, lo, mid, 2 * node + 1);
	update(i, mid + 1, hi, 2 * node + 2);

	// copypaste this
	bool b = !(T[mid] == -1 && T[mid+1] == 1) && T[mid] && T[mid+1]; // if it can extend
	stl[node] = stl[2 * node + 1];
	if (b && stl[2 * node + 1] == mid - lo + 1) stl[node] += stl[2 * node + 2];
	str[node] = str[2 * node + 2];
	if (b && str[2 * node + 2] == hi - mid) str[node] += str[2 * node + 1];
	st[node] = max(st[2 * node + 1], st[2 * node + 2]);
	if (b) {
		st[node] = max(st[node], str[2 * node + 1] + stl[2 * node + 2]);
	}
}

void chk(int i) {
	if (ty(P[i]) != T[i]) {
		T[i] = ty(P[i]);
		update(i);
	}
}

void debug() {
	for (int i = 0; i < 2 * N; i++) {
		error(i, st[i], stl[i], str[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i) {
			P[i-1] = A[i] - A[i-1];
			T[i-1] = ty(P[i-1]);
		}
	}

	cin >> M;
	if (N == 1) {
		for (int i = 0; i < N; i++) {
			cout << 1 << ' ';
		}
		cout << endl;
		return 0;
	}
	init();
	for (int i = 0; i < M; i++) {
		// debug();
		int l, r;
		LL d;
		cin >> l >> r >> d; l--; r--;
		if (l) {
			P[l-1] += d;
			chk(l-1);
		}
		if (r < N - 1) {
			P[r] -= d;
			chk(r);
		}
		cout << st[0] + 1 << '\n';
	}
	cout.flush();
	return 0;
}