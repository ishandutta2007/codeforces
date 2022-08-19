#include<iostream>
#include<complex>
#include<algorithm>
#include<cassert>

using namespace std;

typedef long long ll;

const int MAXN = 400;

const ll MOD = 1e9 + 7;

int N;

ll X[MAXN], Y[MAXN];

#define PT(i) X[i], Y[i]

ll cross(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}

ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
}

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return area(x1, y1, x2, y2, x3, y3) > 0;
}
ll cw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return area(x1, y1, x2, y2, x3, y3) < 0;
}
ll col(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return area(x1, y1, x2, y2, x3, y3) == 0;
}

ll sign(ll a) { return a ? ((a > 0) ? 1 : -1) : 0; }

bool between(ll l, ll r, ll x) { return sign(x - l) != sign(x - r); }

bool inOrder(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1 != x3) ? between(x1, x3, x2) : between(y1, y3, y2);
}

bool inter(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if(col(x1, y1, x2, y2, x3, y3) || col(x1, y1, x2, y2, x4, y4)) return false;
	if(col(x3, y3, x4, y4, x1, y1) || col(x3, y3, x4, y4, x2, y2)) return false;
	return sign(area(x1, y1, x2, y2, x3, y3)) != sign(area(x1, y1, x2, y2, x4, y4)) &&
		sign(area(x3, y3, x4, y4, x1, y1)) != sign(area(x3, y3, x4, y4, x2, y2));
}

bool isGood[MAXN][MAXN];

ll dp[MAXN][MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	ll a = 0;
	for(int i = 0; i < N; i++) {
		a += cross(PT(i), PT((i + 1) % N));
	}
	if(a < 0) reverse(X, X + N), reverse(Y, Y + N);
	for(int i = 0; i < N; i++) {
		for(int j = (i + 1) % N; j != i; j++, j %= N) {
			isGood[i][j] = true;
			for(int k = (i + 1) % N; k != i; k++, k %= N) {
				if(k == i || k == j) continue;
				bool blocked = col(PT(i), PT(k), PT(j)) && inOrder(PT(i), PT(k), PT(j));
				if(blocked) {
					isGood[i][j] = false;
					break;
				}
			}
			if(!isGood[i][j]) continue;
			int nxt = (i + 1) % N;
			int prv = (i - 1 + N) % N;
			if(cw(PT(prv), PT(i), PT(nxt))) {
				if(cw(PT(prv), PT(i), PT(j)) && cw(PT(j), PT(i), PT(nxt))) {
					isGood[i][j] = false;
				} else {
				}
			} else {
				if(!cw(PT(prv), PT(i), PT(j)) && !cw(PT(j), PT(i), PT(nxt))) {
				} else {
					isGood[i][j] = false;
				}
			}
			if(!isGood[i][j]) continue;
			for(int k = (i + 1) % N; (k + 1) % N != i; k++, k %= N) {
				if(inter(PT(i), PT(j), PT(k), PT((k + 1) % N))) isGood[i][j] = false;
			}
			if(!isGood[i][j]) continue;
		}
		/*
		for(int k = 0; k < N; k++) isGood[i][k] = true;
		int j = (i + 1) % N;

		for(int k = (i + 2) % N; k != i; k++, k %= N) {
			if(ccw(PT(i), PT(j), PT(k))) {
				j = k;
			} else {
				isGood[i][k] = false;
				//cerr << i << ' ' << k << '\n';
			}
		}

		j = (i - 1 + N) % N;
		for(int k = (i - 2 + N) % N; k != i; k--, k += N, k %= N) {
			if(cw(PT(i), PT(j), PT(k))) {
				j = k;
				cerr << i << ' ' << j << '\n';
			} else {
				isGood[i][k] = false;
				//cerr << i << ' ' << k << '\n';
			}
		}
		*/

		//assert(isGood[i][(i + 1) % N]);
	}

	//for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) assert(isGood[i][j] == isGood[j][i]);

	for(int i = 0; i < N; i++) dp[i][(i + 1) % N] = 1;
	for(int d = 2; d < N; d++) {
		for(int i = 0; i < N; i++) {
			int j = (i + d) % N;
			if(isGood[i][j]) {
				dp[i][j] = 0;
				for(int k = (i + 1) % N; k != j; k++, k %= N) {
					dp[i][j] += dp[i][k] * dp[k][j];
					dp[i][j] %= MOD;
				}
			} else {
				dp[i][j] = 0;
			}
			//cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	cout << dp[0][N - 1] << '\n';
	return 0;
}