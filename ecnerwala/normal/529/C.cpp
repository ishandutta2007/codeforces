#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int INF = 1e9;

const int MAXN = 2e5;
const int MAXM = 2e5;

int N, M;

const int MAXK = 3e5;
int K;
pii R[MAXK];

const int MAXQ = 3e5;
int Q;
pii X[MAXQ];
pii Y[MAXQ];

bool ans[MAXQ];

const int L = 19;
const int S = 1 << L;

int seg[S * 2];

void reset() {
	memset(seg, -1, sizeof(seg));
}

void update(int a, int v) {
	int i = a + S;
	seg[i] = v;
	for(i /= 2; i; i /= 2) {
		seg[i] = min(seg[2 * i], seg[2 * i + 1]);
	}
}

//inclusive
int query(int a, int b) {
	int res = INF;
	for(int l = a + S, r = b + S; l <= r; l /= 2, r /= 2) {
		if(l % 2 == 1) {
			res = min(res, seg[l]);
			l++;
		}
		if(r % 2 == 0) {
			res = min(res, seg[r]);
			r--;
		}
	}
	return res;
}

pii events[MAXQ];
void solve() {
	reset();
	sort(R, R + K);
	for(int i = 0; i < Q; i++) {
		events[i] = pii(X[i].B, i);
	}

	sort(events, events + Q);

	int k = 0, e = 0;
	for(int x = 0; x < N; x++) {
		while(k < K && R[k].A == x) {
			update(R[k].B, x);
			k++;
		}

		while(e < Q && events[e].A == x) {
			int q = events[e].B;
			if(X[q].A <= query(Y[q].A, Y[q].B)) {
				ans[q] = true;
			}
			e++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K >> Q;
	for(int i = 0; i < K; i++) {
		cin >> R[i].A >> R[i].B;
		R[i].A --, R[i].B --;
	}
	for(int i = 0; i < Q; i++) {
		cin >> X[i].A >> Y[i].A >> X[i].B >> Y[i].B;
		X[i].A --, Y[i].A --, X[i].B --, Y[i].B --;
	}

	memset(ans, 0, sizeof(ans));
	solve();
	swap(N, M);
	for(int i = 0; i < K; i++) {
		swap(R[i].A, R[i].B);
	}
	for(int i = 0; i < Q; i++) {
		swap(X[i].A, Y[i].A);
		swap(X[i].B, Y[i].B);
	}

	solve();

	for(int i = 0; i < Q; i++) {
		cout << (ans[i] ? "YES" : "NO") << '\n';
	}
	return 0;
}