#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
#define MAXSEG (1<<20)
int T;
int N;
int A[MAXN], B[MAXN];
vector<int> pos[MAXN]; int ip[MAXN];
int st[MAXSEG];

void update(int i, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (i < lo || i > hi) return;
	if (lo == hi) { st[node] = x; return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

int query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	if (hi < s || lo > e) return MAXN;
	if (s <= lo && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1),
		query(s, e, mid + 1, hi, 2 * node + 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			update(i, A[i]);
			pos[A[i]].push_back(i);
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}

		bool ok = true;
		for (int i = 0; i < N; i++) {
			if (ip[B[i]] == pos[B[i]].size()) {
				ok = false;
				break;
			}

			int k = pos[B[i]][ip[B[i]]++];
			if (query(0, k) < B[i]) {
				ok = false;
				break;
			}
			update(k, MAXN);
		}

		cout << (ok ? "YES\n" : "NO\n");


		for (int x = 1; x <= N; x++) {
			pos[x].clear();
			ip[x] = 0;
		}
	}

	cout.flush();
	return 0;
}