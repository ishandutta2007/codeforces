#include<bits/stdc++.h>
using namespace std;

const int MAXQ = 3e5;
int V[2][MAXQ];

int N;
int Q;
int C[MAXQ][2];
bool D[MAXQ]; // direction of the fixed coordinate

const int S = 1 << 18;

int seg[2][S * 2];

// [l, r]
void insert(int t, int l, int r, int v) {
	//cerr << "insert " << t << ' ' << l << ' ' << r << ' ' << v << '\n';
	for(l += S, r += S; l <= r; l /= 2, r /= 2) {
		if(l % 2 == 1) seg[t][l] = max(seg[t][l], v), l++;
		if(r % 2 == 0) seg[t][r] = max(seg[t][r], v), r--;
	}
}

int query(int t, int a) {
	//cerr << "query " << t << ' ' << a << ' ';
	int res = 0;
	for(a += S; a; a /= 2) {
		res = max(res, seg[t][a]);
	}
	//cerr << res << '\n';
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> Q;
	for(int i = 0; i < Q; i++) {
		cin >> C[i][0] >> C[i][1];
		V[0][i] = C[i][0];
		V[1][i] = C[i][1];
		char c; cin >> c;
		D[i] = c == 'L';
	}
	sort(V[0], V[0] + Q);
	sort(V[1], V[1] + Q);

	for(int i = 0; i < Q; i++) {
		int c = lower_bound(V[D[i]], V[D[i]] + Q, C[i][D[i]]) - V[D[i]] + 1;
		int v = query(D[i], c);
		//cerr << v << ' ' << C[i][!D[i]] << '\n';
		cout << C[i][!D[i]] - v << '\n';
		//assert(!v || binary_search(V[!D[i]], V[!D[i]] + Q, v));
		int l = v ? lower_bound(V[!D[i]], V[!D[i]] + Q, v) - V[!D[i]] + 1 : 0;
		int r = lower_bound(V[!D[i]], V[!D[i]] + Q, C[i][!D[i]]) - V[!D[i]] + 1;
		assert(l <= r);
		insert(!D[i], l, r, C[i][D[i]]);
		insert(D[i], c, c, C[i][!D[i]]);
	}
	return 0;
}