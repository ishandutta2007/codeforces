#include<bits/stdc++.h>
#include<inttypes.h>
using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pll;

ll N, M;
ll A, B; // bottom of the rectangle
ll X, Y; // current less/less bound

void query(ll x, ll y) {
	assert(0 < X && X <= N);
	assert(0 < Y && Y <= M);
	assert(0 <= x && 0 <= y);
	assert(x <= X && y <= Y);
	assert(x < N && y < M);
	printf("%" PRId64 " %" PRId64 "\n", x+A, y+B);
	fflush(stdout);
	int q; scanf("%d", &q);
	if (q == 0) {
		exit(0);
	} else if (q == 1) {
		// lower bound on x
		A += x+1;
		X -= x+1;
		N -= x+1;
	} else if (q == 2) {
		B += y+1;
		Y -= y+1;
		M -= y+1;
	} else if (q == 3) {
		assert(x <= X && y <= Y);
		X = x;
		Y = y;
	} else assert(false);
	if (X <= 0) {
		// we can't be < X
		// so we must be < Y
		M = Y;
		X = N;
	}
	if (Y <= 0) {
		N = X;
		Y = M;
	}
	assert(0 < X && X <= N);
	assert(0 < Y && Y <= M);
}

int main() {
	scanf("%" SCNd64, &N);
	M = N;

	A = B = 1;
	X = N, Y = M;

	while (true) {
		assert(N >= 1 && M >= 1);
		assert(0 < X && X <= N);
		assert(0 < Y && Y <= M);
		if (X == N || Y == M) query(X / 2, Y / 2);
               else if (X > Y) query(X / 2, Y);
               else query(X, Y / 2);
	}

	return 0;
}