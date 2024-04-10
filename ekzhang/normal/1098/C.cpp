#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
LL S;
int B;
int par[MAXN];
int t = 0;
int layer[MAXN];
int lst[MAXN];

LL go(int num, int N, int b) {
	LL ans = 0;
	LL total = 0;
	LL cur = num;
	for (int d = 1;; d++) {
		LL amt = min(N - total, cur);
		total += amt;
		ans += d * amt;
		if (total == N)
			break;
		cur *= b;
	}
	return ans;
}

int solve(int N, LL S) {
	int lo = 1;
	int hi = N - 1;
	while (lo != hi) {
		int mid = (lo + hi) / 2;
		if (go(1, N, mid) <= S)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int solve2(int N, LL S) {
	int lo = 1;
	int hi = N;
	while (lo != hi) {
		int mid = (lo + hi) / 2;
		if (go(mid, N, B) <= S)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

void layers(int k, int num, int N, LL S) {
	layer[k] = num;
	// cout << k << ' ' << num << endl;
	S -= N;
	N -= num;
	if (!N)
		return;
	// how small can i make the next layer
	// so that minimal sum is still <= S?
	int nxt = solve2(N, S);
	layers(k + 1, nxt, N, S);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> S;
	if (S < 2*N-1 || S > (LL) N*(N+1)/2) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	B = solve(N, S);

	if (B == 1) {
		for (int i = 1; i < N; i++)
			cout << i << ' ';
		cout << endl;
		return 0;
	}

	// now construct it
	layers(0, 1, N, S);

	for (int k = 1; k < N; k++) {
		lst[k] = lst[k - 1] + layer[k - 1];
		for (int i = lst[k]; i < lst[k] + layer[k]; i++) {
			par[i] = (i - lst[k]) / B + lst[k - 1];
		}
	}

	for (int i = 1; i < N; i++) {
		cout << par[i] + 1 << ' ';
	}
	cout << endl;
	return 0;
}