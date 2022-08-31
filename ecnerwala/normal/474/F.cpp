#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return a ? gcd( b % a, a ) : b; }

const int L = 17;
const int S = 1 << L;
const int MAXS = S * 2 + 20;

const int MAXN = 1.2e5;
int N;
int A[MAXN];

int seg[MAXS];
int getgcd(int a, int b) {
	int res = 0;
	for(a += S, b += S; a < b; a /= 2, b /= 2) {
		if(a % 2) res = gcd(res, seg[a++]);
		if(b % 2) res = gcd(res, seg[--b]);
	}
	return res;
}

typedef pair<int, int> pii;
pii vals[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		seg[i + S] = A[i];
		vals[i] = pii(A[i], i);
	}
	for(int i = S - 1; i > 0; i--) {
		seg[i] = gcd(seg[2 * i], seg[2 * i + 1]);
	}
	sort(vals, vals + N);

	int T; cin >> T;
	for(int i = 0; i < T; i++) {
		int l, r; cin >> l >> r;
		l--;
		int g = getgcd(l, r);
		int res = lower_bound(vals, vals + N, pii(g, r)) - lower_bound(vals, vals + N, pii(g, l));
		cout << r - l - res << '\n';
	}
	return 0;
}